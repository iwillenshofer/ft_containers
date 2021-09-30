/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/30 18:30:49 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename T>
std::string RangeConstructor_constructor1()
{
	T rng(10, 100);
	T v(rng.begin(), rng.end());
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

template <typename T>
std::string FillConstructor_constructor1()
{
	T v(10, 999);
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

void test_vector_range_constructor(ft::Tester &tester)
{
	tester.printName("Range Constructor");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			RangeConstructor_constructor1< ft::vector<int> >(),
			RangeConstructor_constructor1< std::vector<int> >()
		);
		tester.compare(
			RangeConstructor_constructor1< ft::vector<float> >(),
			RangeConstructor_constructor1< std::vector<float> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		RangeConstructor_constructor1< ft::vector<int> >();
		RangeConstructor_constructor1< ft::vector<float> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		RangeConstructor_constructor1< std::vector<int> >();
		RangeConstructor_constructor1< std::vector<float> >();
		tester.printClock("[std]");
	}
}

void test_vector_fill_constructor(ft::Tester &tester)
{
	tester.printName("Fill Constructor");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			FillConstructor_constructor1< ft::vector<int> >(),
			FillConstructor_constructor1< std::vector<int> >()
		);
		tester.compare(
			FillConstructor_constructor1< ft::vector<float> >(),
			FillConstructor_constructor1< std::vector<float> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		FillConstructor_constructor1< ft::vector<int> >();
		FillConstructor_constructor1< ft::vector<float> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		FillConstructor_constructor1< std::vector<int> >();
		FillConstructor_constructor1< std::vector<float> >();
		tester.printClock("[std]");
	}
}

void test_vector_default_constructor(ft::Tester &tester)
{
	tester.printName("Default Constructor");
	if (tester.kind == KIND_COMPARE)
	{
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
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		default_constructor1< ft::vector<int> >();
		default_constructor1< ft::vector<float> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		default_constructor1< std::vector<int> >();
		default_constructor1< std::vector<float> >();
		tester.printClock("[std]");
	}
}

void test_vector_constructors(ft::Tester &tester)
{
	tester.printName("* CONSTRUCTORS *");
	test_vector_default_constructor(tester);
	test_vector_fill_constructor(tester);
	test_vector_range_constructor(tester);
}
