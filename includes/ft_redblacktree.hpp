/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redblacktree.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:13:20 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/03 17:33:03 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REDBLACKTREE_HPP
# define FT_REDBLACKTREE_HPP

# include "ft_redblacktree_iterator.hpp"

namespace ft
{
	/*
	** individual nodes for RbTree
	*/
	template <typename Val>
	class RbNode
	{
		public:
			typedef RbNode*			node_pointer;
			typedef const RbNode*	const_node_pointer;
			typedef RbNode<Val>*	link_type;

		public:
			RbColor			_color;
			node_pointer	_parent;
			node_pointer	_left;
			node_pointer	_right;
			Val				_value;

			RbNode(): _color(RbRed), _parent(0x0), _left(0x0), _right(0x0) {};
			RbNode(RbNode &cp) { *this = cp; };
			RbNode& operator=(const RbNode& cp)
			{
				this->_color = cp._color;
				this->_parent = cp._parent;
				this->_left = cp._left;
				this->_right = cp._right;
				return (*this);
			}
			virtual ~RbNode() {}
	};

	/*
	** RbTree
	*/
	template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc = std::allocator<Val> >
	class RbTree
	{
		private:
			typedef typename Alloc::template rebind<RbNode<Val> >::other node_allocator;
		
		protected:
			typedef	RbNode<Val>*			node_pointer;
			typedef	const RbNode<Val>*		const_node_pointer;

		public:
			typedef Key										key_type;
			typedef Val										value_type;
			typedef	value_type*								pointer;
			typedef value_type&								reference;
			typedef const value_type*						const_pointer;
			typedef const value_type&						const_reference;
			typedef RbNode<Val>*							link_type;
			typedef const RbNode<Val>*						const_link_type;
			typedef size_t									size_type;
			typedef ptrdiff_t								difference_type;
			typedef Alloc									allocator_type;
			typedef RedBlackTreeIterator<value_type>	 	iterator;
			typedef RedBlackTreeIterator<const value_type>	const_iterator;
			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			/*
			** RbTree implementation on top of node_allocator.
			*/
			template<typename KeyCompare>
			class RbTreeImpl : public node_allocator
			{
				public:
					KeyCompare      	key_compare;
					RbNode<Val>		    root;
					size_type			node_count;

					RbTreeImpl()
					: node_allocator(), key_compare(), root(), node_count(0)	{ initialize(); }

					RbTreeImpl(const KeyCompare &comp, const node_allocator& a)
					: node_allocator(a), key_compare(comp), root(), node_count(0) { initialize(); }
				
					RbTreeImpl(RbTreeImpl &cp) { *this = cp; };
				
					RbTreeImpl& operator=(const RbTreeImpl& cp)
					{
						this->root = cp.root;
						this->key_compare = cp.key_compare;
						this->node_count = cp.node_count;
						return (*this);
					}
					virtual ~RbTreeImpl() { }

				private:
					void initialize()
					{
						this->root._color = RbRed;
						this->root._parent = 0x0;
						this->root._left = &(this->root);
						this->root._right = &(this->root);
					}
			};

			RbTreeImpl<Compare> rb_tree;

		protected:
			node_pointer &Root() { return (this->rb_tree.root.parent); }
			node_pointer &LeftMost() { return (this->rb_tree.root.left); }
			node_pointer &RightMost() { return (this->rb_tree.root.right); }
			link_type Begin() { return static_cast<link_type>(&(this->rb_tree.root.parent)); }
			link_type End() { return static_cast<link_type>(&(this->rb_tree.root)); }
			link_type Left(node_pointer x) { return static_cast<link_type>(x->_left); }
			link_type Right(node_pointer x) { return static_cast<link_type>(x->_right); }

			static const_reference Value(const_link_type x)	{ return (x->_value); }
			static const key_type &S_Key(const_link_type x) { return (KeyOfValue()(Value(x))); }

		public:
			/*
			** Constructors & Destructors
			*/
			RbTree() { };
			RbTree(const Compare &comp, const allocator_type& a = allocator_type())
			: rb_tree(comp, a) { }
			RbTree(const RbTree& cp)
			: rb_tree(cp.rb_tree.key_compare, cp.getNodeAllocator())
			{
				if (this->Root())
				{
					
				}
			}

			node_allocator &getNodeAllocator() { return (*(static_cast<node_allocator*>(&(this->rb_tree)))); }
			allocator_type &getAllocator(){ return allocator_type(getNodeAllocator()); }
			link_type _create_node(value_type val)
			{
				link_type tmp;
				
				tmp = this->_node_allocator.allocate(1);
				this->_allocator.construct(&(tmp->_data), val);
				return (tmp);
			}

			template<typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc>
			iterator insert(const_node_pointer new_node, const_node_pointer parent, const _Val& val)
			{
				bool insert_left = (new_node || parent == this->End() || this->rb_tree.key_compare(_KeyOfValue()(val), this->S_Key(parent)));
				link_type _z = this->_create_node(val);
				insertAndRebalance(insert_left, _z, const_cast<node_pointer>(parent), this->rb_tree.root );
				this->rb_tree.node_count++;
				return (iterator(_z));
			}
			
			//template<typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc>
			ft::pair<iterator, bool> insertUnique (const value_type &val)
			{
				link_type x = this->Begin();
				link_type y = this->End();
				bool _comp = true;
				while (x)
				{
					y = x;
					_comp = rb_tree.key_compare(KeyOfValue()(val), this->S_Key(x));
					x = _comp ? Left(x) : Right(x);
				}
				iterator _j = iterator(y);
				if (_comp)
				{
					if (_j == this->Begin())
						return (ft::pair<iterator, bool>(insert(x, y, val), true));
					else
						_j--;
				}
				if (rb_tree.key_compare(S_Key(_j._p), KeyOfValue()(val)))
					return (ft::pair<iterator, bool>(insert(x, y, val), true));
				return (ft::pair<iterator, bool>(_j, false));
			}


			void insertAndRebalance(const bool insert_left, node_pointer new_node, node_pointer parent, RbNode<Val> header)
			{
				node_pointer root = header._parent;
				new_node->_parent = parent;
				if (insert_left)
				{
					parent->_left = new_node; // also makes leftmost = __x when __p == &__header
					if (parent == &header)
					{
						header._parent = new_node;
						header._right = new_node;
					}
					else if (parent == header._left)
					{
					header._left = new_node; // maintain leftmost pointing to min node
					}
				}
				else
				{
					parent->_right = new_node;
					if (parent == header._right)
						header._right = new_node; // maintain rightmost pointing to max node
				}	
			}	
	};

	template<typename _Key, typename _Val, typename _KeyOfValue,
           typename _Compare, typename _Alloc>
    inline bool
    operator==(const ft::RbTree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& __x,
           const ft::RbTree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& __y)
    {
      return __x.size() == __y.size()
         && ft::equal(__x.begin(), __x.end(), __y.begin());
    }
}

#endif
