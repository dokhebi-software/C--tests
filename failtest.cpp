#include <cstdlib>
#include <math.h>
#include "rnd.hpp"

int failtest(int d)
{
int x = std::abs(d);

	switch(x)
	{
		case 0:
		case 1: return(1);
		default : if (((int)trunc(rnd() * x) + 1) == x)
				return(0);
			  else
				return(1);
	}
}
