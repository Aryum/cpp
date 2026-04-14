#include <iostream>

void print_upper(char *input)
{
	std::string str;

	for (int i = 0; input[i] != '\0'; i++)
		str.push_back(toupper(input[i]));
	std::cout << str;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			print_upper(argv[i]);
	}
	std::cout << "\n";
	return 0;
}