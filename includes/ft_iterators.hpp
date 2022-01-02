/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:52:15 by iwillens          #+#    #+#             */
/*   Updated: 2022/01/02 12:44:45 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATORS_HPP
# define FT_ITERATORS_HPP

# include "ft_iterator_traits.hpp"

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

			/*
			** User-defind conversion function is considered in copy-initialization and reference-initialization
			** It is used on this case to allow initialization of a iterator when passing a const_iterator.
			** The full conversion is:
			** opeartor typename ft::BidirectionalIterator<const value_type>() const
			**  {return (typename ft::BidirectionalIterator<const value_type>(this->_p);}
			** It allows for `typename ft::vector<int>::const_iterator it = container.begin();`
			** Sources:
			**  https://en.cppreference.com/w/cpp/language/cast_operator
			*/

			operator const_self() const { return const_self(this->_p); }	
			pointer	base() const { return this->_p; }

			BidirectionalIterator &operator=(BidirectionalIterator const &b)
			{
				this->_p = b._p;
				return (*this);
			}

			reference operator*() { return *(this->_p); }
			pointer operator->() { return (this->_p); }
			BidirectionalIterator &operator++() { this->_p++; return (*this); }
			BidirectionalIterator &operator--() { this->_p--; return (*this); }

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

			BidirectionalIterator& operator+=(difference_type n) { this->_p += n; return *this; }
			BidirectionalIterator operator+(difference_type n) const { return BidirectionalIterator(this->_p + n); }
			BidirectionalIterator& operator-=(difference_type n) { this->_p -= n; return *this; }
			BidirectionalIterator operator-(difference_type n) const { return BidirectionalIterator(this->_p - n); }

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

 			/*
			** User-defined conversion function, as described in BidirectionalIterator.
			** allows for `typename ft::vector<int>::const_iterator it = container.begin();`
			*/

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
	};

	/*
	** Comparisons with varying iterator types,
	** allowing for cons - nonconst comparisons.
	*/

	template<typename IteratorL, typename IteratorR> 
	bool operator==(const BidirectionalIterator<IteratorL>& lhs, const BidirectionalIterator<IteratorR>& rhs) { return (lhs.base() == rhs.base()); }

	template<typename Iterator>
	bool operator==(const BidirectionalIterator<Iterator>& lhs, const BidirectionalIterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }

	template<typename IteratorL, typename IteratorR>
	bool operator!=(const BidirectionalIterator<IteratorL>& lhs, const BidirectionalIterator<IteratorR>& rhs) { return (lhs.base() != rhs.base()); }

	template<typename Iterator>
	bool operator!=(const BidirectionalIterator<Iterator>& lhs, const BidirectionalIterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }

	template<typename IteratorL, typename IteratorR>
	bool operator<(const BidirectionalIterator<IteratorL>& lhs, const BidirectionalIterator<IteratorR>& rhs) { return (lhs.base() < rhs.base()); }

	template<typename Iterator>
	bool operator<(const BidirectionalIterator<Iterator>& lhs, const BidirectionalIterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); }

	template<typename IteratorL, typename IteratorR>
	bool operator>(const BidirectionalIterator<IteratorL>& lhs, const BidirectionalIterator<IteratorR>& rhs) { return (lhs.base() > rhs.base()); }

	template<typename Iterator>
	bool operator>(const BidirectionalIterator<Iterator>& lhs, const BidirectionalIterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }

	template<typename IteratorL, typename IteratorR>
	bool operator<=(const BidirectionalIterator<IteratorL>& lhs, const BidirectionalIterator<IteratorR>& rhs) { return (lhs.base() <= rhs.base()); }

	template<typename Iterator>
	bool operator<=(const BidirectionalIterator<Iterator>& lhs, const BidirectionalIterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }

	template<typename IteratorL, typename IteratorR>
	bool operator>=(const BidirectionalIterator<IteratorL>& lhs, const BidirectionalIterator<IteratorR>& rhs) { return (lhs.base() >= rhs.base()); }

	template<typename Iterator>
	bool operator>=(const BidirectionalIterator<Iterator>& lhs, const BidirectionalIterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }
}

#endif
