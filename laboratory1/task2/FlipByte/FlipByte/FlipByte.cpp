#include <iostream>
#include <string>
#include <optional>
using namespace std;

typedef struct Args
{
	string inputNumber;
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

int ReverseInt(unsigned int n) {
	int x = n; 
	int r = 0;
	for (int i = 7, k = 0; i >= 0; --i, k++)
	{
		r |= ((x >> i) & 1) << k;
	}
	printf("%i\n", r);
	return 1;
}

bool CheckCorrectInputNumber(string n) {
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
	int x = stoi(n);
	//Проверка на верхнюю и нижнюю границу числа
	if ((x > 255) || (x < 0))
	{
		cout << "Incorrect number";
		return false;
	}
	return true;
}

bool CheckArgs(int argc) {
	if (!argc)
	{
		cout << "Invalid arguments count \n";
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!CheckArgs)
	{
		return 1;
	}
	if (!CheckCorrectInputNumber(args->inputNumber))
	{
		return 1;
	}
	ReverseInt(stoi(args->inputNumber));
	return 0;
}


