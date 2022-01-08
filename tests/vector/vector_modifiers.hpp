/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2022/01/08 09:24:36 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_MODIFIERS_HPP
# define VECTOR_MODIFIERS_HPP

# include "vector_tests.hpp"


template <typename T>
std::string vector_pushback1()
{
	T rng;
	T v;
	std::string s("");
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
	std::string s("");
	for (int i = 0; i < 42; i++)
		rng.push_back(i);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_popback1()
{
	T v;
	std::string s("");
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
	std::string s("");

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
	std::string s("");
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
	std::string s("");

	v.assign(10, 42);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert1()
{
	T v(10, 42);
	T tmp(15, 21);
	std::string s("");

	v.insert(v.begin() + 5, tmp.begin(), tmp.end());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert2()
{
	T v(10, 42);
	std::string s("");

	v.insert(v.begin() + 2, 15, 21);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert3()
{
	T v(10, 42);
	std::string s("");

	v.insert(v.begin() + 2, 15);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert4()
{
	T v(10, 42);
	T tmp(15, 21);
	std::string s("");

	v.insert(v.end(), tmp.begin(), tmp.end());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert5()
{
	T v(10, 42);
	std::string s("");

	v.insert(v.end(), 15, 21);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert6()
{
	T v(10, 42);
	std::string s("");

	v.insert(v.end(), 15);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase1()
{
	T v;
	std::string s("");

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
	std::string s("");

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
	std::string s("");

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
	std::string s("");

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
	std::string s("");

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
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.push_back(i);
	for(int i = 5; i >= 0; i--)
		v2.push_back(i);
	v1.swap(v2);
	s = "v1: " + vector_attributes<T>(v1) + "\n";
	s += "v2: " + vector_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_swap_ref()
{
	T v1;
	T v2;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.push_back(i);
	for(int i = 5; i >= 0; i--)
		v2.push_back(i);
	typename T::reference ref1 = *(v1.begin());
	typename T::reference ref2 = *(v1.begin() + 1);
	typename T::reference ref3 = *(v1.begin() + 2);
	v1.swap(v2);
	s = "ref1: " + ft::to_string(ref1) + "\n";
	s += "ref2: " + ft::to_string(ref2) + "\n";
	s += "ref3: " + ft::to_string(ref3) + "\n";
	s += "v1: " + vector_attributes<T>(v1) + "\n";
	s += "v2: " + vector_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_swap_pointer()
{
	T v1;
	T v2;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.push_back(i);
	for(int i = 5; i >= 0; i--)
		v2.push_back(i);
	typename T::pointer pnt1 = (v1.begin()).base();
	typename T::pointer pnt2 = (v1.begin() + 1).base();
	typename T::pointer pnt3 = (v1.begin() + 2).base();
	v1.swap(v2);
	s = "pnt1: " + ft::to_string(*pnt1) + " addr: " + ft::to_string((v2.begin()).base() == pnt1) + "\n";
	s += "pnt2: " + ft::to_string(*pnt2) + " addr: " + ft::to_string((v2.begin() + 1).base() == pnt2) + "\n";
	s += "pnt3: " + ft::to_string(*pnt3) + " addr: " + ft::to_string((v2.begin() + 2).base() == pnt3) + "\n";
	s += "v1: " + vector_attributes<T>(v1) + "\n";
	s += "v2: " + vector_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_swap_iterator()
{
	T v1;
	T v2;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.push_back(i);
	for(int i = 5; i >= 0; i--)
		v2.push_back(i);
	typename T::iterator it = v1.begin();
	v1.swap(v2);
	v2.push_back(99);
	s += "iterator: ";
	for (; it != v2.end(); it++)
		s += ft::to_string(*it) + "|";
	s += "\nv1: " + vector_attributes<T>(v1) + "\n";
	s += "v2: " + vector_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_clear()
{
	T v(10, 42);
	T tmp(15, 21);
	std::string s("");

	v.insert(v.end(), tmp.begin(), tmp.end());
	v.clear();
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

#endif
