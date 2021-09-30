/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/30 19:30:14 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <typename T>
std::string resize1()
{
	T v(10, 42);
	std::string s;

	v.resize(500);
	s += "Capacity: " + ft::to_string(v.capacity()) + "\n";
	s += "Size: " + ft::to_string(v.size()) + "\n";
	s += "Content: \n";
	for (typename T::iterator it = v.begin(); it != v.end(); it++)
		s += ft::to_string(*it) + "|";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string resize2()
{
	T v(10, 42);
	std::string s;

	v.resize(3);
	s += "Capacity: " + ft::to_string(v.capacity()) + "\n";
	s += "Size: " + ft::to_string(v.size()) + "\n";
	s += "Content: \n";
	for (typename T::iterator it = v.begin(); it != v.end(); it++)
		s += ft::to_string(*it) + "|";
	return (ft::Tester::Return(s));
}


template <typename T>
std::string max_size()
{
	T v;
	std::string s;

	s += "Capacity: " + ft::to_string(v.capacity()) + "\n";
	s += "Size: " + ft::to_string(v.size()) + "\n";
	s += "Max Size: " + ft::to_string(v.max_size()) + "\n";
	s += "Content: \n";

	for (typename T::iterator it = v.begin(); it != v.end(); it++)
	{
		s += ft::to_string(*it) + "|";
	}
	return (ft::Tester::Return(s));
}

template <typename T>
std::string size1()
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
std::string size2()
{
	T v(0, 0);
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
std::string capacity1()
{
	T v;
	std::string s;

	s.reserve(1000);
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
std::string capacity2()
{
	T v;
	std::string s;

	s.reserve(1000);
	s.resize(0);
	s += "Capacity: " + ft::to_string(v.capacity()) + "\n";
	s += "Size: " + ft::to_string(v.size()) + "\n";
	s += "Content: \n";

	for (typename T::iterator it = v.begin(); it != v.end(); it++)
	{
		s += ft::to_string(*it) + "|";
	}
	return (ft::Tester::Return(s));
}

void test_vector_resize(ft::Tester &tester)
{
	tester.printName("Resize");
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
	tester.printName("Fill Constructor");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			max_size< ft::vector<int> >(),
			max_size< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		max_size< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		max_size< std::vector<int> >();
		tester.printClock("[std]");
	}
}


void test_vector_size(ft::Tester &tester)
{
	tester.printName("Fill Constructor");
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
	tester.printName("Capacity");
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
	tester.printName("* CAPACITY *");
	test_vector_cap(tester);
	test_vector_size(tester);
	test_vector_max_size(tester);
	test_vector_resize(tester);
}
