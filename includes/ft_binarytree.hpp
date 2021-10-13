/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:56:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/13 15:47:10 by iwillens         ###   ########.fr       */
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


			/*
			** Constructors, destructor and assignment operator.
			*/

			explicit BinaryTree(const key_compare& comp = key_compare(), const allocator& alloc = allocator())
			: _root(NULL), _allocator(alloc), _compare(comp), _size(0) { }
			
			BinaryTree(BinaryTree const &cp): _root(NULL), _allocator(cp._allocator), _compare(cp._compare), _size(0) { *this = cp; }

			BinaryTree &operator=(BinaryTree const &cp)
			{
				this->clear();
				this->_allocator = cp._allocator;
				this->_compare = cp._compare;
				this->insert(cp.begin(), cp.end());
				return (*this);
			}

			virtual ~BinaryTree() {};


		private:
			/*
			** Helper internal methods and variables.
			** _header: element before first element. It's address is end()
			** _root: first element of the tree
			** The tree structure is as follows (n = NULL):
			**                        _header
			**                        /    \
			**              _root  [10]      n
			**                   /      \
			**                [5]        [15]
			**               /   \       /   \
			**             [1]    n   [14]   [16]
			**             /  \       /  \   /  \
			**            n    n     n    n n    n
			*/
			node			_header; 
			node_pointer	_root;
			allocator		_allocator;
			Compare			_compare;
			size_type		_size;

			/*
			** switches the root. Required as both _root and _header
			** are changed when the root is changed.
			*/
			void _setRoot(node_pointer node)
			{
				this->_root = node;
				this->_header._left = this->_root;
				if (this->_root)
					this->_root->_parent = &(this->_header);
			}

			/*
			** Insert helper function.
			** inserts an element if it does not exist.
			*/
			ft::pair<iterator, bool> _insert(node_pointer node, value_type const &val)
			{
				node_pointer	parent = NULL;
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
				node = this->_create_node(val);
				node->_parent = parent;
				if (parent)
					left_side ? parent->_left = node : parent->_right = node;
				if (!(this->_root))
					_setRoot(node);
				_balance(node);
				return (ft::make_pair(node, true));
			}

			/*
			** Erase Helper Functions
			** erases a single child.
			** 1. switches with its child and erases.
			*/
			void _erase_singlechild(node_pointer node)
			{
				node_pointer child = node->_right ? node->_right : node->_left;
				node_pointer parent = node->_parent;

				parent->_right == node ? parent->_right = child : parent->_left = child;
				child->_parent = parent;
				if (node == this->_root)
					_setRoot(child);
				_delete_node(node);
				_balance(child->_parent);
			}

			/*
			** erases node if it has two children
			** 1. finds the sucessor
			** 2. replaces itself with the successor.
			** 3. call erase function again to erase it as leaf or
			** single child node.
			*/
			void _erase_twochildren(node_pointer nd)
			{	
				node_pointer pred = nd->_left->maximum();

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
					_setRoot(pred);
				_erase(nd);
			}

			/*
			** erase leaf node.
			** 1. disconnect from parent and erase it. 
			*/
			void _erase_leaf(node_pointer node)
			{
				node_pointer parent = node->_parent;

				parent->_right == node ? parent->_right = NULL :	parent->_left = NULL;
				_delete_node(node);
				if (node == this->_root)
					_setRoot(NULL);
				_balance(parent);
			}

			void _erase(node_pointer node)
			{
				if (!(node->_left) && !(node->_right))
					_erase_leaf(node);
				else if (node->_left && node->_right)
					_erase_twochildren(node);
				else
					_erase_singlechild(node);
			}

			/*
			** find helper function. 
			*/
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

			/*
			** node helpers. Creates and deletes nodes.
			*/
			node_pointer _create_node(value_type const &val)
			{
				node_pointer tmp = this->_allocator.allocate(1);
				this->_allocator.construct(tmp, value_type(val));
				this->_size++;
				return (tmp);
			}
	
			void _delete_node(node_pointer p)
			{
				this->_allocator.destroy(p);
				this->_allocator.deallocate(p, 1);
				this->_size--;
				if (p == this->_root)
					_setRoot(NULL);
			}

			void _clear(node_pointer node)
			{
				if (!node)
					return;
				_clear(node->_left);
				_clear(node->_right);
				if (node->_parent)
				{
					if (node->_parent->_left == node)
						node->_parent->_left = NULL;
					if (node->_parent->_right == node)
						node->_parent->_right = NULL;
				}
				_delete_node(node);
				_setRoot(NULL);
			}

			/*
			** Binary tree rotation mathods
			*/

			void _rotate_left(node_pointer x)
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
					_setRoot(y);
			}

			void _rotate_right(node_pointer x)
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
					_setRoot(y);
			}
			
			void _balance(node_pointer node)
			{
				if (node == &this->_header || (node == this->_root && node->balanced()))
					return ;
				if (!(node->balanced()))
				{
					if (node->_right->height() > node->_left->height())
					{
						if (node->_right->_left && (!(node->_right->_right)
							|| node->_right->_left->height() > node->_right->_right->height()))
							_rotate_right(node->_right);
						_rotate_left(node);
					}
					else
					{
						if (node->_left->_right && (!(node->_left->_left)
							|| node->_left->_right->height() > node->_left->_left->height()))
							_rotate_left(node->_left);
						_rotate_right(node);
					}
				}
				_balance(node->_parent);
			}


		public:

			/*
			** Iterators
			*/

			iterator begin()
			{ 
				if (!(this->_size))
					return(end());
				return(iterator(this->_header.minimum()));
			}
			iterator end() { return(iterator(&(this->_header))); }
			reverse_iterator rbegin() { return(reverse_iterator(this->end())); }
			reverse_iterator rend() { return(reverse_iterator(this->begin())); }
			const_iterator begin() const
			{
				if (!this->_size)
					return(end());
				return(const_iterator(this->_header.minimum()));
			}
			const_iterator end() const { return(const_iterator(&(this->_header))); }
			const_reverse_iterator rbegin() const { return(const_reverse_iterator(this->end())); }
			const_reverse_iterator rend() const { return(const_reverse_iterator(this->begin())); }


			/*
			** Capacity
			*/

			bool empty() const { return (this->_size == 0); }
			size_type size() const { return (this->_size); }
			size_type		max_size() const { return (this->_allocator.max_size()); }

			/*
			** element access
			*/
			mapped_type &operator[](const key_type& k)
			{
				iterator i = lower_bound(k);

				if (i == end() || _compare(k, (*i).first))
					i = insert(i, value_type(k, mapped_type()));
				return ((*i).second);
			}

			/*
			** Modifiers
			*/

			ft::pair<iterator, bool> insert(value_type const &val) { return(this->_insert(this->_root, val)); }
			template<typename InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->_insert(this->_root, *first);
					first++;
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
				node_pointer node = position.base();
				ft::pair<iterator, bool> ret;

				if (!(this->_root) || position == end() || !(_compare(node->minimum()->Key(), val.first))
					|| !(_compare(val.first, node->maximum()->Key())))
					node = this->_root;
				ret = _insert(node, val);
				return(ret.first);
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

			void clear() { this->_clear(this->_root); }

			/*
			** observers
			*/

			key_compare key_comp() const { return (this->_compare); }

			/*
			** operations
			*/

			iterator find (const key_type& k) { return (iterator(this->_find(k)));  }
			const_iterator find (const key_type& k) const { return (const_iterator(this->_find(k))); }

			size_type count(const key_type& k) { return(find(k) == end() ? 0 : 1); }

			ft::pair<iterator,iterator> equal_range( const key_type& key )
			{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const
			{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}

			const_iterator lower_bound(const key_type& k) const
			{ 
				for (const_iterator ite = begin(); ite != end(); ++ite)
					if (_compare(ite->first, k) == false)
						return ite;
				return end();
			} 
			
			iterator lower_bound(const key_type& k)
			{ 
				for (iterator ite = begin(); ite != end(); ++ite)
					if (_compare(ite->first, k) == false)
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
	};
}

#endif
