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
		cout << "Invalid arguments count \n";
		return nullopt;
	}
	Args args;
	args.inputNumber = argv[1];
	return args;
}

string ToBinaryString(unsigned int n) {
	string buffer;
	for (int i = 0; i < 8; ++i)
	{	
		if (n > 0) {
			buffer += char('0' + n % 2);
			n = n / 2;
		}
		else
		{
			buffer += char('0');
		}
	}

	return buffer;
}

int ReverseBinaryString(string n) {
	int reverseNumber = 0;
	string num;

	for (int i = 0; i <= 7; ++i)
	{
		num = n[i];
		reverseNumber = stoi(num) * pow(2, 7-i) + reverseNumber;
	}
	return reverseNumber;
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

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (CheckCorrectInputNumber(args -> inputNumber)) 
	{
		cout << ReverseBinaryString(ToBinaryString(stoi(args -> inputNumber)));
	}
}


