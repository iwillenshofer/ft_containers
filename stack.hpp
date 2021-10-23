/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:06 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/23 14:48:21 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	/*
	** Reference for the Stack container:
	** https://cplusplus.com/reference/stack/stack/
	*/
    template <class T, class Container = ft::vector<T> >
    class stack
	{
		public:
			typedef T           value_type;
			typedef Container   container_type;
			typedef size_t      size_type;

		protected:
			container_type c;

		public:
			explicit stack (const container_type& ctnr = container_type())
			: c(ctnr) { };

			bool empty() const { return (c.empty()); }
			size_type size() const { return (c.size()); }
			value_type& top() { return (c.back()); }
			const value_type& top() const { return (c.back()); }
			void push (const value_type& val) { return (c.push_back(val)); }
			void pop() { return (c.pop_back()); }

			template <class _T, class _Container>
			friend bool operator== (const stack<_T, _Container>&, const stack<_T, _Container>&);

			template <class _T, class _Container>
			friend bool operator<  (const stack<_T, _Container>&, const stack<_T, _Container>&);

    };

	template <class T, class Container>
	bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (lhs.c == rhs.c); }

	template <class T, class Container>
	bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (!(lhs == rhs)); }

	template <class T, class Container>
	bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (lhs.c < rhs.c); }

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
