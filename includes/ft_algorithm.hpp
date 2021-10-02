/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:52:16 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 11:30:35 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHM_HPP
# define FT_ALGORITHM_HPP

namespace ft
{
	/*
	** true if the first range is lexicographically less than the second.
	*/
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 )
	{
		while ((first1 != last1) && (first2 != last2))
		{
			if (*first1 < *first2)
				return (true);
			else if (*first1 > *first2)
				return(false);
			first1++;
			first2++;
		}
		return ((first1 == last1) && (first2 != last2));
	}

	/*
	** comp: comparison function which returns ​true if the first argument
	** is less than the second.
	*/
	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare (InputIt1 first1, InputIt1 last1,
		InputIt2 first2, InputIt2 last2, Compare comp)
	{
		while ((first1 != last1) && (first2 != last2))
		{
			if (comp(*first1, *first2))
				return (true);
			else if (comp(*first2, *first1))
				return(false);
			first1++;
			first2++;
		}
		return ((first1 == last1) && (first2 != last2));
	}

	/*
	** ft::equal
	*/
	template< class InputIt1, class InputIt2 >
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	/*
	** Binary Predicate is a function that accepts two elements as argument
	**  (one of each of the two sequences - *first, *last),
	** and returns a value convertible to bool.
	*/
	template <class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal (InputIt1 first1, InputIt1 last1,
				InputIt2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}
}

#endif
