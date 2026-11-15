#include <string>
#include <fstream>
#include <iostream>

int	ft_replace(std::ifstream &inputFile, const std::string &file_name,
				const std::string &s1, const std::string &s2)
{
	size_t			pos = 0;
	std::string		line;
	std::ofstream	outputFile;

	outputFile.open((std::string(file_name) + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << "Error: Unable to create or write to file '"
		<< file_name << ".replace'" << std::endl;
		return (1);
	}
	while (std::getline(inputFile, line))
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}
		outputFile << line << '\n';
	}
	inputFile.close();
	outputFile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	std::string		first_line;
	std::ifstream	inputFile;

	if (argc != 4)
	{
		std::cerr << "Error: Wrong format !" << std::endl
		<< "Format require: ./replace <file> <s1> <s2>" << std::endl;
		return (1);
	}
	if (std::string(argv[2]).empty())
	{
		std::cerr << "Error: s1 cannot be an empty string." << std::endl;
		return (1);
	}
	inputFile.open(argv[1]);
	if (!std::getline(inputFile, first_line))
	{
		std::cerr << "Error: " << argv[1]
		<< " is not a readable text file (might be a directory)."
		<< std::endl;
		return (1);
	}
	inputFile.close();
	inputFile.open(argv[1]);
	if (!inputFile)
	{
		std::cerr << "Error: " << argv[1]
		<< ": No such file or directory" << std::endl;
		return (1);
	}
	return (ft_replace(inputFile, argv[1], argv[2], argv[3]));
}
