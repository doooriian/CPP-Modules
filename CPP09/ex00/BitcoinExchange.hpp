#pragma once
#include <map>
#include <string>

class	BitcoinExchange
{
	public:

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange(void);

		void	loadDataBase(void);
		void	processInput(const std::string &filename) const;

		private:

		std::map<std::string, double>	_btcRates;
		bool							processOneLine(const std::string &line) const;
};
