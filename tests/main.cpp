#include "./includes/utilities.hpp"

#include <utility>
#include <iostream>

#include "tests.hpp"


int main (int argc, char **argv)
{
	ft::Tester tester;
	if (argc > 1)
	{
		ft::Tester::colorized = false;
	}
	else
	{
		tester.printTitle("Iterators");
		test_reverseiterator(tester);

//		tester.startClock();
//		tester.printClock();
		test_utilities(tester);
	}
	(void)argv;
	return (0);
}
