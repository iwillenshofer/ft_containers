/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:47:16 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 15:10:31 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_tests.hpp"

std::string randomString(const int len)
{
	std::string tmp_s;
	static const char alphanum[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	tmp_s.reserve(len);
	for (int i = 0; i < len; i++)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	return tmp_s;   
}

template<>
std::string map_presets<std::string>(int i)
{
	std::string s[3];

	s[0] = "Testing";
	s[1] = "Forty";
	s[2] = "Two";
	return(s[i]);
}

void test_map(void)
{
	ft::Tester tester;

	tester.printTitle("Map");
	test_map_constructors();
	test_map_capacity();
	test_map_iterators();
	test_map_elementaccess();
	test_map_modifiers();
	test_map_operations();
	test_map_overloads();
	test_map_observers();
 	test_map_largetests();

}
