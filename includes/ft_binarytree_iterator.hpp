/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:44:58 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/05 13:45:43 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redblacktree_iterator.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:20:07 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/03 17:21:37 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REDBLACKTREE_ITERATOR_HPP
# define FT_REDBLACKTREE_ITERATOR_HPP

# include "ft_iterator_traits.hpp"
# include "ft_binarytree_node.hpp"

namespace ft
{

	template <typename T>
	class BinaryTreeIterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
		
		private:
			typedef typename ft::BinaryTreeIterator<value_type>									_self;
			typedef typename ft::BinaryTreeIterator<const value_type>							const_self;

		protected:
			pointer	_p;
	
		public:
			BinaryTreeIterator(): _p() { };
			explicit BinaryTreeIterator(pointer p): _p(p) { };
			BinaryTreeIterator(BinaryTreeIterator const &b): _p(b._p) { };
			virtual ~BinaryTreeIterator() {}

 			/*
			** User-defined conversion function, as described in BidirectionalIterator.
			** allows for `typename ft::vector<int>::const_iterator it = container.begin();`
			*/

			operator const_self() const { return const_self(this->_p); }
			pointer	base() const { return this->_p; }
	
			BinaryTreeIterator &operator=(BinaryTreeIterator const &b)
			{
				this->_p = b._p;
				return (*this);
			}

			reference operator*() { return (*(this->_p)); }
			pointer operator->() { return (&(this->_p)); }

			_self &operator++() { this->_p = this->_p->successor(); return (*this); }
			_self &operator--() { this->_p = this->_p->predecessor(); return (*this); }

			_self operator++(int)
			{
				_self tmp(*this);

				this->_p = this->_p->successor();
				return (tmp); 
			}

			_self operator--(int)
			{
				_self tmp(*this);

				this->_p = this->_p->predecessor();
				return (tmp); 
			}

			bool operator==(const _self &x) const { return (this->_p == x.base()); }
			bool operator!=(const _self &x) const { return (this->_p != x.base()); }

	};

	template<typename Val>
	inline bool	operator==(const BinaryTreeIterator<Val>& x,	const BinaryTreeIterator<Val>& y)
	{ return x._p == y._p; }

	template<typename Val>
	inline bool	operator!=(const BinaryTreeIterator<Val>& x,	const BinaryTreeIterator<Val>& y)
	{ return x._p != y._p; }
}

#endif
