/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 12:04:04 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename T>
std::string resize1()
{
	T v(10, 42);
	std::string s;

	v.resize(500);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string resize2()
{
	T v(10, 42);
	std::string s;

	v.resize(3);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string max_size()
{
	T v;
	std::string s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string size1()
{
	T v(10, 999);
	std::string s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string size2()
{
	T v(0, 0);
	std::string s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string capacity1()
{
	T v;
	std::string s;

	v.reserve(1000);
	s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string capacity2()
{
	T v(100, 42);
	std::string s;

	v.reserve(110);
	s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_empty()
{
	T v(100, 42);
	std::string s;

	v.empty();
	s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_reserve()
{
	T v(100, 42);
	std::string s;

	v.reserve(200);
	s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

void test_vector_reserve(void)
{
	ft::Tester tester;

	tester.printName("reserve()");
	tester.add(
		vector_reserve< ft::vector<int> >,
		vector_reserve< std::vector<int> >
	);
	tester.run();

}

void test_vector_empty(void)
{
	ft::Tester tester;

	tester.printName("empty()");
	tester.add(
		vector_empty< ft::vector<int> >,
		vector_empty< std::vector<int> >
	);
	tester.run();
}

void test_vector_resize(void)
{
	ft::Tester tester;

	tester.printName("resize()");
	tester.add(
		resize1< ft::vector<int> >,
		resize1< std::vector<int> >
	);
	tester.add(
		resize2< ft::vector<float> >,
		resize2< std::vector<float> >
	);
	tester.run();
}

void test_vector_max_size(void)
{
	ft::Tester tester;

	tester.printName("max_size()");
	tester.add(
		max_size< ft::vector<int> >,
		max_size< std::vector<int> >
	);
	tester.add(
		max_size< ft::vector<std::string> >,
		max_size< std::vector<std::string> >
	);
	tester.run();
}

void test_vector_size(void)
{
	ft::Tester tester;

	tester.printName("size()");
	tester.add(
		size1< ft::vector<int> >,
		size1< std::vector<int> >
	);
	tester.add(
		size2< ft::vector<int> >,
		size2< std::vector<int> >
	);
	tester.run();
}

void test_vector_cap(void)
{
	ft::Tester tester;

	tester.printName("capacity()");
	tester.add(
		capacity1< ft::vector<int> >,
		capacity1< std::vector<int> >
	);
	tester.add(
		capacity2< ft::vector<int> >,
		capacity2< std::vector<int> >
	);
	tester.run();
}

void test_vector_capacity(void)
{
	ft::Tester tester;

	tester.printName("* CAPACITY *", true);
	test_vector_size();
	test_vector_max_size();
	test_vector_resize();
	test_vector_cap();
	test_vector_empty();
	test_vector_reserve();
}
