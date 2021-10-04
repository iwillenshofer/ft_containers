/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree_node.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:56:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/04 16:11:31 by iwillens         ###   ########.fr       */
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
			typedef ft::pair<const K, T>			value_type;
			typedef Node<K, T>*						node_pointer;
			typedef Node<K, T>&						node_reference;
			typedef const K&						key_reference;
			typedef T&								value_reference;

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
				this->_right = value_type(cp._value);
				return (*this);
			}
			virtual ~Node() {}
			value_type &Pair(void) { return (this->_value); }
			key_reference Key(void) { return (this->_value.first); }
			value_reference Value(void) { return (this->_value.second); }
	};
}

#endif
