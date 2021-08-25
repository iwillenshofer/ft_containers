/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:02 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/25 18:30:22 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "input_iterator.hpp"
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
			typedef ft::RandomAccessIterator<T, T&, T*>						iterator;
			typedef ft::RandomAccessIterator
						<const T, const T&, const T*>						const_iterator;
		//	typedef ft::reverse_iterator<iterator>					reverse_iterator;
		//	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
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
			vector(const allocator_type& alloc = allocator_type()):
			_allocator(alloc), _size(0), _capacity(0)
			{
				this->_create(this->_data, 0);
			};
			vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type()):
			_allocator(alloc), _size(n), _capacity(n)
			{
				this->_create(this->_data, 0);
				for (size_type i = 0; i < n; i++)
					this->_start[i] = val;
			};
			template <typename InputIterator> vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):
			_allocator(alloc), _size(last - first), _capacity(last - first)
			{
				this->_create(this->_data, this->_size);
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_start[i] = *first;
					first++;
				}
			};
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
			allocator_type	get_allocator() const { return allocator_type(this->_p); };
			iterator		begin() const { return iterator(this->_data); }
			iterator		end() const { return iterator(&(this->_data[this->_size])); }
			void			push_back(const value_type & val) {	this->resize(this->_size + 1, val);	}
			void			pop_back() { this->_size--; }
			size_type		size() const { return (this->_size); }
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
			
	};
}

#endif
