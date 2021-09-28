#include <limits>
#include "tests.hpp"


/*
** ft::lexicographical_compare
*/
bool mycomp (char c1, char c2)
{
	return std::tolower(c1) < std::tolower(c2);
}

void lexicographical_compare(ft::Tester &tester)
{
	tester.printName("ft::lexicographical_compare");
	std::string s1("Apple");
	std::string s2("apartment");

    tester.compare(ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()), true);
    tester.compare(ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), mycomp), true);
	std::cout << std::endl;
}

/*
** ft::equal
*/
void test_equal(ft::Tester &tester)
{
	tester.printName("ft::equal");
	std::string s1("Test1");
	std::string s2("Test1");
	std::string s3("Test3");
	std::string s4("");
	std::string s5("");

    tester.compare(ft::equal(s1.begin(), s1.end(), s2.begin()), true);
	tester.compare(ft::equal(s1.begin(), s1.end(), s3.begin()), false);
	tester.compare(ft::equal(s1.begin(), s1.end(), s4.begin()), false);
	tester.compare(ft::equal(s4.begin(), s4.end(), s5.begin()), true);
	std::cout << std::endl;
}

/*
** is_integral is CPP11. Can't compare with std::.
*/

struct A {};

void test_isintegral(ft::Tester &tester)
{
	tester.printName("ft::is_integral");
	tester.compare(ft::is_integral<A>::value, false);
    tester.compare(ft::is_integral<float>::value, false);
    tester.compare(ft::is_integral<int>::value, true);
    tester.compare(ft::is_integral<const int>::value, true);
    tester.compare(ft::is_integral<bool>::value, true);
    tester.compare(ft::is_integral<int*>::value, false);
	std::cout << std::endl;
}

/*
** enable_if is CPP11. Can't compare with std::.
*/

template <typename Enableif>
bool test_enableif_helper (void) {return true;}

template <>
bool test_enableif_helper<ft::enable_if<false, bool> > (void) {return false;}

void test_enableif(ft::Tester &tester)
{
    tester.printName("ft::enable_if");
	tester.compare(
		test_enableif_helper<ft::enable_if<std::numeric_limits<int*>::is_integer, bool> >(), false
		);
	tester.compare(
		test_enableif_helper<ft::enable_if<std::numeric_limits<int>::is_integer, bool> >(), true
		);
	std::cout << std::endl;
}

/*
** iterator_traits
*/

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
