/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:52:15 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/25 16:59:36 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_ITERATOR_HPP
# define INPUT_ITERATOR_HPP

# include "iterators.hpp"

namespace ft
{
	template <typename T, typename Category = forward_iterator_tag,
		typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	class BidirectionalIterator
	{
		public:
			typedef Category											iterator_category;
			typedef T													value_type;
			typedef Distance											difference_type;
			typedef Pointer												pointer;
			typedef Reference											reference;
			typedef ft::BidirectionalIterator
				<T, Category, Distance, Pointer, Reference>				iterator;
			typedef ft::BidirectionalIterator
				<T, Category, Distance, const Pointer, const Reference>	const_iterator;

			BidirectionalIterator(): _p(0x0) { };
			BidirectionalIterator(pointer p): _p(p) { };
			BidirectionalIterator(const BidirectionalIterator &b) { *this = b; };
			virtual ~BidirectionalIterator() { }
			BidirectionalIterator &operator=(BidirectionalIterator const &b)
			{
				this->_p = b._p;
				return (*this);
			}
			bool operator==(BidirectionalIterator const &b) { return (this->_p == b._p); }
			bool operator!=(BidirectionalIterator const &b) { return (this->_p != b._p); }
			reference operator*() { return *(this->_p); }
			pointer operator->() { return (&(this->_p)); }
			iterator &operator++()
			{ 
				this->_p++;
				return (*this); 
			}
			
			iterator &operator--()
			{ 
				this->_p--;
				return (*this); 
			}

			iterator operator++(int)
			{
				iterator tmp(*this);

				this->_p++;
				return (tmp); 
			}

			iterator operator--(int)
			{
				iterator tmp(*this);

				this->_p--;
				return (tmp); 
			}
			
		private:
			pointer	_p;
	};

	template <typename T, typename Category = random_access_iterator_tag,
		typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	class RandomAccessIterator :
		public ft::BidirectionalIterator<T, Category, Distance, Pointer, Reference>
	{
		public:
			typedef Category											iterator_category;
			typedef T													value_type;
			typedef Distance											difference_type;
			typedef Pointer												pointer;
			typedef Reference											reference;
			typedef BidirectionalIterator
				<T, Category, Distance, Pointer, Reference>				base_class;
			typedef RandomAccessIterator
				<T, Category, Distance, Pointer, Reference>				iterator;
			typedef RandomAccessIterator
				<T, Category, Distance, const Pointer, const Reference>	const_iterator;

			RandomAccessIterator(): base_class() {};
			RandomAccessIterator(pointer p): base_class(p) { };
			RandomAccessIterator(const RandomAccessIterator &b): base_class(b) {};
			virtual ~RandomAccessIterator() {}
			RandomAccessIterator &operator=(RandomAccessIterator const &b)
			{
				this->base_class::operator=(b);
				return (*this);
			}
			iterator	operator+(difference_type const &n) const
			{
				iterator	tmp(*this);

				tmp._p += n;
				return (tmp);
			}
			iterator	operator-(difference_type const &n) const
			{
				iterator	tmp(*this);

				tmp._p -= n;
				return (tmp);
			}
			difference_type	operator+(iterator const &b) const { return (this->_p + b._p);	}
			difference_type	operator-(iterator const &b) const { return (this->_p - b._p);	}
			bool	operator>(iterator const &b) const	{ return (this->_p > b._p); };
			bool	operator<(iterator const &b) const	{ return (this->_p < b._p); };
			bool	operator>=(iterator const &b) const	{ return (this->_p >= b._p); };
			bool	operator<=(iterator const &b) const	{ return (this->_p <= b._p); };
			reference	operator[](difference_type const &n) const	{ return (&(this->_p) + n); };
			iterator	operator+=(iterator const &n) const
			{
				this->_p += n;
				return (this);
			}
			iterator	operator-=(iterator const &n) const
			{
				this->_p -= n;
				return (this);
			}
	};
}

#endif
