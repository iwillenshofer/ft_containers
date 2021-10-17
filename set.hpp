/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:08 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 22:24:21 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <memory>
# include "includes/ft_algorithm.hpp"
# include "includes/ft_redblacktree.hpp"

namespace ft
{
	/*
	** Reference for the Set container:
	** https://cplusplus.com/reference/set/set/
	*/
	template< typename Key, typename Compare = std::less<Key>, typename Alloc = std::allocator<Key> >
	class set
	{
	public:
		typedef Key														key_type;
		typedef Key														value_type;
		typedef size_t													size_type;
		typedef Compare													key_compare;
		typedef Compare													value_compare;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;

	private:
		typedef typename ft::RedBlackTree<Key, Key, ft::Identity<Key>, Compare, Alloc>							binary_tree;

	public:
		typedef typename binary_tree::iterator							iterator;
		typedef typename binary_tree::const_iterator					const_iterator;
		typedef typename binary_tree::reverse_iterator	 				reverse_iterator;
		typedef typename binary_tree::const_reverse_iterator			const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	
	private:
		binary_tree _btree;

	public:
		/*
		** Constructors and destructor
		*/

		explicit set(const Compare& comp = key_compare(), const allocator_type& a = allocator_type())
		: _btree(comp, allocator_type(a)) { }

		template<typename InputIterator>
		set(InputIterator first, InputIterator last, const Compare& comp = key_compare(), const allocator_type& a = allocator_type())
		: _btree(comp, allocator_type(a))
		{ this->_btree.insert(first, last); }

		set(const set& x): _btree(x._btree) { }

		~set() { this->clear(); }

		set	&operator=(const set& x)
		{
			this->_btree = x._btree;
			return (*this);
		}

		/*
		** iterators
		*/
		iterator begin() { return (this->_btree.begin()); }
		const_iterator begin() const { return (this->_btree.begin()); }
		iterator end() { return (this->_btree.end()); }
		const_iterator end() const { return (this->_btree.end()); }
		reverse_iterator rbegin() { return (this->_btree.rbegin()); }
		const_reverse_iterator rbegin() const { return (this->_btree.rbegin()); }
		reverse_iterator rend() { return (this->_btree.rend()); }
		const_reverse_iterator rend() const { return (this->_btree.rend()); }

		/*
		** capacity
		*/
		bool empty() const { return (this->_btree.empty()); }
		size_type size() const { return (this->_btree.size()); }
		size_type max_size() const { return (this->_btree.max_size()); }

		/*
		** modifiers
		*/
		ft::pair<iterator, bool> insert(const value_type& val) { return (this->_btree.insert(val)); }

		iterator insert(iterator position, const value_type& val) { return (this->_btree.insert(position, val)); }

		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last) { this->_btree.insert(first, last); }

		void erase(iterator position) { this->_btree.erase(position); }
		size_type erase(const key_type& k) { return (this->_btree.erase(k)); }
		void erase(iterator first, iterator last) { this->_btree.erase(first, last); }
		
		void swap(set& x) { this->_btree.swap(x._btree); }
		void clear() { this->_btree.clear(); }

		/*
		** observers
		*/
		key_compare key_comp() const { return (this->_btree.key_comp()); }
		value_compare value_comp() const { return (this->_btree.key_comp()); }

		/*
		** operations
		*/
		iterator find(const key_type& x) { return (this->_btree.find(x)); }
		const_iterator find(const key_type& x) const { return (this->_btree.find(x)); }

		size_type count(const key_type& x) const { return (this->_btree.find(x) == this->_btree.end() ? 0 : 1); }

		iterator lower_bound(const key_type& x) { return (this->_btree.lower_bound(x)); }
		const_iterator lower_bound(const key_type& x) const { return (this->_btree.lower_bound(x)); }

		iterator upper_bound(const key_type& x) { return (this->_btree.upper_bound(x)); }
		const_iterator upper_bound(const key_type& x) const { return (this->_btree.upper_bound(x)); }

		ft::pair<iterator, iterator> equal_range(const key_type& x) { return (this->_btree.equal_range(x)); }
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& x) const { return (this->_btree.equal_range(x)); }

		/*
		** allocator
		*/
		allocator_type get_allocator() const { return (allocator_type(this->_btree.get_allocator())); }

	};

	template<typename Key, typename Compare, typename Alloc>
	bool operator==(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y)
	{ return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin())); }

	template<typename Key, typename Compare, typename Alloc>
	bool operator<(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y)
	{ return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end())); }

	template<typename Key, typename Compare, typename Alloc>
	bool operator!=(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y)
	{ return (!(x == y)); }

	template<typename Key, typename Compare, typename Alloc>
	bool operator>(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y)
	{ return (y < x); }

	template<typename Key, typename Compare, typename Alloc>
	bool operator<=(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y)
	{ return (!(y < x)); }

	template<typename Key, typename Compare, typename Alloc>
	bool operator>=(const set<Key, Compare, Alloc>& x, const set<Key, Compare, Alloc>& y)
	{ return (!(x < y)); }

	template<typename Key, typename Compare, typename Alloc>
	void swap(set<Key, Compare, Alloc>& x, set<Key, Compare, Alloc>& y)
	{ x.swap(y); }
}

#endif
