/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:56:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/04 17:54:39 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARYTREE_HPP
# define FT_BINARYTREE_HPP

# include "ft_binarytree_node.hpp"
# include "ft_iterators.hpp"
# include "ft_iterator_traits.hpp"
# include "ft_reverse_iterator.hpp"
# include <memory>

namespace ft
{
	template <typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class BinaryTree
	{
		public:
			/*
			** regular iterators will be replaced by BinaryTree interators.
			*/
			typedef ft::RandomAccessIterator<T>										iterator;
			typedef ft::RandomAccessIterator<const T>								const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef ft::Node<Key, T>*												node_pointer;
			typedef ft::pair<const Key, T>											value_type;
			typedef typename Alloc::template rebind<ft::Node<Key, T> >::other		allocator;

			BinaryTree(): _root(nullptr) {}
			BinaryTree(BinaryTree const &cp): _root(cp._root) { *this = cp; }
			virtual ~BinaryTree() {};

			node_pointer	_root;
			allocator		_allocator;

			node_pointer insert(value_type const &val) { return(this->insert(this->_root, val)); }

			node_pointer insert(node_pointer node, value_type const &val)
			{
				node_pointer	parent = nullptr;
				bool			left_side = false;
				bool			compare;
				while (node)
				{
					parent = node;
					compare = Compare()(val.first, node->_value.first);
					if (compare)
					{
						node = node->_left;
						left_side = true;
					}
					else
					{
						node = node->_right;
						left_side = false;
					}
				}
				node = this->create_node(val);
				node->_parent = parent;
				if (parent)
					left_side ? parent->_left = node : parent->_right = node;
				if (!(this->_root))
					this->_root = node;
				return (node);
			}

			/*
			** erases a single node
			*/	
			void erase(node_pointer node)
			{
				node_pointer parent = node->_parent;
				node_pointer left = node->_left;
				node_pointer right = node->_right;
	
				
			}

			node_pointer create_node(value_type const &val)
			{
				node_pointer tmp = this->_allocator.allocate(1);
				this->_allocator.construct(tmp, value_type(val));
				return (tmp);
			}
	
			void		delete_node(node_pointer p)
			{
				this->_allocator.destroy(p);
				this->_allocator.deallocate(p, 1);
			}
			
			void clear() { this->clear(this->_root); }
			void clear(node_pointer node)
			{
				if (!node)
					return;
				clear(node->_left);
				clear(node->_right);
				if (node->_parent)
				{
					if (node->_parent->_left == node)
						node->_parent->_left = nullptr;
					if (node->_parent->_right == node)
						node->_parent->_right = nullptr;
				}
				if (node == this->_root)
					this->_root = nullptr;
				delete_node(node);
			}
	};
}

#endif
