#include <iostream>
//#include <stdio.h>      /* printf, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "rnd.hpp"

int main()
{
    std::srand (std::time(0));
    std::cout << rnd() << std::endl;
}
