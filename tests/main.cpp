#include <utility>
#include <iostream>

#include "tests.hpp"


int main (int argc, char **argv)
{
	ft::Tester tester;
	if (argc == 1)
	{
		if (ORIGINAL_STD == 1)
		{
			std::cout << "ORIGINAL_STD" << std::endl;
			ft::Tester::kind = KIND_STD;
		}
		else
		{
			std::cout << "FT" << std::endl;
			ft::Tester::kind = KIND_FT;
		}
	}
	else
		ft::Tester::kind = KIND_COMPARE;
	

	test_utilities();
	test_vector();
	test_map();

	(void)argv;
	return (0);
}
