#include "ScalarConverter.hpp"

static void	test(const std::string &label, const std::string &input)
{
	std::cout << "--- " << label << " ---" << std::endl;
	std::cout << "Input: \"" << input << "\"" << std::endl;
	ScalarConverter::convert(input);
	std::cout << std::endl;
}

int	main(void)
{
	//Char literals
	test("char: 'a'", "a");
	test("char: 'z'", "z");
	test("char: '.'", ".");

	test("char: space ' '", " ");

	//Non-displayable / edge chars
	test("int 31 → non-displayable char", "31");
	test("int 127 → DEL (non-displayable)", "127");

	//Ordinary integers
	test("int: 42", "42");
	test("int: -42", "-42");
	test("int: 0", "0");
	test("int: 2147483647",  "2147483647");   // INT_MAX
	test("int: -2147483648", "-2147483648");  // INT_MIN

	//Integer overflow
	test("int overflow +",   "2147483648");
	test("int overflow -",   "-2147483649");

	//Ordinary floats
	test("float: 0.0f",      "0.0f");
	test("float: 42.0f",     "42.0f");
	test("float: -4.2f",     "-4.2f");
	test("float: 0.1f",      "0.1f");
	test("float: 3.14159f",  "3.14159f");

	//Float pseudo-literals
	test("float: +inff",     "+inff");
	test("float: -inff",     "-inff");
	test("float: nanf",      "nanf");

	//Ordinary doubles
	test("double: 0.0",      "0.0");
	test("double: 42.0",     "42.0");
	test("double: -4.2",     "-4.2");

	//Double pseudo-literals 
	test("double: +inf",     "+inf");
	test("double: -inf",     "-inf");
	test("double: nan",      "nan");

	//Displayable ASCII boundary values
	test("int 32  → space (displayable)",  "32");
	test("int 65  → 'A'",                 "65");
	test("int 126 → '~'",                 "126");


	//Bad / nonsense inputs
	test("empty string",     "");
	test("random word",      "hello");
	test("mixed",            "42abc");
	test("just dot",         ".");
	test("multiple dots",    "1.2.3");
	test("only minus",       "-");
	test("only f",           "f");       // single printable char
	test("bare inf (no sign)","inf");

	return 0;
}