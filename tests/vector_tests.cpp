/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:47:16 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/30 20:46:48 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void test_vector(ft::Tester &tester)
{
    tester.printTitle("Vector");
    test_vector_constructors(tester);
    test_vector_capacity(tester);
}
