#include <utility>
#include <iostream>

#include "tests.hpp"


int main2 (int argc, char **argv)
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
	

	tester.printTitle("Iterators");
	test_reverseiterator();
	test_utilities();
	test_vector();

	(void)argv;
	return (0);
}

int main(void)
{
	ft::map<char, int> m;
	ft::pair<char, int> p('a', 100);
	
	ft::map<char, int>::node_pointer n = m._create_node(p);
	m._delete_node(n);
	return (0);
}
