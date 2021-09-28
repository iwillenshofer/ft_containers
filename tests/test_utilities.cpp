#include "tests.hpp"

template <typename Iterator, typename T >
typename T::value_type test_iteratortraits_helper(Iterator first, Iterator last)
{
    typename T::difference_type n = last - first;
    typename T::difference_type i = 0;
    typename T::value_type val = typename T::value_type();
    while (i < n)
    {
        val += *first++;
        i++;
    }
    return (val);
}

void test_iteratortraits(ft::Tester &tester)
{
    tester.printName("ft::iterator_traits");
    int i[10];
    for (int j = 0; j < 10; j++)
        i[j] = j;
    char c[12];
    for (int j = 0; j < 12; j++)
        c[j] = j;
    tester.compare(test_iteratortraits_helper<int*, ft::iterator_traits<int*> >(i, i + 10), test_iteratortraits_helper<int*, std::iterator_traits<int*> >(i, i + 10));
    tester.compare(test_iteratortraits_helper<char*, ft::iterator_traits<char*> >(c, c + 12), test_iteratortraits_helper<char*, std::iterator_traits<char*> >(c, c + 12));

}

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
