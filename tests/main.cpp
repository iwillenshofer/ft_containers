#include "./includes/utilities.hpp"

#include <utility>
#include <iostream>

#define LINE_LEN		90

/*
** color schemes: 
*/

#define CLR_BLACK		30
#define CLR_RED			31
#define CLR_GREEN		32
#define CLR_YELLOW		33
#define CLR_BLUE		34
#define CLR_MAGENTA		35
#define CLR_CYAN		36
#define CLR_WHITE		37

/*
** attributes light and lightbg can be added using | bitwise operator.
** ex: CLR_BOLD | CLR_LIGHTBG | CLR_LIGHTFG
*/

#define CLR_DEFAULT		0
#define CLR_BOLD		1
#define CLR_DIM			2
#define CLR_ITALICS		3
#define CLR_UNDERLINED	4
#define CLR_BLINK		5
#define CLR_REVERSE		7
#define CLR_HIDDEN		8
#define CLR_LIGHTFG		16
#define CLR_LIGHTBG		32

std::string color(std::string s, int color, int attributes = CLR_DEFAULT, int background = CLR_DEFAULT)
{
	std::string str("\033[");

	if (color && (attributes & CLR_LIGHTFG))
		color += 60;
	if (background)
		background += 10;
	if (background && (attributes & CLR_LIGHTBG))
		background += 60;
	attributes = attributes & 15;

	str += std::to_string(attributes);
	str +=  ";" + std::to_string(color);
	if (background)
		str += ";" + std::to_string(background);
	str += "m";
	str += s;
	str += "\033[0m";
	return(str);
}

template <typename T>
void test(T t1, T t2)
{
	if (t1 == t2)
		std::cout << color("[OK] ", CLR_GREEN, CLR_BOLD);
	else
		std::cout << color("[X] ", CLR_RED, CLR_BOLD) ;
}

std::string &line_fill(std::string &s)
{
	if (s.length() % 2)
		s += " ";
	while (s.length() < LINE_LEN)
		s = " " + s + " ";
	return (s);
}

void print_name(std::string s)
{
	std::cout << color(line_fill(s) , CLR_WHITE, CLR_BOLD, CLR_BLUE) << std::endl;
}

void print_title(std::string s)
{
	std::string empty_str("");

	s = "* * * " + s + " * * *";
	std::cout << std::endl;
	std::cout << color(line_fill(empty_str) , CLR_BLUE, CLR_BOLD  | CLR_LIGHTBG, CLR_WHITE) << std::endl;
	std::cout << color(line_fill(s) , CLR_BLUE,  CLR_LIGHTBG, CLR_WHITE) << std::endl;
	std::cout << color(line_fill(empty_str) , CLR_BLUE, CLR_BOLD | CLR_LIGHTBG , CLR_WHITE) << std::endl;
}

void test_pair()
{
	ft::pair<int,char> foo (10,'z');
	ft::pair<int,char> bar (90,'a');

	print_name("ft::pair");
	test(foo==bar, false);
	test(foo!=bar, true);
	test(foo<bar, true);
	test(foo>bar, false);
	test(foo<=bar, true);
	test(foo>=bar, false);
	test(foo.first == bar.first, false);
	test(foo.second == bar.second, false);
	foo = bar;
	test(foo==bar, true);
	test(foo!=bar, false);
	test(foo<bar, false);
	test(foo>bar, false);
	test(foo<=bar, true);
	test(foo>=bar, true);
	test(foo.first, bar.first);
	test(foo.second, bar.second);
	test(foo.first == bar.first, true);
	test(foo.second == bar.second, true);
	std::cout << std::endl;
}

void test_makepair()
{
	ft::pair<int,char> foo = ft::make_pair(10,'z');
	ft::pair<int,char> bar = ft::make_pair(90,'a');

	print_name("ft::make_pair");
	test(foo==bar, false);
	test(foo!=bar, true);
	test(foo<bar, true);
	test(foo>bar, false);
	test(foo<=bar, true);
	test(foo>=bar, false);
	test(foo.first == bar.first, false);
	test(foo.second == bar.second, false);
	foo = bar;
	test(foo==bar, true);
	test(foo!=bar, false);
	test(foo<bar, false);
	test(foo>bar, false);
	test(foo<=bar, true);
	test(foo>=bar, true);
	test(foo.first, bar.first);
	test(foo.second, bar.second);
	test(foo.first == bar.first, true);
	test(foo.second == bar.second, true);
	std::cout << std::endl;
}

int main (void)
{
	print_title("Utilities");
	test_pair();
	test_makepair();
	return (0);
}