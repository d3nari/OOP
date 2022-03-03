#include <iostream>
#include <string>
#include <optional>
using namespace std;

typedef struct Args
{
	string inputNumber; //number
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		return nullopt;
	}
	Args args;
	args.inputNumber = argv[1];
	return args;
}

int ReverseInt(uint8_t n)
{
	int x = n; 
	uint8_t r = 0;
	for (int i = 7, k = 0; i >= 0; --i, k++)
	{
		r |= ((x >> i) & 1) << k;
	}
	return 1;
}

bool InputNumberCorrectWas(string n) {
	if (n == "")
	{
		cout << "Empty value";
		return false;
	}

	for (int i = 0; i < n.size(); i++)
	{
		if (!isdigit(n[i]))
		{
			cout << "Input value is not digit";
			return false;
		}
	}
	int x = stoi(n);//выбрасывает исключение, когда не число -> проверить
	
	if ((x > 255) || (x < 0))
	{
		cout << "Incorrect number";
		return false;
	}
	return true;
}

bool ArgsRightAmount(int argc) {
	if (!argc)
	{
		cout << "Invalid arguments count \n";
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);//проверить optional на пустоту
	if (!ArgsRightAmount) //()
	{
		return 1;
	}
	if (!InputNumberCorrectWas(args->inputNumber))
	{
		return 1;
	}
	ReverseInt(stoi(args->inputNumber));
	return 0;
}


