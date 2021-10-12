/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:56:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/07 22:58:35 by iwillens         ###   ########.fr       */
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
			typedef ft::Node<Key, T>												node;
			typedef ft::BinaryTreeIterator<node>									iterator;
			typedef ft::BinaryTreeIterator<const node>								const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef node*															node_pointer;
			typedef node&															node_reference;
			typedef const node*														const_node_pointer;
			typedef const node&														const_node_reference;
			typedef ft::pair<const Key, T>											value_type;
			typedef typename Alloc::template rebind<ft::Node<Key, T> >::other		allocator;
			typedef Compare															key_compare;
			typedef size_t															size_type;
			typedef Key																key_type;
			typedef T																mapped_type;


			explicit BinaryTree(const key_compare& comp = key_compare(), const allocator& alloc = allocator())
			: _root(nullptr), _allocator(alloc), _compare(comp), _size(0) { }
			BinaryTree(BinaryTree const &cp): _root(nullptr), _allocator(cp._allocator), _compare(cp._compare), _size(0) { *this = cp; }

			BinaryTree &operator=(BinaryTree const &cp)
			{
				this->clear();
				this->_allocator = cp._allocator;
				this->_compare = cp._compare;
				this->insert(cp.begin(), cp.end());
				return (*this);
			}

			virtual ~BinaryTree() {};

			node			_header; /* element before first element */
			node_pointer	_root; /* first element */
			allocator		_allocator;
			Compare			_compare;
			size_type		_size;

			ft::pair<iterator, bool> insert(value_type const &val) { return(this->insert(this->_root, val)); }

			template<typename InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->insert(this->_root, *first);
					first++;
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
				node_pointer node = position.base();
				ft::pair<iterator, bool> ret;

				if (!(this->_root) || position == end() || !(_compare(node->minimum()->Key(), val.first)) || !(_compare(val.first, node->maximum()->Key())))
					node = this->_root;
				ret = insert(node, val);
				return(ret.first);
			}
	
			ft::pair<iterator, bool> insert(node_pointer node, value_type const &val)
			{
				node_pointer	parent = nullptr;
				bool			left_side = false;
				bool			compare = true;

				while (node && node != &(this->_header))
				{
					parent = node;
					compare = _compare(val.first, node->_value.first);
					if (compare == _compare(node->_value.first, val.first))
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
				balance(node);
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
				node_pointer child = node->_right ? node->_right : node->_left;
				node_pointer parent = node->_parent;

	//			std::cout << "SINGLE" << (node == this->_root) << std::endl << std::flush;
				parent->_right == node ? parent->_right = child : parent->_left = child;
				child->_parent = parent;
				if (node == this->_root)
					setRoot(child);
				delete_node(node);
				balance(child->_parent);
				return(child);
			}

			/* erases node if it has two children */
			/*
			** 1. finds the sucessor
			** 2. replaces itself with the successor.

			*/
			node_pointer _erase_twochildren(node_pointer nd)
			{	
				node_pointer pred = nd->_left->maximum();

	//			std::cout << "TWOCHILDREN" << std::endl << std::flush;
				nd->swapLinks(pred);
				if(pred->_left ==  pred) pred->_left = nd;
				if(pred->_right ==  pred) pred->_right = nd;
				if(pred->_parent->_right == nd ) pred->_parent->_right = pred;
				if(pred->_parent->_left == nd ) pred->_parent->_left = pred;
				if(nd->_parent->_right == pred)  nd->_parent->_right = nd;
				if(nd->_parent->_left == pred)  nd->_parent->_left = nd;
				if(pred->_right) pred->_right->_parent = pred;
				if(pred->_left) pred->_left->_parent = pred;
				if (nd == this->_root)
					setRoot(pred);
				_erase(nd);
				return(nd);
			}
			/* erases node if it has two children */
			node_pointer _erase_leaf(node_pointer node)
			{
				node_pointer parent = node->_parent;

//				std::cout << "LEAF" << std::endl << std::flush;
				parent->_right == node ? parent->_right = nullptr :	parent->_left = nullptr;
				delete_node(node);
				if (node == this->_root)
					setRoot(nullptr);
				balance(parent);
				return (nullptr);
			}

			void _erase(node_pointer node)
			{
				node_pointer new_node;

				if (!(node->_left) && !(node->_right))
					new_node = _erase_leaf(node);
				else if (node->_left && node->_right)
					new_node = _erase_twochildren(node);
				else
					new_node = _erase_singlechild(node);
			}


			void erase (iterator position) { this->_erase(position.base()); }
			size_type erase (const key_type& k)
			{ 
				iterator pos = this->find(k);
				if (pos != this->end())
				{
					erase(pos);
					return (1);
				}
				return (0);
			}
		
			void erase (iterator first, iterator last)
			{
				if (first == begin() && last == end())
					clear();
				else
					while (first != last)
						erase(first++);

			};

			iterator find (const key_type& k) { return (iterator(this->_find(k)));  }
			const_iterator find (const key_type& k) const { return (const_iterator(this->_find(k))); }

			node_pointer _find (const key_type& k) const
			{
				node_pointer node = this->_root;
				bool compare;

				while (node)
				{
					compare = _compare(k, node->_value.first);
					if (compare == _compare(node->_value.first, k))
						return (node);
					if (compare)
						node = node->_left;
					else
						node = node->_right;
				}
				return (node_pointer(&(this->_header)));
			}


			node_pointer create_node(value_type const &val)
			{
				node_pointer tmp = this->_allocator.allocate(1);
				this->_allocator.construct(tmp, value_type(val));
				this->_size++;
				return (tmp);
			}
	
			void		delete_node(node_pointer p)
			{
				this->_allocator.destroy(p);
				this->_allocator.deallocate(p, 1);
				this->_size--;
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

			size_type size() const { return (this->_size); }
			bool empty() const { return (this->_size == 0); }
			iterator begin()
			{ 
				if (!this->_size)
					return(end());
				return(iterator(this->_header.minimum()));
			}
			iterator end() { return(iterator(&this->_header)); }
			reverse_iterator rbegin() { return(reverse_iterator(this->end())); }
			reverse_iterator rend() { return(reverse_iterator(this->begin())); }
			const_iterator begin() const
			{
				if (!this->_size)
					return(end());
				return(const_iterator(this->_header.minimum()));
			}
			const_iterator end() const { return(const_iterator(&this->_header)); }
			const_reverse_iterator rbegin() const { return(const_reverse_iterator(this->end())); }
			const_reverse_iterator rend() const { return(const_reverse_iterator(this->begin())); }

			node_pointer successor(void) { return (successor(this)); }
			node_pointer successor(node_pointer node)
			{
				node_pointer parent = NULL;

				if (node && node->_right)
					return(minimum(node->_right));
				parent = node->_parent;
				while (node && parent != this->_header && node == parent->_right)
				{
					node = parent;
					parent = node->_parent;
				}
				return (parent);
			}
			node_pointer predecessor(void) { return (predecessor(this)); }
			node_pointer predecessor(node_pointer node)
			{
				node_pointer parent = NULL;

				if (node && node->_left)
					return(maximum(node->_left));
				parent = node->_parent;
				while (node && parent != this->_header && node == parent->_left)
				{
					node = parent;
					parent = node->_parent;
				}
				return (parent);
			}


			/*
			** binary tree rotation reference;
			** https://www.tutorialspoint.com/data_structures_algorithms/avl_tree_algorithm.htm
			*/

			void print_node(node_reference n)
			{
				std::cout << "Key: " << n.Key();
				std::cout << ". Value: " << n.Value();
				std::cout << ". Address: " << &n;
				std::cout << ". Left: " << (n._left ? n._left->Key() : 0);
				std::cout << ". Right: " << (n._right ? n._right->Key() : 0);
				std::cout << ". Parent: " << (n._parent ? n._parent->Key() : 0);
			std::cout <<  std::endl << std::flush;
			}

			void print_root()
			{
				for (iterator it = begin(); it != end(); it++)
					print_node(*(it.base()));
			}

			void	rotate_left(node_pointer x)
			{
				node_pointer root = x->_parent;;
				node_pointer y = x->_right;

				y->_parent = x->_parent;
				x->_right = y->_left;
				x->_parent = y;
				y->_left = x;
				if(x->_right)
					x->_right->_parent = x;
				if(x->_left)
					x->_left->_parent = x;
				if (root->_left == x)
					root->_left = y;
				else
					root->_right = y;
				if (this->_root == x)
					setRoot(y);
			}

			void	rotate_right(node_pointer x)
			{
				node_pointer root = x->_parent;;
				node_pointer y = x->_left;

				y->_parent = x->_parent;
				x->_left = y->_right;
				x->_parent = y;
				y->_right = x;
				if(x->_right)
						x->_right->_parent = x;
				if(x->_left)
						x->_left->_parent = x;
				if (root->_left == x)
					root->_left = y;
				else
					root->_right = y;
				if (this->_root == x)
					setRoot(y);
			}
			
			void	balance(node_pointer node)
			{
				if (node == &this->_header || (node == this->_root && node->balanced()))
					return ;
				if (!(node->balanced()))
				{
					if (node->_right->height() > node->_left->height())
					{
						// left rotation or right left rotation
						if (node->_right->_left && (!(node->_right->_right) || node->_right->_left->height() > node->_right->_right->height()))
							rotate_right(node->_right);
						rotate_left(node);
					}
					else
					{
						// right rotation or left right rotation.
						if (node->_left->_right && (!(node->_left->_left) || node->_left->_right->height() > node->_left->_left->height()))
							rotate_left(node->_left);
						rotate_right(node);
					}
				}
				balance(node->_parent);
			};

			ft::pair<iterator,iterator> equal_range( const key_type& key )
			{return (ft::make_pair(lower_bound(key), upper_bound(key))); }

			ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const
			{return (ft::make_pair(lower_bound(key), upper_bound(key))); }



			const_iterator lower_bound(const key_type& k) const
			{ 
				for (const_iterator ite = begin(); ite != end(); ++ite)
					if (_compare(k, ite->first) || k == ite->first)
						return ite;
				return end();
			} 

			iterator lower_bound(const key_type& k)
			{ 
				for (iterator ite = begin(); ite != end(); ++ite)
					if (_compare(k, ite->first) || k == ite->first)
						return ite;
				return end();
			}

			const_iterator upper_bound(const key_type& k) const
			{ 
				for (const_iterator ite = begin(); ite != end(); ++ite)
					if (_compare(k, ite->first))
						return ite;
				return end();
			}

			iterator upper_bound(const key_type& k)
			{ 
				for (iterator ite = begin(); ite != end(); ++ite)
					if (_compare(k, ite->first))
						return ite;
				return end();
			}
			/* element access */
			mapped_type &operator[](const key_type& k)
			{
				iterator i = this->lower_bound(k);

				if (i == end() || _compare(k, (*i).first))
					i = insert(i, value_type(k, mapped_type()));
				return ((*i).second);
			}

			void swap(BinaryTree& x)
			{
				BinaryTree tmp;
			
				tmp._root = x._root;
				tmp._allocator = x._allocator;
				tmp._compare = x._compare;
				tmp._size = x._size;
				x._root = this->_root;
				x._allocator = this->_allocator;
				x._compare = this->_compare;
				x._size = this->_size;
				this->_root = tmp._root;
				this->_allocator = tmp._allocator;
				this->_compare = tmp._compare;
				this->_size = tmp._size;
				if (this->_root)
					this->_root->_parent = &(this->_header);
				this->_header._left = this->_root;
				if (x._root)
					x._root->_parent = &(x._header);
				x._header._left = x._root;
			}

	};
}

#endif
