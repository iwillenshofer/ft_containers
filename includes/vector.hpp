/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:02 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/24 17:58:12 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "input_iterator.hpp"

namespace ft
{
	/*
	** Reference for the Vector container?
	** https://cplusplus.com/reference/vector/vector/
	*/

	template < typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::RandomAccessIterator<T, T&, T*>						iterator;
			typedef ft::RandomAccessIterator
						<const T, const T&, const T*>						const_iterator;
		//	typedef ft::reverse_iterator<iterator>					reverse_iterator;
		//	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t													size_type;

		private:
				pointer 		_start;
				pointer 		_finish;
				pointer 		_end_of_storage;
				allocator_type	_data;
			
		public:	
			allocator_type	get_allocator() const { return allocator_type(this->_p); };

	};

}

#endif
