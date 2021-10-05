/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree_node.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:56:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/05 13:51:19 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARYTREE_NODE_HPP
# define FT_BINARYTREE_NODE_HPP

# include "ft_utilities.hpp"

namespace ft
{
	template <typename K, typename T>
	class Node
	{
		public:
			typedef ft::pair<K, T>					value_type;
			typedef Node<K, T>*						node_pointer;
			typedef Node<K, T>&						node_reference;
			typedef const K&						key_reference;
			typedef T&								value_reference;
			typedef T*								value_pointer;
			typedef Node<K, T>						_Self;

		public:
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
			
			node_pointer minimum(void) { return (minimum(this)); }
			node_pointer minimum(node_pointer node)
			{
				while (node && node->_left)
					node = node->_left;
				return (node);
			}

			node_pointer maximum(void) { return (maximum(this)); }
			node_pointer maximum(node_pointer node)
			{
				while (node && node->_right)
					node = node->_right;
				return (node);
			}
			node_pointer successor(void) { return (successor(this)); }
			node_pointer successor(node_pointer node)
			{
				node_pointer parent = nullptr;

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
			node_pointer predecessor(void) { return (predecessor(this)); }
			node_pointer predecessor(node_pointer node)
			{
				node_pointer parent = nullptr;

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
	};
}

#endif
