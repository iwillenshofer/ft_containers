/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:43:31 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/28 18:52:16 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include "Tester.hpp"

/*
** ft:: includes
*/

# include <vector>
# include <iostream>
# include "vector.hpp"
# include "utilities.hpp"


/*
** Utilities
*/

void test_pair(ft::Tester &tester);
void test_makepair(ft::Tester &tester);
void test_enableif(ft::Tester &tester);
void test_isintegral(ft::Tester &tester);
void test_equal(ft::Tester &tester);
void lexicographical_compare(ft::Tester &tester);

/*
** iterators
*/

void test_reverseiterator(ft::Tester tester);
void test_iteratortraits(ft::Tester &tester);



#endif
