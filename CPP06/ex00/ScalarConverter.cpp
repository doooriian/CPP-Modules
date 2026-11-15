#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert(const std::string &literal)
{
	literalType type;

	if (!literal.empty())
		type = findType(literal);
	else
		type = INVALID;
	switch (type)
	{
		case PSEUDO:
		{
			printPseudo(literal);
			break;
		}
		case CHAR:
		{
			convertFromChar(literal[0]);
			break;
		}
		case INT:
		{
			convertFromInt(atoi(literal.c_str()));
			break;
		}
		case FLOAT:
		{
			char	*endptr = NULL;
			float	value = std::strtof(literal.c_str(), &endptr);
			convertFromFloat(value);
			break;
		}
		case DOUBLE:
		{
			char	*endptr = NULL;
			double	value = std::strtod(literal.c_str(), &endptr);
			convertFromDouble(value);
			break;
		}
		default:
		{
			scalarOutput	out;
			out.charStr = "impossible";
			out.intStr = "impossible";
			out.floatStr = "impossible";
			out.doubleStr = "impossible";
			printOutput(out);
		}
	}
}

ScalarConverter::literalType	ScalarConverter::findType(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (PSEUDO);
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (PSEUDO);
	else if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (CHAR);
	else if (isInt(literal))
		return (INT);
	else if (isFloat(literal))
		return (FLOAT);
	else if (isDouble(literal))
		return (DOUBLE);
	else
		return (INVALID);
}

bool	ScalarConverter::isInt(const std::string &literal)
{
	if (literal[0] != '+' && literal[0] != '-' && !std::isdigit(literal[0]))
		return (false);
	errno = 0;
	char	*endptr = NULL;
	long	strtol_value = strtol(literal.c_str(), &endptr, 10);
	if (errno == ERANGE)
		return (false);
	else if (strtol_value < std::numeric_limits<int>::min() || strtol_value > std::numeric_limits<int>::max())
		return (false);
	else if (*endptr != '\0')
		return (false);
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &literal)
{
	if (literal[0] != '+' && literal[0] != '-' && !std::isdigit(literal[0]))
		return (false);
	if (literal.find(".") == std::string::npos)
		return (false);
	errno = 0;
	char	*endptr = NULL;
	strtof(literal.c_str(), &endptr);
	if (errno == ERANGE)
		return (false);
	else if (*endptr != 'f')
		return (false);
	endptr++;
	if (*endptr != '\0')
		return (false);
	return (true);
}

bool	ScalarConverter::isDouble(const std::string &literal)
{
	if (literal[0] != '+' && literal[0] != '-' && !std::isdigit(literal[0]))
		return (false);
	errno = 0;
	char	*endptr = NULL;
	strtod(literal.c_str(), &endptr);
	if (errno == ERANGE)
		return (false);
	else if (*endptr != '\0')
		return (false);
	return (true);
}

void	ScalarConverter::printPseudo(const std::string &literal)
{
	scalarOutput	out;

	out.charStr = "impossible";
	out.intStr = "impossible";
	if (literal[0] == '-')
	{
		out.floatStr = "-inff";
		out.doubleStr = "-inf";
	}
	else if (literal[0] == '+')
	{
		out.floatStr = "+inff";
		out.doubleStr = "+inf";
	}
	else
	{
		out.floatStr = "nanf";
		out.doubleStr = "nan";
	}
	printOutput(out);
}

void	ScalarConverter::convertFromChar(char c)
{
	scalarOutput	out;

	// char
	if (std::isprint(static_cast<unsigned char>(c)))
		out.charStr = std::string("'") + c + "'";
	else
		out.charStr = "Non displayable";

	// int
	{
		std::ostringstream	oss;
		oss << static_cast<int>(c);
		out.intStr = oss.str();
	}

	// float
	{
		std::ostringstream	oss;
		oss << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f";
		out.floatStr = oss.str();
	}

	// double
	{
		std::ostringstream	oss;
		oss << std::fixed << std::setprecision(1) << static_cast<double>(c);
		out.doubleStr = oss.str();
	}
	printOutput(out);
}

void	ScalarConverter::convertFromInt(int nb)
{
	scalarOutput	out;

	// char
	if (nb < std::numeric_limits<char>::min() || nb > std::numeric_limits<char>::max())
		out.charStr = "impossible";
	else
	{
		char c = static_cast<char>(nb);
		if (std::isprint(static_cast<unsigned char>(c)))
			out.charStr = std::string("'") + c + "'";
		else
			out.charStr = "Non displayable";
	}

	// int
	{
		std::ostringstream	oss;
		oss << nb;
		out.intStr = oss.str();
	}

	// float
	{
		std::ostringstream	oss;
		oss << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f";
		out.floatStr = oss.str();
	}

	//double
	{
		std::ostringstream	oss;
		oss << std::fixed << std::setprecision(1) << static_cast<double>(nb);
		out.doubleStr = oss.str();
	}
	printOutput(out);
}

void	ScalarConverter::convertFromFloat(float nb)
{
	scalarOutput	out;

	// char
	if (nb < std::numeric_limits<char>::min() || nb > std::numeric_limits<char>::max())
		out.charStr = "impossible";
	else
	{
		char c = static_cast<char>(nb);
		if (std::isprint(static_cast<unsigned char>(c)))
			out.charStr = std::string("'") + c + "'";
		else
			out.charStr = "Non displayable";
	}

	// int
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		out.intStr = "impossible";
	else
	{
		std::ostringstream	oss;
		oss << static_cast<int>(nb);
		out.intStr = oss.str();
	}

	// float
	{
		std::ostringstream	oss;
		oss << std::fixed << std::setprecision(1) << nb << "f";
		out.floatStr = oss.str();
	}

	//double
	{
		std::ostringstream	oss;
		oss << std::fixed << std::setprecision(1) << static_cast<double>(nb);
		out.doubleStr = oss.str();
	}
	printOutput(out);
}

void	ScalarConverter::convertFromDouble(double nb)
{
	scalarOutput	out;

	// char
	if (nb < std::numeric_limits<char>::min() || nb > std::numeric_limits<char>::max())
		out.charStr = "impossible";
	else
	{
		char c = static_cast<char>(nb);
		if (std::isprint(static_cast<unsigned char>(c)))
			out.charStr = std::string("'") + c + "'";
		else
			out.charStr = "Non displayable";
	}

	// int
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		out.intStr = "impossible";
	else
	{
		std::ostringstream	oss;
		oss << static_cast<int>(nb);
		out.intStr = oss.str();
	}

	// float
	if (nb < -std::numeric_limits<float>::max() || nb > std::numeric_limits<float>::max())
		out.floatStr = "impossible";
	else
	{
		std::ostringstream	oss;
		oss << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f";
		out.floatStr = oss.str();
	}

	//double
	{
		std::ostringstream	oss;
		oss << std::fixed << std::setprecision(1) << nb;
		out.doubleStr = oss.str();
	}
	printOutput(out);
}

void	ScalarConverter::printOutput(const scalarOutput &out)
{
	std::cout << "char: " << out.charStr << std::endl;
	std::cout << "int: " << out.intStr << std::endl;
	std::cout << "float: " << out.floatStr << std::endl;
	std::cout << "double: " << out.doubleStr << std::endl;
}
