#include "BitcoinExchange.hpp"
#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
: _btcRates(other._btcRates)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_btcRates = other._btcRates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

static bool	isLeapYear(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return (true);
	return (false);
}

static int	findMaxDay(int year, int month)
{
	static const int	maxDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if (month == 2 && isLeapYear(year))
		return (29);
	return (maxDays[month - 1]);
}

static bool	isValidDate(const std::string &date)
{
	int	y;
	int	m;
	int	d;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; ++i)
	{
		if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	y = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
	m = (date[5] - '0') * 10 + (date[6] - '0');
	d = (date[8] - '0') * 10 + (date[9] - '0');

	if (m < 1 || m > 12)
		return (false);
	if (d < 1 || d > findMaxDay(y, m))
		return (false);
	return (true);
}

static bool	isValidRate(const std::string &rate, double &rate_value)
{
	char	*end;

	end = 0;
	errno = 0;
	rate_value = strtod(rate.c_str(), &end);

	if (end == rate.c_str() || *end != '\0' || errno == ERANGE || rate_value < 0)
		return (false);
	return (true);
}

void	BitcoinExchange::loadDataBase()
{
	std::string		line;
	std::ifstream	file("data.csv");

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty database.");
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: invalid header in database. Expected 'date,exchange_rate'");
	size_t		comma_pos;
	double		rate_value;
	std::string	rate_str;
	std::string	date_str;
	while (std::getline(file, line))
	{
		comma_pos = line.find(',');
		if (comma_pos == std::string::npos)
			throw std::runtime_error(std::string("Error: invalid line => ") + line);
		date_str = line.substr(0, comma_pos);
		rate_str = line.substr(comma_pos + 1);
		if (!isValidDate(date_str))
			throw std::runtime_error(std::string("Error: invalid date => ") + date_str);
		if (!isValidRate(rate_str, rate_value))
			throw std::runtime_error(std::string("Error: invalid rate => ") + rate_str);
		this->_btcRates[date_str] = rate_value;
	}
	if (_btcRates.empty())
		throw std::runtime_error("Error: database has no data.");
}

enum ValueStatus { VAL_OK, VAL_BAD_FORMAT, VAL_NEGATIVE, VAL_TOO_LARGE };

static ValueStatus	isValidValue(const std::string &value_str, double &value)
{
	char	*end;

	end = 0;
	errno = 0;
	value = strtod(value_str.c_str(), &end);

	if (end == value_str.c_str() || *end != '\0' || errno == ERANGE)
		return (VAL_BAD_FORMAT);
	if (value < 0)
		return (VAL_NEGATIVE);
	if (value > 1000)
		return (VAL_TOO_LARGE);
	return (VAL_OK);

}

static std::string	ft_trim(const std::string &s)
{
	size_t		i;
	size_t		j;
	std::string	trimed_s;

	i = 0;
	while (i < s.length() && std::isspace(static_cast<unsigned char>(s[i])))
		++i;
	if (i == s.length())
		return ("");
	j = s.length();
	while (j > i && std::isspace(static_cast<unsigned char>(s[j - 1])))
		--j;
	trimed_s = s.substr(i, j - i);
	return (trimed_s);
}

bool	BitcoinExchange::processOneLine(const std::string &line) const
{
	size_t		pipe_pos;
	double		value;
	std::string	date_str;
	std::string	value_str;

	if (line.empty())
		return (false);
	pipe_pos = line.find('|');
	if (pipe_pos == std::string::npos)
	{
		std::cout << "Error: bad input. Expected '|' between date and value => " << line << std::endl;
		return (false);
	}
	date_str = ft_trim(line.substr(0, pipe_pos));
	value_str = ft_trim(line.substr(pipe_pos + 1));
	if (!isValidDate(date_str))
	{
		std::cout << "Error: invalid date => " << date_str << std::endl;
		return (false);
	}
	ValueStatus	vs = isValidValue(value_str, value);
	switch (vs)
	{
		case VAL_BAD_FORMAT:
			std::cout << "Error: invalid value => " << value_str << std::endl;
			return (false);
		case VAL_NEGATIVE:
			std::cout << "Error: not a positive number => " << value_str << std::endl;
			return (false);
		case VAL_TOO_LARGE:
			std::cout << "Error: too large number => " << value_str << std::endl;
			return (false);
		case VAL_OK:
			break;
	}
	std::map<std::string, double>::const_iterator it = this->_btcRates.lower_bound(date_str);
	if (it == this->_btcRates.end() || it->first != date_str)
	{
		if (it == this->_btcRates.begin())
		{
			std::cout << "Error: date too early for this database => " << date_str << std::endl;
			return (false);
		}
		--it;
	}
	std::cout << date_str << " => " << value_str << " = " << it->second * value << std::endl;
	return (true);
}

void	BitcoinExchange::processInput(const std::string &filename) const
{
	std::string		line;
	std::ifstream	file(filename.c_str());
	bool			hasValidLine = false;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open input.");
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty input.");
	if (ft_trim(line) != "date | value")
	{
		std::cout << "Warning: no header in input file." << std::endl;
		if (processOneLine(line))
			hasValidLine = true;
	}
	while (std::getline(file, line))
	{
		if (!processOneLine(line))
			continue;
		else
			hasValidLine = true;
	}
	if (!hasValidLine)
		std::cout << "Warning: no valid data in input." << std::endl;
}
