/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:34:42 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 11:30:22 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR
# define FT_REVERSE_ITERATOR

# include "ft_iterators.hpp"
# include "ft_type_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator : public iterator <typename iterator_traits<Iterator>::iterator_category,
												typename iterator_traits<Iterator>::value_type,
												typename iterator_traits<Iterator>::difference_type,
												typename iterator_traits<Iterator>::pointer,
												typename iterator_traits<Iterator>::reference>
	{
		protected:
			Iterator _current_iterator;
			typedef ft::iterator_traits<Iterator>								_traits_type;
			typedef typename ft::reverse_iterator<Iterator>						_self;

		public: 
			typedef	Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			
			reverse_iterator(): _current_iterator(iterator_type()) { }
			explicit reverse_iterator (iterator_type it): _current_iterator(it) { }
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter> &rev_it): _current_iterator(rev_it.base())	{ }
			virtual ~reverse_iterator () {};			
			iterator_type base() const { return (this->_current_iterator); }
			reference operator*() const	{ return (*(this->_current_iterator - 1)); }
			pointer operator->() const	{ return (&(*(this->_current_iterator - 1))); }
			reverse_iterator &operator++()
			{
				this->_current_iterator--;
				return *this;
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;

				this->_current_iterator--;
				return tmp;
			}
			reverse_iterator &operator--()
			{
				this->_current_iterator++;
				return *this;
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				this->_current_iterator++;
				return tmp;
			}
			reverse_iterator operator+(difference_type n) const { return (reverse_iterator(this->_current_iterator - n)); }
			reverse_iterator &operator+=(difference_type n)
			{ 
				this->_current_iterator -= n;
				return (*this);
			}
			reverse_iterator operator-(difference_type n) const { return (reverse_iterator(this->_current_iterator + n)); }
			reverse_iterator &operator-=(difference_type n)
			{ 
				this->_current_iterator += n;
				return (*this);
			}
			reference operator[](difference_type n) const { return (this->_current_iterator[-n - 1]); }
	};

	template<typename Iterator>
	bool	operator==(const ft::reverse_iterator<Iterator>& x, const ft::reverse_iterator<Iterator> &y) { return x.base() == y.base(); }

	template<typename Iterator>
	bool	operator<(const ft::reverse_iterator<Iterator>& x, const ft::reverse_iterator<Iterator> &y) { return y.base() < x.base(); }

	template<typename Iterator>
	bool	operator!=(const ft::reverse_iterator<Iterator>& x, const ft::reverse_iterator<Iterator> &y) { return !(x == y); }

	template<typename Iterator>
	bool	operator>(const ft::reverse_iterator<Iterator>& x, const ft::reverse_iterator<Iterator> &y) { return y < x; }

	template<typename Iterator>
	bool	operator<=(const ft::reverse_iterator<Iterator>& x, const ft::reverse_iterator<Iterator> &y) { return !(y < x); }

	template<typename Iterator>
	bool	operator>=(const ft::reverse_iterator<Iterator>& x, const ft::reverse_iterator<Iterator> &y) { return !(x < y); }

	template<typename _Iterator>
	typename ft::reverse_iterator<_Iterator>::difference_type operator-(const ft::reverse_iterator<_Iterator> &x,
		const ft::reverse_iterator<_Iterator>& y)
	{ return y.base() - x.base(); }

	template<typename _Iterator>
	ft::reverse_iterator<_Iterator> operator+(typename ft::reverse_iterator<_Iterator>::difference_type n,
		const ft::reverse_iterator<_Iterator>& x)
	{ return reverse_iterator<_Iterator>(x.base() - n); }

	/*
	** RevIterators vs ConstRevIterators
	*/

	template<typename IteratorL, typename IteratorR>
	bool	operator==(const ft::reverse_iterator<IteratorL>& x, const ft::reverse_iterator<IteratorR>& y) { return x.base() == y.base(); }

	template<typename IteratorL, typename IteratorR>
	bool	operator<(const ft::reverse_iterator<IteratorL>& x, const ft::reverse_iterator<IteratorR>& y) { return y.base() < x.base(); }

	template<typename IteratorL, typename IteratorR>
	bool	operator!=(const ft::reverse_iterator<IteratorL>& x, const ft::reverse_iterator<IteratorR>& y) { return !(x == y); }

	template<typename IteratorL, typename IteratorR>
	bool	operator>(const ft::reverse_iterator<IteratorL>& x, const ft::reverse_iterator<IteratorR>& y) { return y < x; }

	template<typename IteratorL, typename IteratorR>
	bool	operator<=(const ft::reverse_iterator<IteratorL>& x, const ft::reverse_iterator<IteratorR>& y) { return !(y < x); }

	template<typename IteratorL, typename IteratorR>
	bool	operator>=(const ft::reverse_iterator<IteratorL>& x, const ft::reverse_iterator<IteratorR>& y) { return !(x < y); }

}

#endif
