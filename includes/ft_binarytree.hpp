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
# include <iostream>
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

			BinaryTree(): _root(nullptr), _allocator(allocator()) {}
			BinaryTree(BinaryTree const &cp): _root(cp._root) { *this = cp; }
			BinaryTree &operator=(BinaryTree const &cp)
			{
				this->_allocator = cp._allocator;
				this->_root = cp._root;
			}
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
			/* erases node if it has two children */
			node_pointer _erase_singlechild(node_pointer node)
			{
				node_pointer child = node->_right? node->_right : node->_left;
		
				this->swapValue(node, child);
				node->_left = child->_left;
				node->_right = child->_right;
				if (node->_left)
					node->_left->_parent = node;
				if (node->_right)
					node->_right->_parent = node;
				delete_node(child);
				return(node);
			}

			/* erases node if it has two children */
			/*
			** 1. finds the sucessor
			** 2. replaces itself with the successor.

			*/
			node_pointer _erase_twochildren(node_pointer node)
			{
				std::cout << "twochildren\n";
				node_pointer suc = successor(node);
				if (suc->_parent && suc->_parent->_right == suc)
					suc->_parent->_right = nullptr;
				if (suc->_parent && suc->_parent->_left == suc)
					suc->_parent->_left = nullptr;
				if (suc->_right && suc->_parent)
					suc->_parent->_left = suc->_right;
				this->swapValue(node, suc);

				delete_node(suc);
				return(node);
			}
			/* erases node if it has two children */
			node_pointer _erase_leaf(node_pointer node)
			{
				node_pointer parent = node->_parent;

				if (parent && parent->_right == node)
					parent->_right = nullptr;
				if (parent && parent->_left == node)
					parent->_left = nullptr;
				delete_node(node);
				return (nullptr);
			}

			void erase(node_pointer node)
			{
				node_pointer new_node;
				if (!(node->_left) && !(node->_right))
					new_node = _erase_leaf(node);
				else if (node->_left && node->_right)
					new_node = _erase_twochildren(node);
				else
					new_node = _erase_singlechild(node);
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
				delete_node(node);
			}

			void swapValue(node_pointer lhs, node_pointer rhs)
			{
				(*lhs).swapValue(rhs);
			}

			node_pointer minimum(void) { return (minimum(this->_root)); }
			node_pointer minimum(node_pointer node)
			{
				while (node && node->_left)
					node = node->_left;
				return (node);
			}

			node_pointer maximum(void) { return (maximum(this->_root)); }
			node_pointer maximum(node_pointer node)
			{
				while (node && node->_right)
					node = node->_right;
				return (node);
			}

			node_pointer successor(node_pointer node)
			{
				node_pointer parent = nullptr;

				if (node && node->_right)
					return(minimum(node->_right));
				parent = node->_parent;
				while (node && node == parent->_right)
				{
					node = parent;
					parent = node->_parent;
				}
				return (parent);
			}
	
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
