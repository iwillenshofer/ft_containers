/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/01 15:16:22 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename T>
std::string iterator_rend1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	T v(rng.begin(), rng.end());
	std::string s = vector_attributes<T>(v);
	s += "\n";
	s += "REnd - 1: " + ft::to_string(*(v.rend() - 1)) + "\n";
	s += "REnd - 3: " + ft::to_string(*(v.rend() - 3)) + "\n";
	s += "REnd - 9: " + ft::to_string(*(v.rend() - 9)) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string iterator_rbegin1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	T v(rng.begin(), rng.end());
	std::string s = vector_attributes<T>(v);
	s += "\n";
	s += "RBegin: " + ft::to_string(*(v.rbegin())) + "\n";
	s += "RBegin + 3: " + ft::to_string(*(v.rbegin() + 3)) + "\n";
	s += "RBegin + 9: " + ft::to_string(*(v.rbegin() + 9)) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string iterator_end1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	T v(rng.begin(), rng.end());
	std::string s = vector_attributes<T>(v);
	s += "\n";
	s += "End - 1: " + ft::to_string(*(v.end() - 1)) + "\n";
	s += "End - 3: " + ft::to_string(*(v.end() - 3)) + "\n";
	s += "End - 9: " + ft::to_string(*(v.end() - 9)) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string iterator_begin1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	T v(rng.begin(), rng.end());
	std::string s = vector_attributes<T>(v);
	s += "\n";
	s += "Begin: " + ft::to_string(*(v.begin())) + "\n";
	s += "Begin + 3: " + ft::to_string(*(v.begin() + 3)) + "\n";
	s += "Begin + 9: " + ft::to_string(*(v.begin() + 9)) + "\n";
	return (ft::Tester::Return(s));
}

void test_vector_iterator_end(ft::Tester &tester)
{
	tester.printName("end()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			iterator_end1< ft::vector<int> >(),
			iterator_end1< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		iterator_end1< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		iterator_end1< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void test_vector_iterator_begin(ft::Tester &tester)
{
	tester.printName("begin()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			iterator_begin1< ft::vector<int> >(),
			iterator_begin1< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		iterator_begin1< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		iterator_begin1< std::vector<int> >();
		tester.printClock("[std]");
	}
}


void test_vector_iterator_rend(ft::Tester &tester)
{
	tester.printName("rend()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			iterator_rend1< ft::vector<int> >(),
			iterator_rend1< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		iterator_rend1< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		iterator_rend1< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void test_vector_iterator_rbegin(ft::Tester &tester)
{
	tester.printName("rbegin()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			iterator_rbegin1< ft::vector<int> >(),
			iterator_rbegin1< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		iterator_rbegin1< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		iterator_rbegin1< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void test_vector_iterators(ft::Tester &tester)
{
	tester.printName("* ITERATORS *", true);
	test_vector_iterator_begin(tester);
	test_vector_iterator_end(tester);
	test_vector_iterator_rbegin(tester);
	test_vector_iterator_rend(tester);
}
