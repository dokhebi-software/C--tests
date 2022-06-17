#include <iostream>
#include <cstdlib>
#include <ctime>
#include <argp.h>
#include <cstdbool>
#include "rnd.hpp"
#include "failtest.hpp"

/* ANSI colors */
#define BLUE  "\033[0;34m"
#define RED   "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

/* argp definitions */
const char *argp_program_version = "Test6 v1";
const char *argp_program_bug_address = "<dokhebi@gmail.com>";
static char doc[] = "Test of failtest routine with command line arguments.";
static char args_doc[] = "[FILENAME]...";
static struct argp_option options[] = {
	{ "count", 'c', "COUNT", 0, "Number of times to call failtest()" },
	{ "failcnd", 'f', "COND", 0, "Failure condition" },
	{ 0 }
};

struct arguments
{
	int count;
	int failcnd;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = static_cast<struct arguments*>(state->input);
	switch (key)
	{
		case 'c': arguments->count = arg ? atoi(arg) : DEFCOUNT; break;
		case 'f': arguments->failcnd = arg ? atoi(arg) : DEFFAIL; break;
		case ARGP_KEY_ARG: return 0;
		default: return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char *argv[])
{
	struct arguments arguments;

	arguments.count = DEFCOUNT;
	arguments.failcnd = DEFFAIL;

	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	/* int x = 10; */
	/* int count = DEFCOUNT; */

	/* Seed the random number generator. */
    std::srand(std::time(0));

	/* Start the whole thing off... */
    std::cout << BLUE << "GO" << RESET;

	/* Main loop... */
	for ( int lcv = 1; lcv <= arguments.count; lcv++ )
	{
		if (failtest(arguments.failcnd))
            std::cout << " " << GREEN << "SUCCESS" << RESET;
		else
            std::cout << " " << RED << "FAIL" << RESET;
	}

	/* Final message. */
    std::cout << " " << BLUE << "DONE!" << RESET << std::endl;

	return 0;
}
