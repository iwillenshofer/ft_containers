/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorBase.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:02 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/10 12:57:29 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <exception>
# include "input_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"

namespace ft
{
	/*
	** Reference for the Vector container?
	** https://cplusplus.com/reference/VectorBase/VectorBase/
	*/

	template < typename T, typename Alloc = std::allocator<T> >
	class VectorBase
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

			explicit VectorBase(const allocator_type& alloc = allocator_type()):
			_allocator(alloc), _size(0), _capacity(0)
			{
				this->_data = this->_allocator.allocate(0);
			};

			explicit VectorBase(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type()):
			_allocator(alloc), _size(n), _capacity(n)
			{
				this->_data = this->_allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->_allocator.construct(&(this->_data[i]), val);
			};

			template <typename InputIterator>
			VectorBase(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type = 0):
			_allocator(alloc), _size(last - first), _capacity(last - first)
			{
				this->_data = this->_allocator.allocate(this->_size);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_allocator.construct(&(this->_data[i]), value_type(*first));
					first++;
				}
			};

			VectorBase(const VectorBase &x):
			_allocator(x._allocator), _data(0x0), _size(x._size), _capacity(x._capacity) { *this = x; }

			VectorBase& operator=(const VectorBase& x)
			{
				if (this->_data)
				{
					this->clear();
					this->_allocator.deallocate(&(*this->_data), this->_capacity);
				}
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_data = this->_allocator.allocate(this->_size);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&(this->_data[i]), value_type(x._data[i]));
				return (*this);
			}

			virtual ~VectorBase()
			{
				this->clear();
				this->_allocator.deallocate(this->_data, this->_capacity);
			};

			/*
			** Iterators
			*/
			iterator		begin() { return (iterator(this->_data)); }
			iterator		end() { return (iterator(&(this->_data[this->_size]))); }
			const_iterator	begin() const { return (const_iterator(this->_data)); }
			const_iterator	end() const { return const_iterator(&(this->_data[this->_size])); }
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
						this->_allocator.construct(&(tmp[i]), value_type(this->_data[i]));
					this->clear();
					this->_allocator.deallocate(&(*(this->_data)), this->_capacity);
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
		void			assign (InputIterator first, InputIterator last)
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
			value_type values[n];
			for (size_type i = 0; i < n; i++)
				values[i] = val;
			assign(&values[0], &values[n]);
		}

		void			push_back(const value_type & val)
		{	
			this->reserve(this->_size + 1);
			this->_allocator.construct(&(this->_data[this->_size]), value_type(val));
			this->_size++;
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
			value_type values[n];
			
			for (size_type i = 0; i < n; i++)
				values[i] = val;
			insert(position, values, values + n);
		}

		template <typename InputIterator>
		void			insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0x0)
		{
			difference_type pos =  position - this->begin();
			difference_type size = ft::distance(first, last);
			difference_type move = this->_size - pos;
			difference_type last_elem = this->_size + size - 1;

			this->reserve(this->_size + size);
			for (difference_type j = 0; j < move; j++)
			{
				this->_allocator.construct(&(this->_data[last_elem - j]), value_type(this->_data[last_elem - j - size]));
				this->_allocator.destroy(&(this->_data[last_elem - j - size]));
            }
			for (difference_type i = 0; i < size; ++i)
				this->_allocator.construct(&(this->_data[pos + i]), typename ft::iterator_traits<InputIterator>::value_type(*(first + i)));
			this->_size += size;
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

		void			swap (VectorBase& x)
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

		allocator_type	get_allocator() const { return (allocator_type(this->_p)); };

	};


	template <typename T, typename Alloc>
  	void swap (VectorBase<T,Alloc>& x, VectorBase<T,Alloc>& y)
	{
		typename VectorBase<T, Alloc>::allocator_type		tmp_allocator = x._allocator;
		typename VectorBase<T, Alloc>::pointer 				tmp_data = x._data;
		typename VectorBase<T, Alloc>::size_type	 		tmp_size = x._size;
		typename VectorBase<T, Alloc>::size_type	 		tmp_capacity = x._capacity;

		x._allocator = y._allocator;
		x._data = y._data;
		x._size = y._size;
		x._capacity = y._capacity;
		y._allocator = tmp_allocator;
		y._data = tmp_data;
		y._size = tmp_size;
		y._capacity = tmp_capacity;
	}

	/*
	** operator overloads. They are declared as non member functions to
	** mantain synmetry on implicit conversions. They could have been member overloads,
	** but this style guide was followed:
	** https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading/4421729#4421729
	*/

	template <class T, class Alloc>
	bool operator== (const VectorBase<T,Alloc>& lhs, const VectorBase<T,Alloc>& rhs) { 
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
		}

	template <class T, class Alloc>
	bool operator!= (const VectorBase<T,Alloc>& lhs, const VectorBase<T,Alloc>& rhs) { return (!(lhs == rhs)); }

	template <class T, class Alloc>
	bool operator<  (const VectorBase<T,Alloc>& lhs, const VectorBase<T,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class T, class Alloc>
	bool operator<= (const VectorBase<T,Alloc>& lhs, const VectorBase<T,Alloc>& rhs) { return (!(lhs > rhs)); }

	template <class T, class Alloc>
	bool operator>  (const VectorBase<T,Alloc>& lhs, const VectorBase<T,Alloc>& rhs){ return (!(lhs == rhs) && !(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))); }

	template <class T, class Alloc>
	bool operator>= (const VectorBase<T,Alloc>& lhs, const VectorBase<T,Alloc>& rhs) { return (!(lhs < rhs)); }


	template < class T, class Alloc = std::allocator<T> >
	class vector : public VectorBase<T, Alloc>
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

			explicit vector (const allocator_type &alloc = allocator_type()) : VectorBase<T, Alloc>(alloc) {};
			
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: VectorBase<T, Alloc>(n, val, alloc) {};
			
			template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: VectorBase<T, Alloc>(first, last, alloc) {};

			vector (const vector& x): VectorBase<T, Alloc>(x) {};
			~vector() {};
			vector& operator=(const vector& x)
			{
				this->VectorBase<T, Alloc>::operator=(x);
				return (*this); 
			};
	};
	
	/*
	** Template specialization for vector<bool>. 
	*/

	template <class Alloc>
	class vector<bool, Alloc> : public VectorBase<bool,Alloc>
	{
		public:
			typedef bool													value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::RandomAccessIterator<bool>							iterator;
			typedef ft::RandomAccessIterator<const bool>					const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t													size_type;

			explicit vector (const allocator_type &alloc = allocator_type()) : VectorBase<bool, Alloc>(alloc) { };
			
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: VectorBase<bool, Alloc>(n, val, alloc) {};
			
			template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: VectorBase<bool, Alloc>(first, last, alloc) {};

			vector (const vector& x): VectorBase<bool, Alloc>(x) {};
			~vector() {};
			vector& operator=(const vector& x)
			{
				this->VectorBase<bool, Alloc>::operator=(x);
				return (*this); 
			};
			void flip()
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					*it = !(*it);
			}
			void bool_function() { std::cout << "bool function" << std::endl; };
	};
}

#endif
