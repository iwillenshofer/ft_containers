#include "./includes/utilities.hpp"

#include <utility>
#include <iostream>

#include "colorize.hpp"

void test_pair(ft::Tester &tester)
{
	ft::pair<int,char> foo (10,'z');
	ft::pair<int,char> bar (90,'a');

	tester.printName("ft::pair");
	tester.compare(foo==bar, false);
	tester.compare(foo!=bar, true);
	tester.compare(foo<bar, true);
	tester.compare(foo>bar, false);
	tester.compare(foo<=bar, true);
	tester.compare(foo>=bar, false);
	tester.compare(foo.first == bar.first, false);
	tester.compare(foo.second == bar.second, false);
	foo = bar;
	tester.compare(foo==bar, true);
	tester.compare(foo!=bar, false);
	tester.compare(foo<bar, false);
	tester.compare(foo>bar, false);
	tester.compare(foo<=bar, true);
	tester.compare(foo>=bar, true);
	tester.compare(foo.first, bar.first);
	tester.compare(foo.second, bar.second);
	tester.compare(foo.first == bar.first, true);
	tester.compare(foo.second == bar.second, true);
	std::cout << std::endl;
}

void test_makepair(ft::Tester &tester)
{
	ft::pair<int,char> foo = ft::make_pair(10,'z');
	ft::pair<int,char> bar = ft::make_pair(90,'a');

	tester.printName("ft::make_pair");
	tester.compare(foo==bar, false);
	tester.compare(foo!=bar, true);
	tester.compare(foo<bar, true);
	tester.compare(foo>bar, false);
	tester.compare(foo<=bar, true);
	tester.compare(foo>=bar, false);
	tester.compare(foo.first == bar.first, false);
	tester.compare(foo.second == bar.second, false);
	foo = bar;
	tester.compare(foo==bar, true);
	tester.compare(foo!=bar, false);
	tester.compare(foo<bar, false);
	tester.compare(foo>bar, false);
	tester.compare(foo<=bar, true);
	tester.compare(foo>=bar, true);
	tester.compare(foo.first, bar.first);
	tester.compare(foo.second, bar.second);
	tester.compare(foo.first == bar.first, true);
	tester.compare(foo.second == bar.second, true);
	std::cout << std::endl;
}

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
	}
	(void)argv;
	return (0);
}