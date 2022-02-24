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

void FindStingInStream(
	istream& haystack,
	const string& needle,
	const FindStringCallback& callback = FindStringCallback(),
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
			// Передаем в функцию обратного вызова информацию о
			// первом найденном вхождении подстроки
			if (callback)
			{
				callback(lineIndex, line, pos);
			}
		}
	}
	dontFoundCallback(found);
}

bool CheckInputWord(string searchStringName)
{
	//Проверка на пустоту слова
	if (searchStringName == "")
	{
		cout << "Search word is empty";
		return 0;
	}
	return 1;
}

bool CheckInputFile(ifstream& input, string inputFileName)
{
	//Проверка входного файла
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

bool CheckFound()
{
	return 0;
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

	//Инициализация переменных
	auto args = ParseArgs(argc, argv);

	//Проверка полноты входных данных
	if (!CheckArgs(args))
	{
		return 1;
	}
	
	std::ifstream input;
	input.open(args -> inputFileName);

	//Отслеживание ошибок входных данных
	if (!CheckInputWord(args->searchStringName) || !CheckInputFile(input, args->inputFileName))
	{
		return 1;
	}


	
	//Главный алгоритм
	FindStingInStream(input, args->searchStringName, PrintFoundLineIndex, PrintDontFound);

	
	input.clear(); // сбросили флаг окончания потока
	return 0;
}
