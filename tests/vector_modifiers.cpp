/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/01 21:51:32 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"


template <typename T>
std::string vector_pushback1()
{
	T rng;
	T v;
	std::string s;
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_pushback2()
{
	T rng;
	T v;
	std::string s;
	for (int i = 0; i < 42; i++)
		rng.push_back(i);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_popback1()
{
	T v;
	std::string s;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	v.pop_back();
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_popback2()
{
	T v;
	std::string s;

	v.push_back(1);
	v.pop_back();
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_assign1()
{
	T rng;
	T v;
	std::string s;
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	v.assign(rng.begin() + 3, rng.end());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_assign2()
{
	T v;
	std::string s;

	v.assign(10, 42);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert1()
{
	T v(10, 42);
	T tmp(15, 21);
	std::string s;

	v.insert(v.begin() + 5, tmp.begin(), tmp.end());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert2()
{
	T v(10, 42);
	std::string s;

	v.insert(v.begin() + 2, 15, 21);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert3()
{
	T v(10, 42);
	std::string s;

	v.insert(v.begin() + 2, 15);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert4()
{
	T v(10, 42);
	T tmp(15, 21);
	std::string s;

	v.insert(v.end(), tmp.begin(), tmp.end());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert5()
{
	T v(10, 42);
	std::string s;

	v.insert(v.end(), 15, 21);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert6()
{
	T v(10, 42);
	std::string s;

	v.insert(v.end(), 15);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase1()
{
	T v;
	std::string s;

	for(int i = 0; i <= 10; i++)
		v.push_back(i);
	v.erase(v.begin(), v.end());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase2()
{
	T v;
	std::string s;

	for(int i = 0; i <= 10; i++)
		v.push_back(i);
	v.erase(v.begin() + 3, v.end() - 1);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase3()
{
	T v;
	std::string s;

	for(int i = 0; i <= 10; i++)
		v.push_back(i);
	v.erase(v.begin());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase4()
{
	T v;
	std::string s;

	for(int i = 0; i <= 10; i++)
		v.push_back(i);
	v.erase(v.end() - 1);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase5()
{
	T v;
	std::string s;

	for(int i = 0; i <= 10; i++)
		v.push_back(i);
	v.erase(v.begin() + 5);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_swap()
{
	T v1;
	T v2;
	std::string s;

	for(int i = 0; i <= 10; i++)
		v1.push_back(i);
	for(int i = 5; i >= 0; i--)
		v2.push_back(i);
	v1.swap(v2);
	s = "v1: " + vector_attributes<T>(v1) + "\n";
	s = "v2: " + vector_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_clear()
{
	T v(10, 42);
	T tmp(15, 21);
	std::string s;

	v.insert(v.end(), tmp.begin(), tmp.end());
	v.clear();
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

void 	test_vector_assign()
{

	ft::Tester tester;

	tester.printName("assign()");
	tester.add(
		vector_assign1< ft::vector<int> >,
		vector_assign1< std::vector<int> >
		);
	tester.add(
		vector_assign2< ft::vector<int> >,
		vector_assign2< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_pushback()
{
	ft::Tester tester;

	tester.printName("push_back()");
	tester.add(
		vector_pushback1< ft::vector<int> >,
		vector_pushback1< std::vector<int> >
		);
	tester.add(
		vector_pushback2< ft::vector<int> >,
		vector_pushback2< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_popback()
{
	ft::Tester tester;

	tester.printName("pop_back()");
	tester.add(
		vector_popback1< ft::vector<int> >,
		vector_popback1< std::vector<int> >
		);
	tester.add(
		vector_popback2< ft::vector<int> >,
		vector_popback2< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_insert()
{
	ft::Tester tester;

	tester.printName("insert()");
	tester.add(
		vector_insert1< ft::vector<int> >,
		vector_insert1< std::vector<int> >
		);
	tester.add(
		vector_insert2< ft::vector<int> >,
		vector_insert2< std::vector<int> >
		);
	tester.add(
		vector_insert3< ft::vector<int> >,
		vector_insert3< std::vector<int> >
		);
	tester.add(
		vector_insert4< ft::vector<int> >,
		vector_insert4< std::vector<int> >
		);
	tester.add(
		vector_insert5< ft::vector<int> >,
		vector_insert5< std::vector<int> >
		);
	tester.add(
		vector_insert6< ft::vector<int> >,
		vector_insert6< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_erase()
{
	ft::Tester tester;

	tester.printName("erase()");
	tester.add(
		vector_erase1< ft::vector<int> >,
		vector_erase1< std::vector<int> >
		);
	tester.add(
		vector_erase2< ft::vector<int> >,
		vector_erase2< std::vector<int> >
		);
	tester.add(
		vector_erase3< ft::vector<int> >,
		vector_erase3< std::vector<int> >
		);
	tester.add(
		vector_erase4< ft::vector<int> >,
		vector_erase4< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_swap()
{
	ft::Tester tester;

	tester.printName("swap()");
	tester.add(
		vector_swap< ft::vector<int> >,
		vector_swap< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_clear()
{
	ft::Tester tester;

	tester.printName("clear()");
	tester.add(
		vector_clear< ft::vector<int> >,
		vector_clear< std::vector<int> >
		);
	tester.run();
}

void test_vector_modifiers(ft:: Tester &tester)
{
	tester.printName("* MODIFIERS *", true);
	test_vector_assign();
	test_vector_pushback();
	test_vector_popback();
	test_vector_insert();
	test_vector_erase();
	test_vector_swap();
	test_vector_clear();
}
