/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:04:20 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:04:20 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <iostream>

#include "tests.hpp"

std::string randomString(const int len)
{
	std::string tmp_s;
	static const char alphanum[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	tmp_s.reserve(len);
	for (int i = 0; i < len; i++)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	return tmp_s;   
}

int main (int argc, char **argv)
{
	ft::Tester tester;
	if (argc == 1)
	{
		if (ORIGINAL_STD == 1)
		{
			std::cout << "ORIGINAL_STD" << std::endl;
			ft::Tester::kind = KIND_STD;
		}
		else
		{
			std::cout << "FT" << std::endl;
			ft::Tester::kind = KIND_FT;
		}
	}
	else
		ft::Tester::kind = KIND_COMPARE;
	

	test_utilities();
	test_vector();
	test_map();
	test_set();

	(void)argv;
	return (0);
}
