/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:43:31 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/30 19:12:05 by iwillens         ###   ########.fr       */
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

# ifndef ORIGINAL_STD
#  define ORIGINAL_STD	0
# endif
/*
** Utilities
*/

void test_utilities(ft::Tester &tester);


/*
** iterators
*/

void test_reverseiterator(ft::Tester &tester);

/*
** vector
*/
void	test_vector(ft::Tester &tester);
void    test_vector_constructors(ft::Tester &tester);
void 	test_vector_capacity(ft::Tester &tester);


#endif
