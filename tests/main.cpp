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
		tester.startClock();
		tester.printTitle("Utilities");
		test_pair(tester);
		test_makepair(tester);
		tester.printClock();
		test_reverseiterator(tester);

		ft::vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
			std::cout << v.capacity() << std::endl;
		}

	}
	(void)argv;
	return (0);
}
