/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_modifiers.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:37:18 by iwillens          #+#    #+#             */
/*   Updated: 2022/01/02 12:37:20 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MODIFIERS_HPP
# define STACK_MODIFIERS_HPP

# include "stack_tests.hpp"

template <typename T>
std::string stack_push1()
{
	T v;
	for (int i = 0; i < 42; i++)
		v.push(i);
	std::string s = stack_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_push2()
{
	typename T::container_type c(7, 42);
	T v(c);
	for (int i = 0; i < 28; i++)
		v.push(i);
	std::string s = stack_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_pop1()
{
	T v;
	for (int i = 0; i < 42; i++)
		v.push(i);
	while (v.size())
		v.pop();
	std::string s = stack_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_pop2()
{
	typename T::container_type c(7, 42);
	T v(c);
	for (int i = 0; i < 28; i++)
		v.push(i);
	for (int i = 0; i < 5; i++)
		v.pop();
	std::string s = stack_attributes<T>(v);
	return (ft::Tester::Return(s));
}


#endif
