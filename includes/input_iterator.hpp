/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:52:15 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/29 15:58:15 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_ITERATOR_HPP
# define INPUT_ITERATOR_HPP

# include "iterators.hpp"

namespace ft
{
	template <typename T>
	class BidirectionalIterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;
		
		private:
			typedef typename ft::BidirectionalIterator<const value_type>						const_self;

		public:
			BidirectionalIterator(): _p(0x0) { };
			BidirectionalIterator(pointer p): _p(p) { };
			BidirectionalIterator(const BidirectionalIterator &b) { *this = b; };
			virtual ~BidirectionalIterator() { }
			operator const_self() const { return const_self(this->_p); }
			BidirectionalIterator &operator=(BidirectionalIterator const &b)
			{
				this->_p = b._p;
				return (*this);
			}
			bool operator==(BidirectionalIterator const &b) { return (this->_p == b._p); }
			bool operator!=(BidirectionalIterator const &b) { return (this->_p != b._p); }
			reference operator*() { return *(this->_p); }
			pointer operator->() { return (&(this->_p)); }
			BidirectionalIterator &operator++()
			{ 
				this->_p++;
				return (*this); 
			}
			
			BidirectionalIterator &operator--()
			{ 
				this->_p--;
				return (*this); 
			}

			BidirectionalIterator operator++(int)
			{
				BidirectionalIterator tmp(*this);

				this->_p++;
				return (tmp); 
			}

			BidirectionalIterator operator--(int)
			{
				BidirectionalIterator tmp(*this);

				this->_p--;
				return (tmp); 
			}

		protected:
			pointer	_p;
	};

	template <typename T>
	class RandomAccessIterator : public ft::BidirectionalIterator<T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
		
		private:
			typedef typename ft::BidirectionalIterator<T>										base_class;
			typedef typename ft::RandomAccessIterator<const value_type>							const_self;
			typedef typename ft::RandomAccessIterator<value_type>								_self;

		public:
			RandomAccessIterator(): base_class() { };
			RandomAccessIterator(pointer p): base_class(p) { };
			RandomAccessIterator(RandomAccessIterator const &b): base_class(b) { };
			virtual ~RandomAccessIterator() {}
			operator const_self() const { return const_self(this->_p); }

			RandomAccessIterator &operator=(RandomAccessIterator const &b)
			{
				this->_p = b._p;
				return (*this);
			}
			RandomAccessIterator	operator+(difference_type const &n) const { return (_self(this->_p + n)); }
			RandomAccessIterator	operator-(difference_type const &n) const { return (_self(this->_p - n)); }
			difference_type	operator+(RandomAccessIterator const &b) const { return (this->_p + b._p);	}
			difference_type	operator-(RandomAccessIterator const &b) const { return (this->_p - b._p);	}
			bool	operator>(RandomAccessIterator const &b) const	{ return (this->_p > b._p); };
			bool	operator<(RandomAccessIterator const &b) const	{ return (this->_p < b._p); };
			bool	operator>=(RandomAccessIterator const &b) const	{ return (this->_p >= b._p); };
			bool	operator<=(RandomAccessIterator const &b) const	{ return (this->_p <= b._p); };
			reference	operator[](difference_type const &n) const	{ return (this->_p[n]); };
			RandomAccessIterator &operator+=(difference_type n)
			{
				this->_p += n;
				return (*this); 
			}
			RandomAccessIterator &operator-=(difference_type n)
			{
				this->_p -= n;
				return (*this); 
			}
			/* non member to allow const */
				// n + a
	
	};
}

#endif
