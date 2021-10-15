/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redblacktree.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:56:10 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/15 17:21:35 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REDBLACKTREE_HPP
# define FT_REDBLACKTREE_HPP

# include "ft_iterators.hpp"
# include "ft_iterator_traits.hpp"
# include "ft_reverse_iterator.hpp"
# include "ft_utilities.hpp"

# include <memory>
# include <iostream>
# include <algorithm>

# define RBT_RED 1
# define RBT_BLACK 2

namespace ft
{

	/*
	** Node for Red Black Tree.
	*/

	template <typename K, typename T>
	class Node
	{
		public:
			typedef ft::pair<K, T>					value_type;
			typedef value_type&						reference;
			typedef value_type*						pointer;
			typedef ptrdiff_t						difference_type;
			typedef const ft::pair<K, T>			const_value_type;
			typedef Node<K, T>*						node_pointer;
			typedef Node<K, T>&						node_reference;
			typedef const Node<K, T>*				const_node_pointer;
			typedef const K&						key_reference;
			typedef T&								value_reference;
			typedef const T&						const_value_reference;
			typedef Node<K, T>						_Self;
			typedef const Node<K, T>				const_self;
			typedef std::size_t						size_type;

			Node(void) {}
			value_type		_value;
			node_pointer	_parent;
			node_pointer	_left;
			node_pointer	_right;
			char			_color;

		public:
			Node(value_type const &val): _value(value_type(val)), _left(0x0), _right(0x0), _color(RBT_RED) {}
			Node(Node const &cp) { *this = cp; }
			Node& operator=(const Node& cp)
			{
				this->_left = cp._left;
				this->_right = cp._right;
				this->_parent = cp._parent;
				this->_value = cp._value;
				this->_color = cp._color;
				return (*this);
			}
			virtual ~Node() {}

			value_type &Pair(void) { return (this->_value); }
			const_value_type &Pair(void) const { return (this->_value); }

			key_reference Key(void) const { return (this->_value.first); }

			value_reference Value(void) { return (this->_value.second); }
			const_value_reference Value(void) const { return (this->_value.second); }

			char &Color(void) { return (this->_color); }
			const char &Color(void) const { return (this->_color); }

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

			void swapColor(node_pointer node)
			{
				char tmp = node->_color;

				node->_color = this->_color;
				this->_color = tmp;
			}

			void swapLinks(node_pointer nd)
			{
				_Self tmp;
				tmp._parent = nd->_parent;
				tmp._left = nd->_left;
				tmp._right = nd->_right;
				nd->_parent = this->_parent;
				nd->_left = this->_left;
				nd->_right = this->_right;
				this->_parent = tmp._parent;
				this->_left = tmp._left;
				this->_right = tmp._right;
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

			node_pointer successor(void) { return const_cast<node_pointer>(successor(this)); }
			const_node_pointer successor(void) const { return (successor(this)); }
			const_node_pointer successor(const_node_pointer node) const
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
				size_type left = node->_left ? height(node->_left) : 0;
				size_type right = node->_right ? height(node->_right) : 0;
				size_type diff = left > right ? left - right : right - left;

				return (diff <= 1);
			}

			/*
			** RedBlack Tree family getters
			*/
			node_pointer Parent(void) { return (this->_parent); }
			node_pointer GrandParent(void) { return (this->_parent->_parent); }
			node_pointer Uncle(void) { return (Parent()->Sibling()); }
			node_pointer Sibling(void)
			{
				if (!(Parent()))
					return (NULL);
				if (Parent()->_right == this)
					return(Parent()->_left);
				return(Parent()->_right);
			}

			node_pointer Nephew(void)
			{
				if (!(Sibling()))
					return (NULL);
				if (Sibling() == Parent()->_left)
					return(Sibling()->_left);
				return(Sibling()->_right);
			}
		
			node_pointer Niece(void)
			{
				if (!(Sibling()))
					return (NULL);
				if (Sibling() == Parent()->_right)
					return(Sibling()->_left);
				return(Sibling()->_right);
			}

			bool isLeftChild(void)
			{
				if (this == Parent()->_left)
					return (true);
				return(false);
			}
			
			bool isRightChild(void)
			{
				if (this == Parent()->_right)
					return (true);
				return(false);
			}
	};

	/*
	** Iterator for BlackRedTree and Map.
	*/

	template <typename T>
	class RedBlackTreeIterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
		
			typedef typename ft::bidirectional_iterator_tag	iterator_category;
			typedef typename T::value_type					value_type;
			typedef typename T::difference_type				difference_type;
			typedef typename T::pointer						pointer;
			typedef typename T::reference					reference;
		
		private:
			typedef typename ft::RedBlackTreeIterator<T>									_self;
			typedef typename ft::RedBlackTreeIterator<const T>							const_self;
			typedef	T*																	node_pointer;
		protected:
			node_pointer	_p;
	
		public:
			RedBlackTreeIterator(): _p() { };
			explicit RedBlackTreeIterator(node_pointer const p): _p(p) { };
			RedBlackTreeIterator(RedBlackTreeIterator const &b): _p(b._p) { };
			virtual ~RedBlackTreeIterator() {}

			operator const_self() const { return const_self(this->_p); }
			node_pointer	base() const { return this->_p; }
			RedBlackTreeIterator &operator=(RedBlackTreeIterator const &b)
			{
				this->_p = b._p;
				return (*this);
			}

			typename T::value_type &operator*() { return (const_cast<typename T::value_type&>(this->_p->Pair())); }
			typename T::value_type *operator->() { return (const_cast<typename T::value_type*>(&(this->_p->Pair()))); }

			RedBlackTreeIterator	operator+(difference_type const &n) const { return (_self(this->_p + n)); }
			RedBlackTreeIterator	operator-(difference_type const &n) const
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


			RedBlackTreeIterator &operator++() { this->_p = this->_p->successor(); return (*this); }
			RedBlackTreeIterator &operator--() { this->_p = this->_p->predecessor(); return (*this);}

			RedBlackTreeIterator operator++(int)
			{
				_self tmp(*this);

				this->_p = this->_p->successor();
				return (tmp); 
			}

			RedBlackTreeIterator operator--(int)
			{
				_self tmp(*this);

				this->_p = this->_p->predecessor();
				return (tmp); 
			}

			bool operator==(const _self &x) const { return (this->_p == x.base()); }
			bool operator!=(const _self &x) const { return (this->_p != x.base()); }
	};

	template<typename Val>
	inline bool	operator==(const RedBlackTreeIterator<Val>& x,	const RedBlackTreeIterator<Val>& y)
	{ return x._p == y._p; }

	template<typename Val>
	inline bool	operator!=(const RedBlackTreeIterator<Val>& x,	const RedBlackTreeIterator<Val>& y)
	{ return x._p != y._p; }

	/*
	** Blackred tree structure for ft::map.
	*/

	template <typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class RedBlackTree
	{
		public:
			typedef ft::Node<Key, T>												node;
			typedef ft::RedBlackTreeIterator<node>									iterator;
			typedef ft::RedBlackTreeIterator<const node>							const_iterator;
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

			explicit RedBlackTree(const key_compare& comp = key_compare(), const allocator& alloc = allocator())
			: _root(NULL), _allocator(alloc), _compare(comp), _size(0) { }
			
			RedBlackTree(RedBlackTree const &cp): _root(NULL), _allocator(cp._allocator), _compare(cp._compare), _size(0) { *this = cp; }

			RedBlackTree &operator=(RedBlackTree const &cp)
			{
				this->clear();
				this->_allocator = cp._allocator;
				this->_compare = cp._compare;
				this->insert(cp.begin(), cp.end());
				return (*this);
			}

			virtual ~RedBlackTree() {};


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
			void _setRoot(node_pointer node, bool set_color = true)
			{
				this->_root = node;
				this->_header._left = this->_root;
				if (this->_root)
				{
					this->_root->_parent = &(this->_header);
					if (set_color)
						this->_root->_color = RBT_BLACK;
				}
			}

			/*
			** color operations. Provide a safe way to get and set color, 
			** since leaf nodes have null children and null colr is black.
			*/
			char _getColor(node_pointer node)
			{
				if (!node)
					return (RBT_BLACK);
				return(node->_color);
			}

			void _setColor(node_pointer node, char color)
			{
				if (!node)
					return ;
				node->_color = color;
			}

			void _swapColor(node_pointer node1, node_pointer node2)
			{
				char tmp = _getColor(node1);

				_setColor(node1, _getColor(node2));
				_setColor(node2, tmp);
			}
	
			/*
			** node helpers. Creates and deletes nodes.
			*/
			node_pointer _create_node(value_type const &val)
			{
				node_pointer tmp = this->_allocator.allocate(1);
				this->_allocator.construct(tmp, node(value_type(val)));
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
			** RedBlack tree rotation mathods, used to help balancing
			** the tree after insertion or deletion.
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
				node->_color = RBT_RED;
				node->_parent = parent;
				if (parent)
					left_side ? parent->_left = node : parent->_right = node;
				else
					_setRoot(node);
				if (node != _root && node->GrandParent() != &(this->_header)) 
					_redblack_insertionbalance(node);
				return (ft::make_pair(node, true));
			}
			
			/*
			** Insertion balance function.
			** Rotates and recolors nodes to keep RedBlackTree valid.
			*/
			void _redblack_insertionbalance(node_pointer node)
			{
				node_pointer u;

				while (node->_parent->_color== RBT_RED)
				{
					u = node->Uncle();
					if (_getColor(u) == RBT_RED)
					{
						_setColor(u, RBT_BLACK);
						_setColor(node->Parent(), RBT_BLACK);
						_setColor(node->GrandParent(), RBT_RED);
						node = node->GrandParent();
					}
					else
					{
						if (node->isLeftChild())
						{
							node = node->Parent();
							_rotate_right(node);
						}
						else if (node->isRightChild())
						{
							node = node->Parent();
							_rotate_left(node);
						}
						_setColor(node->Parent(), RBT_BLACK);
						_setColor(node->GrandParent(), RBT_RED);
						if (node->_parent->isRightChild())
							_rotate_left(node->GrandParent());
						else
							_rotate_right(node->GrandParent());
					}
					if (node == _root)
						break ;
				}
				_setColor(_root, RBT_BLACK);
			}


			/*
			** A node to be erased can have two children, one child or be a leaf node.
			*/
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
			** Two children:
			** 1. finds the sucessor
			** 2. replaces itself with the successor.
			** 3. call erase function again to erase it as leaf or
			** single child node.
			*/
			void _erase_twochildren(node_pointer node)
			{	
				node_pointer pred = node->_right->minimum();

				node->swapLinks(pred);
 				if(pred->_left ==  pred) pred->_left = node;
 				if(pred->_right ==  pred) pred->_right = node;
 				if(pred->_parent->_right == node ) pred->_parent->_right = pred;
 				if(pred->_parent->_left == node ) pred->_parent->_left = pred;
 				if(node->_parent->_right == pred)  node->_parent->_right = node;
 				if(node->_parent->_left == pred)  node->_parent->_left = node;
 				if(pred->_right) pred->_right->_parent = pred;
 				if(pred->_left) pred->_left->_parent = pred;
				_swapColor(node, pred);
				if (node == this->_root)
					_setRoot(pred);
				_erase(node);
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
				char original_color = _getColor(node);

				parent->_right == node ? parent->_right = child : parent->_left = child;
				child->_parent = parent;
				if (node == this->_root)
					_setRoot(child, false);
				_redblack_deletionbalance(child->_parent, child, original_color);
				_delete_node(node);
			}

			/*
			** erase leaf node.
			** 1. disconnect from parent and erase it. 
			*/
			void _erase_leaf(node_pointer node)
			{
				node_pointer parent = node->_parent;
				char original_color = _getColor(node);
				parent->_right == node ? parent->_right = NULL : parent->_left = NULL;
				if (node == this->_root)
					_setRoot(NULL, false);
				_redblack_deletionbalance(node->_parent, NULL, original_color);
				_delete_node(node);
			}


			/*
			** Rebalance tree after deletion.
			** 1. if the node we deleted is red and its replacement is red or null, do nothing.
			** 2. if the node we deleted is red and its replacement is black, color the replacement red and treat special case.
			** 3. if the node we deleted is black and its replacement is red, color the replacement black, do nothing.
			** 4. if the node we deleted is black and its replacement is null or black, treat special case.
			*/
			void _redblack_deletionbalance(node_pointer parent, node_pointer replacement, char deleted_color)
			{
				if (deleted_color == RBT_RED && (!replacement || _getColor(replacement) == RBT_RED))
					return ;
				else if (deleted_color == RBT_RED && (replacement && _getColor(replacement) == RBT_BLACK))
				{
					_setColor(replacement, RBT_RED);
					_redblack_deletion_specialcases(parent, replacement);
				}
				else if (deleted_color == RBT_BLACK && (replacement && _getColor(replacement) == RBT_RED))
				{
					_setColor(replacement, RBT_BLACK);
					return ;
				}
				else if (deleted_color == RBT_BLACK && _getColor(replacement) == RBT_BLACK)
					_redblack_deletion_specialcases(parent, replacement);
			}

			/*
			** Special Cases (x = replacement, w = sibling):
			** 0. Node x is red.
			** 1. Node x is black & its sibling is red.
			** 2. Node x is black & its sibling is black & both siblings children are black.
			** 3. Node x is black & its sibling w is black && 
			**   3.1 x = left child, w->_left is red, w->_right is black.
			**   3.2 x = right child, w->_right is red, w->_left is black.
			** 4. Node x is black & its sibling w is black && 
			**   4.1 x = left child, w->_right is red.
			**   4.2 x = right child, w->_left is red.
			*/
			void _redblack_deletion_specialcases(node_pointer parent, node_pointer x)
			{
				node_pointer w = parent->_left == x ? parent->_right : parent->_left;

				if (x == _root || _getColor(x) == RBT_RED)
				{
					_setColor(x, RBT_BLACK);
					return;
				}
				if (_getColor(x) == RBT_BLACK && _getColor(w) == RBT_RED)
				{
					_setColor(w, RBT_BLACK);
					_setColor(parent, RBT_RED);
					if (x == parent->_left)
					{
						_rotate_left(parent);
						w = parent->_right;
					}
					else
					{
						_rotate_right(parent);
						w = parent->_left;
					}
				}
				if (_getColor(x) == RBT_BLACK && _getColor(w) == RBT_BLACK
				&& _getColor(w->_left) == RBT_BLACK && _getColor(w->_right) == RBT_BLACK)
				{
					_setColor(w, RBT_RED);
					x = parent;
					if (_getColor(x) == RBT_RED)
						_setColor(x, RBT_BLACK);
					else
						_redblack_deletion_specialcases(x->_parent, x);
					return ;

				}
				if ((_getColor(x) == RBT_BLACK && _getColor(w) == RBT_BLACK)
				&& ((x == parent->_left && _getColor(w->_left) == RBT_RED && _getColor(w->_right) == RBT_BLACK)
				|| (x == parent->_right && _getColor(w->_right) == RBT_RED && _getColor(w->_left) == RBT_BLACK)))
				{
					_setColor(w, RBT_RED);
					if (x == parent->_left)
					{
						_setColor(w->_left, RBT_BLACK);
						_rotate_right(w);
						w = parent->_right;
					}
					else if (x == parent->_right)
					{
						_setColor(w->_right, RBT_BLACK);
						_rotate_left(w);
						w = parent->_left;
					}
				}
				if ((_getColor(x) == RBT_BLACK && _getColor(w) == RBT_BLACK)
				&& ((x == parent->_left && _getColor(w->_right) == RBT_RED)
				|| (x == parent->_right && _getColor(w->_left) == RBT_RED)))
				{
					_setColor(w, _getColor(parent));
					_setColor(parent, RBT_BLACK);
					if (x == parent->_left)
					{
						_setColor(w->_right, RBT_BLACK);
						_rotate_left(parent);
					}
					else if (x == parent->_right)
					{
						_setColor(w->_left, RBT_BLACK);
						_rotate_right(parent);
					}
				}
			}

		public:

			/*
			** Iterators
			*/

			iterator begin() {return (size() ? iterator(this->_header.minimum()) : end()); }
			iterator end() { return(iterator(&(this->_header))); }
			reverse_iterator rbegin() { return(reverse_iterator(this->end())); }
			reverse_iterator rend() { return(reverse_iterator(this->begin())); }
			const_iterator begin() const {return (size() ? const_iterator(this->_header.minimum()) : end()); }
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

			void swap(RedBlackTree& x)
			{
				RedBlackTree tmp;
			
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
