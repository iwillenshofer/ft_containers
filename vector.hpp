/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:02 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/30 20:27:43 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include "includes/iterators.hpp"
# include "includes/iterator_traits.hpp"
# include "includes/reverse_iterator.hpp"
# include "includes/type_traits.hpp"
# include "includes/algorithm.hpp"

namespace ft
{
	/*
	** Reference for the Vector container:
	** https://cplusplus.com/reference/vector/vector/
	*/

	template < typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::RandomAccessIterator<T>								iterator;
			typedef ft::RandomAccessIterator<const T>						const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t													size_type;

		private:
			allocator_type		_allocator;
			pointer 			_data;
			size_type	 		_size;
			size_type	 		_capacity;

		public:	

			/*
			** Constructors, destructor and Assign operator.
			*/

			explicit vector(const allocator_type& alloc = allocator_type()):
			_allocator(alloc), _size(0), _capacity(0)
			{
				this->_data = this->_allocator.allocate(0);
			};

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type()):
			_allocator(alloc), _size(n), _capacity(n)
			{
				this->_data = this->_allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->_allocator.construct(&(this->_data[i]), val);
			};

			template <typename InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type* = 0x0):
			_allocator(alloc), _size(last - first), _capacity(last - first)
			{
				this->_data = this->_allocator.allocate(this->_size);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_allocator.construct(&(this->_data[i]), value_type(*first));
					first++;
				}
			};

			vector(const vector &x):
			_allocator(x._allocator), _data(0x0), _size(x._size), _capacity(x._capacity) { *this = x; }

			vector& operator=(const vector& x)
			{
				if (this->_data)
				{
					this->clear();
					this->_allocator.deallocate(&(*this->_data), this->_capacity);
				}
				this->_size = x._size;
				this->_capacity = x._size;
				this->_data = this->_allocator.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&(this->_data[i]), value_type(x._data[i]));
				return (*this);
			}

			virtual ~vector()
			{
				this->clear();
				this->_allocator.deallocate(this->_data, this->_capacity);
			};

			/*
			** Iterators
			*/
			iterator		begin() { return (iterator(this->_data)); }
			iterator		end() { return (iterator(this->_data + this->_size)); }
			const_iterator	begin() const { return (const_iterator(this->_data)); }
			const_iterator	end() const { return const_iterator(this->_data + this->_size); }
			reverse_iterator rbegin() { return (reverse_iterator(this->end())); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->end())); }
			reverse_iterator rend() { return (reverse_iterator(this->begin())); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }

			/*
			** Capacity
			*/
			size_type		size() const { return (this->_size); }
			size_type		max_size() const { return (this->_allocator.max_size()); }
			void			resize(size_type n, value_type val = value_type())
			{
				pointer tmp;

				if (n == this->_size)
					return ;
				else if (n > this->_size)
				{
					tmp = this->_allocator.allocate(n);
					for (size_type i = 0; i < (n < this->_size ? n : this->_size); i++)
						this->_allocator.construct(&(tmp[i]), this->_data[i]);
					for (size_type i = this->_size; i < n; i++)
						this->_allocator.construct(&(tmp[i]), val);
					this->clear();
					this->_allocator.deallocate(&(*this->_data), this->_capacity);				
					this->_data = tmp;
					this->_size = n;
					this->_capacity = n;
				}
				else
				{
					while (this->_size > n)
						this->pop_back();
				}
			}

			size_type		capacity() const { return (this->_capacity); }
			bool			empty() const
			{
				if (this->_size > 0)
					return (false);
				return (true);
			}

			void			reserve(size_type n)
			{
				pointer		tmp;
				size_type	old_size = this->_size;

				if (n > this->max_size())
					throw std::length_error("Cannot reserve larger than max_size.");
				if (n > this->_capacity)
				{
					tmp = this->_allocator.allocate(n);
					for (size_type i = 0; i < old_size; i++)
						this->_allocator.construct(&(tmp[i]), this->_data[i]);
					this->clear();
					this->_allocator.deallocate(this->_data, this->_capacity);
					this->_capacity = n;
					this->_data = tmp;
					this->_size = old_size;
				}
			}
		
		/*
		** Element Access:
		*/

		reference operator[] (size_type n) { return (this->_data[n]); };
		const_reference operator[] (size_type n) const{ return (this->_data[n]); };
	
		reference at (size_type n)
		{
			if (n >= this->_size)
				throw std::out_of_range("Element out of Range");
			return (this->_data[n]);
		};
	
		const_reference at (size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("Element out of Range");
			return (this->_data[n]);			
		}
	
		reference front() { return (this->_data[0]); }
		const_reference front() const { return (this->_data[0]); }
		reference back() { return (this->_data[this->_size - 1]); }
		const_reference back() const { return (this->_data[this->_size - 1]); }

		/*
		** Modifiers
		*/
		template <class InputIterator>
		void			assign (InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type* = 0x0)
		{
			size_type n = last - first;

			this->clear();
			this->reserve(n);
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void			assign (size_type n, const value_type& val)
		{
			this->clear();
			this->reserve(n);
			for (size_type i = 0; i < n; i++)
				push_back(val);
		}

		void			push_back(const value_type & val)
		{
			if (this->_capacity < this->_size + 1)
			{
				this->reserve(this->_size ? this->_size * 2 : 1);
				this->_allocator.construct(&(this->_data[this->_size]), val);
				this->_size++;
			}
			else
			{
				this->_allocator.construct(&(this->_data[this->_size]), val);
				this->_size++;
			}
		}

		void			pop_back()
		{ 
			this->_size--;
			this->_allocator.destroy(&(this->_data[this->_size]));
		}

		iterator		insert (iterator position, const value_type& val)
		{
			size_type pos = (position - this->_data);

			insert(position, 1, val);
			return (iterator(this->begin() + pos));
		}
		
		void			insert (iterator position, size_type n, const value_type& val)
		{	
			size_type pos =  position - this->begin();
			size_type move = this->_size - pos;

			if (this->_capacity < this->_size + n)
				this->reserve(this->_size + (this->_size > n ? this->_size : n));
			for (size_type j = 0; j < n; j++)
				this->_allocator.construct((this->_data + this->_size + j), value_type(val));
			for (size_type j = 0; j < n; j++)
			{
				for (size_type i = 0; i < move; i++)
					std::swap(*(this->end() + j - i), *(this->end() + j - i - 1));
			}
			this->_size += n;
		}

		template <typename InputIterator>
		void			insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0x0)
		{
			size_type pos =  position - this->begin();
			size_type len = ft::distance(first, last);
			size_type move = this->_size - pos;

			if (this->_capacity < this->_size + len)
				this->reserve(this->_size + (this->_size > len ? this->_size : len));
			for (size_type j = 0; j < len; j++)
				this->_allocator.construct((this->_data + this->_size + j), *(first + j));
			for (size_type j = 0; j < len; j++)
			{
				for (size_type i = 0; i < move; i++)
					std::swap(*(this->end() + j - i), *(this->end() + j - i - 1));
			}
			this->_size += len;
		}
		
		iterator		erase (iterator position)
		{
			erase(position, position + 1);
			return(position);
		}

		iterator		erase (iterator first, iterator last)
		{
			pointer p = &(*first);
			difference_type size = this->end() - &(*last);

			if (first == end() || first == last)
				return(first);
			while (first != last)
			{
				this->_allocator.destroy(&(*first));
				this->_size--;
				first++;
			}
			for (difference_type i = 0; i < size; i++)
			{
				this->_allocator.construct(p + i, *(&last[i]));
				this->_allocator.destroy(&last[i]);				
			}
			return(iterator(p));
		}	

		void			swap (vector& x)
		{
			allocator_type		tmp_allocator = this->_allocator;
			pointer 			tmp_data = this->_data;
			size_type	 		tmp_size = this->_size;
			size_type	 		tmp_capacity = this->_capacity;
	
			this->_allocator = x._allocator;
			this->_data = x._data;
			this->_size = x._size;
			this->_capacity = x._capacity;
			x._allocator = tmp_allocator;
			x._data = tmp_data;
			x._size = tmp_size;
			x._capacity = tmp_capacity;
		}

		void			clear()
		{
			while (this->_size)
				pop_back();
		};

		allocator_type	get_allocator() const { return (allocator_type(this->_allocator)); };

	};


	template <typename T, typename Alloc>
  	void swap (vector<T,Alloc>& lhs, vector<T,Alloc>& rhs)
	{
		vector<T, Alloc> tmp(lhs);

		lhs = rhs;
		rhs = tmp;
	}

	/*
	** operator overloads. They are declared as non member functions to
	** mantain synmetry on implicit conversions. They could have been member overloads,
	** but this style guide was followed:
	** https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading/4421729#4421729
	*/

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{ 
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return (!(lhs == rhs)); }

	template <class T, class Alloc>
	bool operator<  (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class T, class Alloc>
	bool operator<= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return (!(lhs > rhs)); }

	template <class T, class Alloc>
	bool operator>  (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs){ return (!(lhs == rhs) && !(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))); }

	template <class T, class Alloc>
	bool operator>= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return (!(lhs < rhs)); }

}

#endif
