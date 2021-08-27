/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:02 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/27 19:50:19 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "input_iterator.hpp"
# include "reverse_iterator.hpp"

# include "utils.hpp"
# include <exception>

namespace ft
{
	/*
	** Reference for the Vector container?
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
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t													size_type;

		private:
			allocator_type		_allocator;
			pointer 			_data;
			size_type	 		_size;
			size_type	 		_capacity;
			pointer	_create(pointer &p, size_type n)
			{
				p = this->_allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->_allocator.construct(&(p[i]), value_type());
				return(p);
			};
			pointer _clear(pointer &p, size_type n)
			{
				for (size_type i = 0; i < n; i++)
					this->_allocator.destroy(&(p[i]));
				this->_allocator.deallocate(p, n);
				return(p);
			}

		public:	
			/*
			** Constructors, destructor and Assign operator.
			*/
			explicit vector(const allocator_type& alloc = allocator_type()):
			_allocator(alloc), _size(0), _capacity(0)
			{
				this->_create(this->_data, 0);
			};
			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type()):
			_allocator(alloc), _size(n), _capacity(n)
			{
				this->_create(this->_data, 0);
				for (size_type i = 0; i < n; i++)
					this->_data[i] = val;
			};
			template <typename InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type = 0):
			_allocator(alloc), _size(last - first), _capacity(last - first)
			{
				this->_create(this->_data, this->_size);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_data[i] = *(first);
					first++;
				}
			};
			vector(const vector &x):
			_allocator(x._allocator), _size(x._size), _capacity(x._capacity)
			{
				this->_create(this->_data, this->_size);
				for (size_type i = 0; i < this->_size; i++)
					this->_data[i] = x._data[i];
			}
			vector& operator=(const vector& x)
			{
				if (this->_data)
					this->_clear(this->_data, this->_size);
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_create(this->_data, this->_size);
				for (size_type i = 0; i < this->_size; i++)
					this->_data[i] = x._data[i];
				return (*this);
			}
			virtual ~vector() { this->_clear(this->_data, this->_size); };
			
						
			void			resize(size_type n, value_type val = value_type())
			{
				pointer tmp;
				bool	destroy_elem = false;
				size_type orig_size = this->_size;

				if (n == this->_size)
					return ;
				if (n < this->_size)
				{
					destroy_elem = true;
					tmp = this->_data;
					this->_create(this->_data, n);
					for (size_type i = 0; i < n; i++)
						this->_data[i] = tmp[i];
					this->_capacity = n;
				}
				if (n > this->_size)
				{
					tmp = this->_data;
					if (n > this->_capacity)
					{
						this->_create(this->_data, n);
						this->_capacity = n;
						destroy_elem = true;
					}
					for (size_type i = 0; i < this->_size; i++)
						this->_data[i] = tmp[i];
					for (size_type i = this->_size; i < n; i++)
						this->_data[i] = val;
				}
				this->_size = n;
				if (destroy_elem)
					this->_clear(tmp, orig_size);
			}

			/*
			** 
			*/
			allocator_type	get_allocator() const { return (allocator_type(this->_p)); };
			iterator		begin() { return (iterator(this->_data)); }
			iterator		end() { return (iterator(&(this->_data[this->_size]))); }
			const_iterator	begin() const { return (const_iterator(this->_data)); }
			const_iterator	end() const { return const_iterator(&(this->_data[this->_size])); }
			reverse_iterator rbegin() { return (reverse_iterator(end())); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }
			reverse_iterator rend() { return (reverse_iterator(begin())); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); }
			void			push_back(const value_type & val) {	this->resize(this->_size + 1, val);	}
			void			pop_back() { this->_size--; }
			size_type		size() const { return (this->_size); }
			bool			empty() const
			{
				if (this->_size > 0)
					return (false);
				return (true);
			}

			size_type		max_size() const { return (this->_allocator.max_size()); }
			size_type		capacity() const { return (this->_capacity); }
			void			reserve(size_type n)
			{
				pointer tmp;

				if (n > this->max_size())
					throw std::length_error("Cannot reserve larger than max_size.");
				if (n > this->_capacity)
				{
					tmp = this->_data;
					this->_create(this->_data, n);
					for (size_type i = 0; i < this->_size; i++)
						this->_data[i] = tmp[i];
					this->_capacity = n;
				}
				this->_clear(tmp, this->_size);
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

	};
}

#endif
