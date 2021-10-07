/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree_node.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:56:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/06 22:51:16 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARYTREE_NODE_HPP
# define FT_BINARYTREE_NODE_HPP

# include <algorithm>
# include "ft_utilities.hpp"
#include <iostream>
namespace ft
{
	template <typename K, typename T>
	class Node
	{
		public:
			typedef ft::pair<K, T>					value_type;
			typedef Node<K, T>*						node_pointer;
			typedef Node<K, T>&						node_reference;
			typedef const Node<K, T>*				const_node_pointer;
			typedef const K&						key_reference;
			typedef T&								value_reference;
			typedef T*								value_pointer;
			typedef Node<K, T>						_Self;
			typedef const Node<K, T>				const_self;
			typedef std::size_t							size_type;

			Node(void) {}
			value_type		_value;
			node_pointer	_parent;
			node_pointer	_left;
			node_pointer	_right;

		public:
			Node(value_type const &val): _value(value_type(val)), _left(0x0), _right(0x0) {}
			Node(Node &cp) { *this = cp; }
			Node& operator=(const Node& cp)
			{
				this->_left = cp._left;
				this->_right = cp._right;
				this->_parent = cp._parent;
				this->_value = cp._value;
				return (*this);
			}
			virtual ~Node() {}
			value_type &Pair(void) { return (this->_value); }
			key_reference Key(void) { return (this->_value.first); }
			value_reference Value(void) { return (this->_value.second); }
			void swap(node_pointer node)
			{
				_Self tmp;

				tmp = *node;
				*node = *this;
				*this = tmp;
			}
			void swapValue(node_pointer node)
			{
				value_type tmp = node->_value;

				node->_value = this->_value;
				this->_value = tmp;
			}

			node_pointer minimum(void) { return const_cast<node_pointer>(minimum(this)); }
			const_node_pointer minimum(void) const { return (minimum(this)); }
			const_node_pointer minimum(const_node_pointer node) const
			{
				while (node && node->_left)
					node = node->_left;
				return (node);
			}

			node_pointer maximum(void) { return const_cast<node_pointer>(maximum(this)); }
			const_node_pointer maximum(void) const { return (maximum(this)); }
			const_node_pointer maximum(const_node_pointer node) const
			{
				while (node && node->_right)
					node = node->_right;
				return (node);
			}

			node_pointer successor(void)  { return const_cast<node_pointer>(successor(this)); }
			const_node_pointer successor(void) const { return (successor(this)); }
			const_node_pointer successor(node_pointer node) const
			{
				node_pointer parent = NULL;

				if (node && node->_right)
					return(minimum(node->_right));
				parent = node->_parent;
				while (node && parent && node == parent->_right)
				{
					node = parent;
					parent = node->_parent;
				}
				return (parent);
			}

			node_pointer predecessor(void)  { return const_cast<node_pointer>(predecessor(this)); }
			const_node_pointer predecessor(void) const { return (predecessor(this)); }
			const_node_pointer predecessor(const_node_pointer node) const
			{
				node_pointer parent = NULL;

				if (node && node->_left)
					return(maximum(node->_left));
				parent = node->_parent;
				while (node && node == parent->_left)
				{
					node = parent;
					parent = node->_parent;
				}
				return (parent);
			}

//			size_type height(void)  { return const_cast<node_pointer>(height(this)); }
			size_type height(void) const { return (height(this)); }
			size_type height(const_node_pointer node) const
			{
				if (!(node))
					return (0);
				else
					return (std::max(height(node->_left), height(node->_right)) + 1);
			}
			
			bool balanced(void) const { return (balanced(this)); }
			bool balanced(const_node_pointer node) const
			{
				size_type left = height(node->_left);
				size_type right = height(node->_right);
				size_type diff = left > right ? left - right : right - left;

				return (diff <= 1);
			}

	};
}

#endif
