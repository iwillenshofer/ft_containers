/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:08 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/03 21:27:01 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "includes/ft_utilities.hpp"

namespace ft
{
  template <typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<const Key, T>									value_type;
		typedef Compare													key_compare;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;

	private:
		typedef typename ft::BinaryTree<Key, T, key_compare, allocator_type> binary_tree;

	public:
		typedef typename binary_tree::iterator							iterator;
		typedef typename binary_tree::const_iterator					const_iterator;
		typedef typename binary_tree::reverse_iterator	 				reverse_iterator;
		typedef typename binary_tree::const_reverse_iterator			const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t											size_type;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			protected:
				Compare comp;

			public:
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
				value_compare(Compare c): comp(c) { }
				bool operator()(const value_type& x, const value_type& y) const
				{ return (comp(x.first, y.first)); }
		};
	
	private:
		binary_tree _btree;

	public:
		/*
		** Constructors and destructor
		*/

		explicit map(const Compare& comp = key_compare(), const allocator_type& a = allocator_type())
		: _btree(comp, allocator_type(a)) { }

		template<typename InputIterator>
		map(InputIterator first, InputIterator last, const Compare& comp, const allocator_type& a = allocator_type())
		: _btree(comp, allocator_type(a))
		{ this->_btree.insert(first, last); }

		map(const map& x): _btree(x._btree) { }

		~map() { this->clear(); }

		map	&operator=(const map& x)
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
		** element access
		*/
		mapped_type &operator[](const key_type& k)
		{
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				i = insert(i, value_type(k, mapped_type()));
			return ((*i).second);
		}
	
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
		
		void swap(map& x) { this->_btree.swap(x._btree); }
		void clear() { this->_btree.clear(); }

		/*
		** observers
		*/
		key_compare key_comp() const { return (this->_btree.key_comp()); }
		value_compare value_comp() const { return (value_compare(this->_btree.key_comp())); }

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
		allocator_type getAllocator() const { return (allocator_type(this->_btree.getAllocator())); }

		template<typename _K1, typename _T1, typename _C1, typename _A1>
		friend bool operator==(const map<_K1, _T1, _C1, _A1>&, const map<_K1, _T1, _C1, _A1>&);

		template<typename _K1, typename _T1, typename _C1, typename _A1>
		friend bool operator<(const map<_K1, _T1, _C1, _A1>&, const map<_K1, _T1, _C1, _A1>&);
	};

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{ return (x._btree == y.t_btree); }

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{ return (x._btree < y._btree); }

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{ return (!(x == y)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{ return (y < x); }

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{ return (!(y < x)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{ return (!(x < y)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y)
	{ x.swap(y); }
}

#endif
