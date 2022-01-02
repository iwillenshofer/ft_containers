/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:37:27 by iwillens          #+#    #+#             */
/*   Updated: 2022/01/02 12:37:30 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_FUNCTIONS_HPP
# define STACK_FUNCTIONS_HPP

# include "stack_tests.hpp"

template <typename T>
std::string stack_constructor1()
{
	T v;
	std::string s = stack_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_constructor2()
{
	typename T::container_type vec(100, 50);
	T v(vec);
	std::string s = stack_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_constructor3()
{
	typename T::container_type c(7, 42);
	T v(c);
	std::string s = stack_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_empty1()
{
	typename T::container_type c(7, 42);
	T v(c);
	std::string s = stack_attributes<T>(v);
	s += "Empty: " + ft::to_string(v.empty()) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_empty2()
{
	T v;
	std::string s = stack_attributes<T>(v);
	s += "Empty: " + ft::to_string(v.empty()) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_size1()
{
	typename T::container_type c(7, 42);
	T v(c);
	std::string s = stack_attributes<T>(v);
	s += "Empty: " + ft::to_string(v.empty()) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_size2()
{
	T v;
	std::string s = stack_attributes<T>(v);
	s += "Empty: " + ft::to_string(v.empty()) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_top1()
{
	typename T::container_type c(7, 42);
	T v(c);
	std::string s = stack_attributes<T>(v);
	s += "Top: " + ft::to_string(v.top()) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_top2()
{
	typename T::container_type c(7, 42);
	T v(c);
	v.top() = 16;
	std::string s = stack_attributes<T>(v);
	s += "Top: " + ft::to_string(v.top()) + "\n";
	return (ft::Tester::Return(s));
}

#endif
