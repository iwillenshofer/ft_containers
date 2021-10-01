/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/01 15:30:04 by iwillens         ###   ########.fr       */
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

void test_vector_reserve(ft::Tester &tester)
{
	tester.printName("reserve()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_reserve< ft::vector<int> >(),
			vector_reserve< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_reserve< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_reserve< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void test_vector_empty(ft::Tester &tester)
{
	tester.printName("empty()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_empty< ft::vector<int> >(),
			vector_empty< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_empty< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_empty< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void test_vector_resize(ft::Tester &tester)
{
	tester.printName("resize()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			resize1< ft::vector<int> >(),
			resize1< std::vector<int> >()
		);
		tester.compare(
			resize2< ft::vector<float> >(),
			resize2< std::vector<float> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		resize1< ft::vector<int> >();
		resize2< ft::vector<float> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		resize1< std::vector<int> >();
		resize2< std::vector<float> >();
		tester.printClock("[std]");
	}
}

void test_vector_max_size(ft::Tester &tester)
{
	tester.printName("max_size()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			max_size< ft::vector<int> >(),
			max_size< std::vector<int> >()
		);
		tester.compare(
			max_size< ft::vector<std::string> >(),
			max_size< std::vector<std::string> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		max_size< ft::vector<int> >();
		max_size< ft::vector<std::string> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		max_size< std::vector<int> >();
		max_size< std::vector<std::string> >();
		tester.printClock("[std]");
	}
}

void test_vector_size(ft::Tester &tester)
{
	tester.printName("size()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			size1< ft::vector<int> >(),
			size1< std::vector<int> >()
		);
		tester.compare(
			size2< ft::vector<int> >(),
			size2< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		size1< ft::vector<int> >();
		size2< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		size1< std::vector<int> >();
		size2< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void test_vector_cap(ft::Tester &tester)
{
	tester.printName("capacity()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			capacity1< ft::vector<int> >(),
			capacity1< std::vector<int> >()
		);
		tester.compare(
			capacity2< ft::vector<int> >(),
			capacity2< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		capacity1< ft::vector<int> >();
		capacity2< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		capacity1< std::vector<int> >();
		capacity2< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void test_vector_capacity(ft::Tester &tester)
{
	tester.printName("* CAPACITY *", true);
	test_vector_size(tester);
	test_vector_max_size(tester);
	test_vector_resize(tester);
	test_vector_cap(tester);
	test_vector_empty(tester);
	test_vector_reserve(tester);
}
