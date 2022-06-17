#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rnd.hpp"
#include "failtest.hpp"

#define BLUE  "\033[0;34m"
#define RED   "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

int main()
{
	int x = 10;
	int count = DEFCOUNT;

	// Seed the random number generator.
    std::srand(std::time(0));

	// Start the whole thing off...
    std::cout << BLUE << "GO" << RESET;

	// Main loop...
	for ( int lcv = 1; lcv <= count; lcv++ )
	{
		if (failtest(x))
            std::cout << " " << GREEN << "SUCCESS" << RESET;
		else
            std::cout << " " << RED << "FAIL" << RESET;
	}

	// Final message.
    std::cout << " " << BLUE << "DONE!" << RESET << std::endl;

	return 0;
}
