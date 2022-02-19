#include <iostream>
#include <fstream>
#include <optional>
#include <string>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count \n";
		std::cout << "Usage: CopyFile.exe <input file name> <output file name> \n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

void CopyStreams(std::ifstream& input, std::ofstream& output)
{
	char ch;
	while (input.get(ch))
	{
		output.put(ch);
	}
}

int main(int argc, char* argv[])
{

	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		return 1;
	}

	std::ifstream input;
	input.open(args->inputFileName);
	if (!input.is_open())
	{
		std::cout << "Fail to open '" << args->inputFileName << "' for reading";
		return 1;
	}

	std::ofstream output;
	output.open(args->outputFileName);
	if (!output.is_open())
	{
		std::cout << "Fail to open '" << args->outputFileName << "' for writing";
		return 1;
	}

	CopyStreams(input, output);

	if (input.bad())
	{
		std::cout << "Failed to read data from input file \n";
		return 1;
	}


	if (!output.flush())
	{
		std::cout << "Eror to write data output file \n";
		return 1;
	};

	return 0;
}

