/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverseiterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:54:24 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/25 17:55:14 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

/*
** string
*/

template<typename T>
std::string test3()
{
	std::string s;
	std::string txt(".gnirtS a gnitseT");
	T v(txt.data(), txt.data() + txt.size());

	for (typename T::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
			s += ft::to_string(*it);
	}
	return (s);
}

/*
** complex types
*/

template<typename T1, typename T2>
std::string test2()
{
	std::string s;
	int array[5];
	for (int i = 0; i < 5; i++)
		array[i] = i;
	T1 v;
	T2 tmp(array, array + 5);
	v.push_back(tmp);
	v.push_back(tmp);
	v.push_back(tmp);
	v.push_back(tmp);
	v.push_back(tmp);
	for (typename T1::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		for (typename T2::reverse_iterator it2 = (*it).rbegin(); it2 != (*it).rend(); it2++)
			s += ft::to_string(*it2);
	}
	return (s);
}

/*
** integers
*/

template<typename T>
std::string test1()
{
	std::string s;

	T v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (typename T::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		s += ft::to_string(*it);
	}
	return (s);
}


void test_reverseiterator(ft::Tester tester)
{
	typedef  std::vector<int>   STD1;
	typedef  ft::vector<int>    FT1;
	typedef  std::vector< std::vector<int> >   STD2;
	typedef  ft::vector< ft::vector<int> >    FT2;
	typedef  std::vector<char>   STD3;
	typedef  ft::vector<char>   FT3;
	tester.printName("ft::reverse_iterator");

	tester.compare(test1< STD1 >(), test1< FT1 >());
    tester.compare(test2< STD2, STD1 >(), test2< FT2, FT1 >());
	tester.compare(test3< FT3 >(), test3< FT3 >());

	std::cout << std::endl;
	tester.startClock();
	test1< STD1 >();
	test2< STD2, STD1 >();
	test3< STD3 >();
	tester.printClock("[std]");

	tester.startClock();
	test1< FT1 >();
	test2< FT2, FT1 >();
	test3< FT3 >();
	tester.printClock("[ft ]");


	std::cout << std::endl;


//	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
//		std::cout << *it << " | ";
	ft::vector<int> v;
	v.insert(v.begin(), 15, 5);
	for (std::reverse_iterator<ft::vector<int>::iterator> it = v.rbegin(); it != v.rend(); it++)
		std::cout << *it << " | ";
	std::cout << std::endl;

	std::vector<int> v2;
	v2.insert(v2.begin(), 15, 5);
	for (ft::reverse_iterator<std::vector<int>::iterator> it = v2.rbegin(); it != v2.rend(); it++)
		std::cout << *it << " | ";
	std::cout << std::endl;




	std::reverse_iterator<ft::vector<int>::iterator> r = v.rbegin();


	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " | ";
	std::cout << std::endl;


	std::string s = "Hello, world";
	for (ft::reverse_iterator<std::string::iterator> it = s.rbegin(); it != s.rend(); it++)
    	std::cout << *it;
	std::cout << std::endl;


	ft::vector<int> v3;
	v3.insert(v3.begin(), 15, 5);
	ft::reverse_iterator<ft::vector<int>::iterator> it = v3.rbegin();
	ft::reverse_iterator<ft::vector<int>::iterator> ite = v3.rend();

	ft::vector<int> v4;
	v4.insert(v4.begin(), 15, 5);
	ft::vector<int>::reverse_iterator it1 = v4.rbegin();
	ft::vector<int>::reverse_iterator ite1 = v4.rend();




}
