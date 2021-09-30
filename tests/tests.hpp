/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:43:31 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/29 21:05:24 by iwillens         ###   ########.fr       */
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


#endif
