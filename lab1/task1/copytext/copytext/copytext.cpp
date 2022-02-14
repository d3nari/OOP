#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) 
{
	if (argc != 3) 
	{
		std::cout << "Invalid arguments count \n";
		std::cout << "Usage: CopyFile.exe <input file name> <output file name> \n";
		return 1;
	}

	std::ifstream input;

	input.open(argv[1]);
	if (!input.is_open()) 
	{
		std::cout << "Fail to open '" << argv[1] << "' for reading";
		return 1;
	}

	std::ofstream output;
	output.open(argv[2]);
	if (!output.is_open()) 
	{
		std::cout << "Fail to open '" << argv[2] << "' for writing";
		return 1;
	}



	char ch;
	while (input.get(ch))
	{
		output.put(ch);
	}

    /*std::cout << argc << "\n";
	for (int i = 0; i < argc; ++i)
	{
		std::cout << argv[i] << "\n";
	}*/
    return 0;
}

