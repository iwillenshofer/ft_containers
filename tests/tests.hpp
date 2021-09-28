/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:43:31 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/27 20:02:14 by iwillens         ###   ########.fr       */
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

/*
** iterators
*/

void test_reverseiterator(ft::Tester tester);
void test_iteratortraits(ft::Tester &tester);


#endif
