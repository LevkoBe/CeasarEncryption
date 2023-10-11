#include <iostream>
#include "Encrypt.h"


int main()
{
	std::string str = "Hello, I'm encrypted text!";
	std::string encr = encrypt(str, 13);
	for (int i = 0; i < 10; i++)
	{
		std::string encrypted = encrypt(str, i);
		std::cout << encrypted << std::endl;
		std::cout << decrypt(encrypted, i) << std::endl;
		std::cout << decrypt(encrypted, i + 1) << std::endl;
		std::cout << std::endl;
	}
	return 0;
}