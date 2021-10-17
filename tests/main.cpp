/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:04:20 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/17 12:24:36 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <iostream>
#include <sstream>
#include "tests.hpp"

std::string randomString(const int len)
{
	std::string s;
	static const char alphanum[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	s.reserve(len);
	for (int i = 0; i < len; i++)
		s += alphanum[rand() % (sizeof(alphanum) - 1)];
	return s;   
}

void set_largenumber(int argc, char **argv, int cmd_pos)
{
	if (argc <= cmd_pos)
		return;
	std::istringstream ss(argv[cmd_pos]);
	int number;
	if (!(ss >> number) || number < 0 || number > 100000)
		return;
	ft::Tester::large_number = number;
}

void run_tests (int argc, char **argv, int cmd_pos)
{
	set_largenumber(argc, argv, cmd_pos + 1);
	if (argc <= cmd_pos ||  std::string(argv[cmd_pos]) == std::string("all"))
	{
		test_utilities();
		test_vector();
		test_map();
		test_stack();
		test_set();
	}
	else if (std::string(argv[cmd_pos]) == std::string("utilities"))
		test_utilities();
	else if (std::string(argv[cmd_pos]) == std::string("vector"))
		test_vector();
	else if (std::string(argv[cmd_pos]) == std::string("map"))
		test_map();
	else if (std::string(argv[cmd_pos]) == std::string("stack"))
		test_stack();
	else if (std::string(argv[cmd_pos]) == std::string("set"))
		test_set();
}


int main (int argc, char **argv)
{
	ft::Tester tester;
	int cmd_pos = 1;

	if (argc == 1 || std::string(argv[1]) != std::string("compare"))
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
	{
		ft::Tester::kind = KIND_COMPARE;
		cmd_pos++;
	}
	run_tests(argc, argv, cmd_pos);
	return (0);
}
