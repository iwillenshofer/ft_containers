/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:11 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/23 13:24:43 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include <cstddef>

namespace ft
{

	/*
	** iterator_traits are helpers that declare definitions for different types
	** of iterators, making unecessary to rewrite code for each different type.
	** References:
	** https://accu.org/journals/overload/9/43/frogley_442/
	** https://en.cppreference.com/w/cpp/iterator/iterator_traits
	** Partial specialization for pointer types (and const pointer) were added,
	** as they also exist in STL. It allows for iteration over raw pointers,
	** like an array of ints.
	*/

	/*
	** simple tags to identify iterators.
	*/

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };


	template<typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template<typename T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef typename ft::random_access_iterator_tag	iterator_category;
	};

	template<typename T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef typename ft::random_access_iterator_tag	iterator_category;
	};
}

#endif
