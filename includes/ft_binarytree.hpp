/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:56:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/05 17:56:27 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARYTREE_HPP
# define FT_BINARYTREE_HPP

# include "ft_binarytree_node.hpp"
# include "ft_binarytree_iterator.hpp"
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
			typedef ft::BinaryTreeIterator<T>										iterator;
			typedef ft::BinaryTreeIterator<const T>									const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef ft::Node<Key, T>												node;
			typedef node*															node_pointer;
			typedef node&															node_reference;
			typedef ft::pair<const Key, T>											value_type;
			typedef typename Alloc::template rebind<ft::Node<Key, T> >::other		allocator;
			typedef ft::pair<node_pointer, bool>									node_pointer_pair;

			BinaryTree(): _root(nullptr), _allocator(allocator()) { }
			BinaryTree(BinaryTree const &cp): _root(cp._root) { *this = cp; }
			BinaryTree &operator=(BinaryTree const &cp)
			{
				this->_allocator = cp._allocator;
				setRoot(cp._root);
			}
			virtual ~BinaryTree() {};

			node			_header; /* element before first element */
			node_pointer	_root; /* first element */
			allocator		_allocator;

			node_pointer_pair insert(value_type const &val) { return(this->insert(this->_root, val)); }

			node_pointer_pair insert(node_pointer node, value_type const &val)
			{
				node_pointer	parent = nullptr;
				bool			left_side = false;
				bool			compare = true;
				while (node)
				{
					parent = node;
					compare = Compare()(val.first, node->_value.first);
					if (compare == Compare()(node->_value.first, val.first))
						return(ft::make_pair(node, false));
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
					setRoot(node);
				return (ft::make_pair(node, true));
			}

			void setRoot(node_pointer node)
			{
				this->_root = node;
				this->_header._left = this->_root;
				if (this->_root)
					this->_root->_parent = &(this->_header);
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
				node_pointer suc = (*node).successor();
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
				if (p == this->_root)
					setRoot(nullptr);
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
				setRoot(nullptr);
			}

			void swapValue(node_pointer lhs, node_pointer rhs)
			{
				(*lhs).swapValue(rhs);
			}

			iterator begin() { return(iterator(this->_root->minimum())); }
			iterator end() { return(iterator(nullptr)); }


	};
}

#endif
