/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/01 15:39:42 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename T>
std::string vector_assignment_op()
{
	T rng(10, 100);
	T v;

	v = rng;
	std::string s = vector_attributes<T>(v);
	
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_copy_constructor1()
{
	T rng(10, 100);
	T v(rng);
	std::string s = vector_attributes<T>(v);
	
	return (ft::Tester::Return(s));
}

template <typename T>
std::string RangeConstructor_constructor1()
{
	T rng(10, 100);
	T v(rng.begin(), rng.end());
	std::string s = vector_attributes<T>(v);
	
	return (ft::Tester::Return(s));
}

template <typename T>
std::string FillConstructor_constructor1()
{
	T v(10, 999);
	std::string s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string default_constructor1()
{
	T v;
	std::string s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}


void test_vector_copy_constructor(ft::Tester &tester)
{
	tester.printName("Copy Constructor");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_copy_constructor1< ft::vector<int> >(),
			vector_copy_constructor1< std::vector<int> >()
		);
		tester.compare(
			vector_copy_constructor1< ft::vector<float> >(),
			vector_copy_constructor1< std::vector<float> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_copy_constructor1< ft::vector<int> >();
		vector_copy_constructor1< ft::vector<float> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_copy_constructor1< std::vector<int> >();
		vector_copy_constructor1< std::vector<float> >();
		tester.printClock("[std]");
	}
}

void test_vector_assignment_op(ft::Tester &tester)
{
	tester.printName("operator=()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_assignment_op< ft::vector<int> >(),
			vector_assignment_op< std::vector<int> >()
		);
		tester.compare(
			vector_assignment_op< ft::vector<float> >(),
			vector_assignment_op< std::vector<float> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_assignment_op< ft::vector<int> >();
		vector_assignment_op< ft::vector<float> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_assignment_op< std::vector<int> >();
		vector_assignment_op< std::vector<float> >();
		tester.printClock("[std]");
	}
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
	tester.printName("* CONSTRUCTORS *", true);
	test_vector_default_constructor(tester);
	test_vector_fill_constructor(tester);
	test_vector_range_constructor(tester);
	test_vector_copy_constructor(tester);
	test_vector_assignment_op(tester);
}
