/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:52:16 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/15 10:52:31 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	
	template< class InputIt1, class InputIt2 >
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2)) {
				return false;
			}
			first1++;
			first2++;
		}
		return true;
	}
}