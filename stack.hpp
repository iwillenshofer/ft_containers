/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:06 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/15 21:19:28 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
	{
		public:
			typedef T           value_type;
			typedef Container   container_type;
			typedef size_t      size_type;

		private:
			container_type _container;

		public:
			explicit stack (const container_type& ctnr = container_type())
			: _container(ctnr) { };

			bool empty() const { return (_container.empty()); }
			size_type size() const { return (_container.size()); }
			value_type& top() { return (_container.back()); }
			const value_type& top() const { return (_container.back()); }
			void push (const value_type& val) { return (_container.push_back(val)); }
			void pop() { return (_container.pop_back()); }

			template <class _T, class _Container>
			friend bool operator== (const stack<_T, _Container>&, const stack<_T, _Container>&);

			template <class _T, class _Container>
			friend bool operator<  (const stack<_T, _Container>&, const stack<_T, _Container>&);

    };

	template <class T, class Container>
	bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (lhs._container == rhs._container); }

	template <class T, class Container>
	bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (!(lhs == rhs)); }

	template <class T, class Container>
	bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (lhs._container < rhs._container); }

	template <class T, class Container>
	bool operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return ((lhs < rhs ) || (lhs == rhs)); }

	template <class T, class Container>
	bool operator>  (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (!(lhs <= rhs)); }

	template <class T, class Container>
	bool operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (!(lhs < rhs)); }
}

#endif
