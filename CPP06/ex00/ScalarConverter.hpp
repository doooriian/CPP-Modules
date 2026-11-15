#pragma once
#include <string>

class	ScalarConverter
{
	public:

		enum	literalType
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO,
			INVALID
		};
		struct	scalarOutput
		{
			std::string charStr;
			std::string intStr;
			std::string floatStr;
			std::string doubleStr;
		};
		static void	convert(const std::string &literal);

	private:

		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter(void);

		// parsing part
		static literalType	findType(const std::string &literal);
		static bool			isInt(const std::string &literal);
		static bool			isFloat(const std::string &literal);
		static bool			isDouble(const std::string &literal);
		// convert part
		static void			printPseudo(const std::string &literal);
		static void			convertFromChar(char c);
		static void			convertFromInt(int nb);
		static void			convertFromFloat(float nb);
		static void			convertFromDouble(double nb);
		// printing part
		static void			printOutput(const scalarOutput &out);
};
