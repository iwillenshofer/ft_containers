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

namespace ft
{
	/*
	** ft_redblacktree.hpp prototypes.
	*/
	template <typename Val>	class RbNode;
	enum RbColor { RbRed = false, RbBlack = true};

	template <typename T>
	class RedBlackTreeIterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
		
		private:
			typedef typename ft::RedBlackTreeIterator<value_type>								_self;
			typedef typename ft::RedBlackTreeIterator<const value_type>							const_self;
			typedef typename ft::RbNode<T>::node_pointer										node_pointer;
			typedef typename ft::RbNode<T>*														link_type;

		protected:
			node_pointer	_p;
	
		public:
			RedBlackTreeIterator(): _p() { };
			explicit RedBlackTreeIterator(link_type p): _p(p) { };
			RedBlackTreeIterator(RedBlackTreeIterator const &b): _p(b._p) { };
			virtual ~RedBlackTreeIterator() {}

 			/*
			** User-defined conversion function, as described in BidirectionalIterator.
			** allows for `typename ft::vector<int>::const_iterator it = container.begin();`
			*/

			operator const_self() const { return const_self(this->_p); }
			node_pointer	base() const { return this->_p; }
	
			RedBlackTreeIterator &operator=(RedBlackTreeIterator const &b)
			{
				this->_p = b._p;
				return (*this);
			}

			reference operator*() { return (static_cast<link_type>(this->_p)->_value); }
			pointer operator->() { return (&(static_cast<link_type>(this->_p)->value)); }

			_self &operator++() { this->_p = RedBlackTreeIterator::increment(this->_p); return (*this); }
			_self &operator--() { this->_p = RedBlackTreeIterator::decrement(this->_p); return (*this); }

			_self operator++(int)
			{
				_self tmp(*this);

				this->_p = RedBlackTreeIterator::increment(this->_p);
				return (tmp); 
			}

			_self operator--(int)
			{
				_self tmp(*this);

				this->_p = RedBlackTreeIterator::decrement(this->_p);
				return (tmp); 
			}

			bool operator==(const _self &x) const { return (this->_p == x.base()); }
			bool operator!=(const _self &x) const { return (this->_p != x.base()); }
	
			static node_pointer increment(node_pointer & node)
			{
				if (node->_right) 
				{
					node = node->_right;
					while (node->_left)
						node = node->_left;
				}
				else 
				{
					node_pointer antecessor = node->_parent;
					while (node == antecessor->_right) 
					{
						node = antecessor;
						antecessor = antecessor->_parent;
					}
					if (node->_right != antecessor)
					node = antecessor;
				}
				return (node);
			}

			static node_pointer decrement(node_pointer & node)
			{
				if (node->_color == RbRed && node->_parent->_parent == node)
				{
					node = node->_right;
				}
				else if (node->_left)
				{
					node_pointer antecessor = node->_left;
					while (antecessor->_right)
						antecessor = antecessor->_right;
					node = antecessor;
				}
				else
				{
					node_pointer antecessor = node->_parent;
					while (node == antecessor->_left)
					{
						node = antecessor;
						antecessor = antecessor->_parent;
					}
					node = antecessor;
				}
				return (node);
			}
	};

	template<typename Val>
	inline bool	operator==(const RedBlackTreeIterator<Val>& x,	const RedBlackTreeIterator<Val>& y)
	{ return x._p == y._p; }

	template<typename Val>
	inline bool	operator!=(const RedBlackTreeIterator<Val>& x,	const RedBlackTreeIterator<Val>& y)
	{ return x._p != y._p; }
}

#endif
