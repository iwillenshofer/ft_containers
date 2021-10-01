/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_overloads.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/01 18:27:31 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"


template <typename T>
std::string vector_getallocator()
{
	T v;
	std::string s;

	s = vector_attributes<T>(v);
	s += "\nAlloc Max Size: " + ft::to_string(v.get_allocator().max_size());
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_relational1()
{
	T v1(3, 100);
	T v2(5, 200);
	std::string s;

	if (v1 == v2)
		s += "v1 and v2 are equal\n";
	if (v1 != v2)
		s += "v1 and v2 are not equal\n";
	if (v1 <  v2)
		s += "v1 is less than v2\n";
	if (v1 >  v2)
		s += "v1 is greater than v2\n";
	if (v1 <= v2)
		s += "v1 is less than or equal to v2\n";
	if (v1 >= v2)
		s += "v1 is greater than or equal to v2\n";
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_relational2()
{
	T v1(3, 100);
	T v2(3, 100);
	std::string s;

	if (v1 == v2)
		s += "v1 and v2 are equal\n";
	if (v1 != v2)
		s += "v1 and v2 are not equal\n";
	if (v1 <  v2)
		s += "v1 is less than v2\n";
	if (v1 >  v2)
		s += "v1 is greater than v2\n";
	if (v1 <= v2)
		s += "v1 is less than or equal to v2\n";
	if (v1 >= v2)
		s += "v1 is greater than or equal to v2\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_relational3()
{
	T v1(4, 200);
	T v2(3, 100);
	std::string s;

	if (v1 == v2)
		s += "v1 and v2 are equal\n";
	if (v1 != v2)
		s += "v1 and v2 are not equal\n";
	if (v1 <  v2)
		s += "v1 is less than v2\n";
	if (v1 >  v2)
		s += "v1 is greater than v2\n";
	if (v1 <= v2)
		s += "v1 is less than or equal to v2\n";
	if (v1 >= v2)
		s += "v1 is greater than or equal to v2\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_relational4()
{
	T v1(3, 100);
	T v2(4, 100);
	std::string s;

	if (v1 == v2)
		s += "v1 and v2 are equal\n";
	if (v1 != v2)
		s += "v1 and v2 are not equal\n";
	if (v1 <  v2)
		s += "v1 is less than v2\n";
	if (v1 >  v2)
		s += "v1 is greater than v2\n";
	if (v1 <= v2)
		s += "v1 is less than or equal to v2\n";
	if (v1 >= v2)
		s += "v1 is greater than or equal to v2\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_swap(void (*swap)(T&, T&))
{
	T v1;
	T v2;
	std::string s;

	for(int i = 0; i <= 10; i++)
		v1.push_back(i);
	for(int i = 5; i >= 0; i--)
		v2.push_back(i);
	swap(v1, v2);
	s = "v1: " + vector_attributes<T>(v1) + "\n";
	s += "v2: " + vector_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

void 	test_vector_getallocator(ft::Tester &tester)
{
	tester.printName("get_allocator()");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_getallocator< ft::vector<int> >(),
			vector_getallocator< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_getallocator< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_getallocator< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void 	test_vector_relationalops(ft::Tester &tester)
{
	tester.printName("relational operators");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_relational1< ft::vector<int> >(),
			vector_relational1< std::vector<int> >()
		);
		tester.compare(
			vector_relational2< ft::vector<int> >(),
			vector_relational2< std::vector<int> >()
		);
		tester.compare(
			vector_relational3< ft::vector<int> >(),
			vector_relational3< std::vector<int> >()
		);
		tester.compare(
			vector_relational4< ft::vector<int> >(),
			vector_relational4< std::vector<int> >()
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_relational1< ft::vector<int> >();
		vector_relational2< ft::vector<int> >();
		vector_relational3< ft::vector<int> >();
		vector_relational4< ft::vector<int> >();
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_relational1< std::vector<int> >();
		vector_relational2< std::vector<int> >();
		vector_relational3< std::vector<int> >();
		vector_relational4< std::vector<int> >();
		tester.printClock("[std]");
	}
}

void 	test_vector_nonmemberswap(ft::Tester &tester)
{
	tester.printName("swap");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_swap< ft::vector<int> >(ft::swap),
			vector_swap< std::vector<int> >(std::swap)
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_swap< ft::vector<int> >(ft::swap);
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_swap< std::vector<int> >(std::swap);
		tester.printClock("[std]");
	}
}

void test_vector_overloads(ft::Tester &tester)
{
	tester.printName("* ALLOCATOR *", true);
	test_vector_getallocator(tester);
	tester.printName("* NON-MEMBER FUNCTION OVERLOADS *", true);
	test_vector_relationalops(tester);
	test_vector_nonmemberswap(tester);
}
