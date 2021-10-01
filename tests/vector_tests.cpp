/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:47:16 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/01 17:43:37 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_vector(ft::Tester &tester)
{
    tester.printTitle("Vector");
    test_vector_constructors(tester);
    test_vector_capacity(tester);
	test_vector_iterators(tester);
	test_vector_elementaccess(tester);
	test_vector_modifiers(tester);
	test_vector_overloads(tester);
}
