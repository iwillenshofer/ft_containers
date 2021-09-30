/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/30 17:46:59 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename T>
std::string default_constructor1()
{
	T v;
	std::string s;

	s += "Capacity: " + ft::to_string(v.capacity()) + "\n";
	s += "Size: " + ft::to_string(v.size()) + "\n";
	s += "Content: \n";

	for (typename T::iterator it = v.begin(); it != v.end(); it++)
	{
		s += ft::to_string(*it) + "|";
	}
	return (ft::Tester::Return(s));
}

void test_vector_default_constructor(ft::Tester &tester)
{
	tester.printName("Default Constructor");
	tester.compare(
		default_constructor1< ft::vector<int> >(),
		default_constructor1< std::vector<int> >()
	);
	tester.compare(
		default_constructor1< ft::vector<float> >(),
		default_constructor1< std::vector<float> >()
	);
	tester.compare(
		default_constructor1< ft::vector<bool> >(),
		default_constructor1< std::vector<bool> >()
	);
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		default_constructor1< ft::vector<int> >(),
		default_constructor1< ft::vector<float> >(),
		default_constructor1< ft::vector<bool> >(),
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		default_constructor1< std::vector<int> >(),
		default_constructor1< std::vector<float> >(),
		default_constructor1< std::vector<bool> >(),
		tester.printClock("[std]");
	}
}

void test_vector_constructors(ft::Tester &tester)
{
	tester.printName("* CONSTRUCTORS *");
	test_vector_default_constructor(tester);
}
