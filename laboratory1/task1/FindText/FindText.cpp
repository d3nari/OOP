#include <cassert>
#include <functional> // Необходим для std::function
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <optional>

using namespace std;

typedef struct Args
{
	string inputFileName;
	string searchStringName;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	Args args;
	args.inputFileName = argv[1];
	args.searchStringName = argv[2];
	return args;
}

using FindStringCallback = function<void(int lineIndex, const string& line, size_t foundPos)>;
using NoneStringCallback = function<void(bool found)>;

void FindString(
	istream& haystack,
	const string& needle,
	const FindStringCallback& foundCallback = FindStringCallback(),
	const NoneStringCallback& dontFoundCallback = NoneStringCallback())
{
	string line;
	bool found = false;
	for (int lineIndex = 1; getline(haystack, line); ++lineIndex)
	{
		auto pos = line.find(needle);
		if (pos != string::npos)
		{
			found = true;
			foundCallback(lineIndex, line, pos);
		}
	}
	dontFoundCallback(found);
}

bool CheckInputWord(string searchStringName)
{
	if (searchStringName == "")
	{ 
		cout << "Search word is empty";
		return 0;
	}
	return 1;
}

bool CheckInputFile(ifstream& input, string inputFileName)
{
	if (!input.is_open())
	{
		cout << "Fail to open '" << inputFileName << "' for reading";
		return 0;
	}
}

bool CheckArgs(optional<Args> args)
{
	if (!args)
	{
		return 0;
	}
}

bool CheckArgsCount(int argc)
{
	if (argc != 3)
	{
		cout << "Invalid arguments count \n";
		cout << "Usage: CopyFile.exe <input file name> <output file name> \n";
		return 0;
	}
}

bool CheckInterrupt(ifstream& input)
{
	if (input.bad())
	{
		std::cout << "Failed to read data from input file \n";
		return 0;
	}
}

void PrintFoundLineIndex(int lineIndex, const string& /*line*/, size_t /*foundPos*/)
{
	cout << lineIndex << endl;
}

void PrintDontFound(bool found)
{
	if (!found)
	{
		cout << "No string found" << endl;
	}
}

int main(int argc, char* argv[])
{

	if (!CheckArgsCount(argc))
	{
		return 1;
	}
	
	auto args = ParseArgs(argc, argv);

	if (!CheckArgs(args))
	{
		return 1;
	}
	
	std::ifstream input;
	input.open(args -> inputFileName);

	if (!CheckInputWord(args->searchStringName) || !CheckInputFile(input, args->inputFileName))
	{
		return 1;
	}

	FindString(input, args->searchStringName, PrintFoundLineIndex, PrintDontFound);


	input.clear(); // сбросили флаг окончания потока
	return 0;
}
