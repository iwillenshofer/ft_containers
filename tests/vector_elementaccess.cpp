/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_elementaccess.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/01 16:23:27 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename T>
std::string vector_operator_brackets()
{
	T v;
	std::string s;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	
	s = vector_attributes<T>(v);
	s += "\n";
	s += "operator[3]: " + ft::to_string(v[3]) + "\n";
	s += "operator[5]: " + ft::to_string(v[5]) + "\n";
	s += "operator[7]: " + ft::to_string(v[7]) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_at()
{
	T v;
	std::string s;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	
	s = vector_attributes<T>(v);
	s += "\n";
	s += "at(3): " + ft::to_string(v.at(3)) + "\n";
	s += "at(5): " + ft::to_string(v.at(5)) + "\n";
	s += "at(7): " + ft::to_string(v.at(7)) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_front()
{
	T v;
	std::string s;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	
	s = vector_attributes<T>(v);
	s += "\n";
	s += "front: " + ft::to_string(v.front()) + "\n";
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_back()
{
	T v;
	std::string s;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	
	s = vector_attributes<T>(v);
	s += "\n";
	s += "back: " + ft::to_string(v.back()) + "\n";
	return (ft::Tester::Return(s));
}


void 	test_vector_at(ft::Tester &tester)
{
	tester.printName("at()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_at< ft::vector<int> >(),
			vector_at< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_at< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_at< std::vector<int> >();
		tester.printClock("[std]");
	}
}


void 	test_vector_front(ft::Tester &tester)
{
	tester.printName("front()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_front< ft::vector<int> >(),
			vector_front< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_front< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_front< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void 	test_vector_back(ft::Tester &tester)
{
	tester.printName("back()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_back< ft::vector<int> >(),
			vector_back< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_back< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_back< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void 	test_vector_operator_brackets(ft::Tester &tester)
{
	tester.printName("operator[]");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_operator_brackets< ft::vector<int> >(),
			vector_operator_brackets< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_operator_brackets< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_operator_brackets< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void test_vector_elementaccess(ft::Tester &tester)
{
	tester.printName("* ELEMENT ACCESS *", true);
	test_vector_operator_brackets(tester);
	test_vector_at(tester);
	test_vector_front(tester);
	test_vector_back(tester);

}
