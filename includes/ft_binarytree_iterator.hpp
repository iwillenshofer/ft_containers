/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:20:07 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/07 20:37:44 by iwillens         ###   ########.fr       */
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
		
			typedef typename ft::bidirectional_iterator_tag	iterator_category;
			typedef typename T::value_type					value_type;
			typedef typename T::difference_type				difference_type;
			typedef typename T::pointer						pointer;
			typedef typename T::reference					reference;
		
		private:
			typedef typename ft::BinaryTreeIterator<T>									_self;
			typedef typename ft::BinaryTreeIterator<const T>							const_self;
			typedef	T*																	node_pointer;
		protected:
			node_pointer	_p;
	
		public:
			BinaryTreeIterator(): _p() { };
			explicit BinaryTreeIterator(node_pointer p): _p(p) { };
			BinaryTreeIterator(BinaryTreeIterator const &b): _p(b._p) { };
			virtual ~BinaryTreeIterator() {}

 			/*
			** User-defined conversion function, as described in BidirectionalIterator.
			** allows for `typename ft::vector<int>::const_iterator it = container.begin();`
			*/

			operator const_self() const { return const_self(this->_p); }
			node_pointer	base() const { return this->_p; }

			BinaryTreeIterator &operator=(BinaryTreeIterator const &b)
			{
				this->_p = b._p;
				return (*this);
			}

			typename T::value_type &operator*() { return (const_cast<typename T::value_type &>(this->_p->Pair())); }
			typename T::value_type *operator->() { return (const_cast<typename T::value_type*>(&(this->_p->Pair()))); }


			BinaryTreeIterator	operator+(difference_type const &n) const { return (_self(this->_p + n)); }
			BinaryTreeIterator	operator-(difference_type const &n) const
			{
				node_pointer tmp = this->_p;
				difference_type steps = n;
				if (steps > 0)
				{
					while (steps)
					{
						tmp = tmp->predecessor();
						steps--;
					}	
				}
				else
				{
					while (steps)
					{
						tmp = tmp->successor();
						steps++;
					}
				}
				return (_self(tmp));
			}


			BinaryTreeIterator &operator++() { this->_p = this->_p->successor(); return (*this); }
			BinaryTreeIterator &operator--() { this->_p = this->_p->predecessor(); return (*this);}

			BinaryTreeIterator operator++(int)
			{
				_self tmp(*this);

				this->_p = this->_p->successor();
				return (tmp); 
			}

			BinaryTreeIterator operator--(int)
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
