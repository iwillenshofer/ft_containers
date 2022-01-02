/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator_traits.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:11 by iwillens          #+#    #+#             */
/*   Updated: 2022/01/02 12:43:23 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_TRAITS_HPP
# define FT_ITERATOR_TRAITS_HPP

# include <cstddef>

namespace ft
{
	/*
	** simple tags to identify iterators.
	*/

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	/*
	** Base structure for iterators.
	*/

	template <typename Category, typename T, typename Distance = ptrdiff_t,
		typename Pointer = T*, typename Reference = T&>
	class iterator {
		public:
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
	};
	
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
	
	/*
	** ft:distance() calculates the number of elements between first and last.
	** If it is a random-access iterator, the function uses operator- to calculate this.
	** Otherwise, the function uses the increase operator (operator++) repeatedly.
	** Source: https://www.cplusplus.com/reference/iterator/distance/
	*/
	
	template<class Iterator>
	typename ft::iterator_traits<Iterator>::difference_type do_distance(Iterator first, Iterator last, ft::input_iterator_tag)
	{
		typename ft::iterator_traits<Iterator>::difference_type result = 0;

		while (first != last)
		{
			++first;
			++result;
		}
		return (result);
	}
	
	template<class Iterator>
	typename ft::iterator_traits<Iterator>::difference_type do_distance(Iterator first, Iterator last, ft::random_access_iterator_tag)
	{
		return last - first;
	}
	
	template<class Iterator>
	typename ft::iterator_traits<Iterator>::difference_type  distance(Iterator first, Iterator last)
	{
		return ft::do_distance(first, last, typename ft::iterator_traits<Iterator>::iterator_category());
	}
}

#endif
