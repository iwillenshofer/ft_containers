/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:34:42 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/27 13:54:21 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

# include "iterators.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		typedef	Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;
	
	reverse_iterator();
	reverse_iterator (iterator_type it);
	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter>& rev_it);
	iterator_type base() const;


	iterator_type _p;
	};
}


#endif