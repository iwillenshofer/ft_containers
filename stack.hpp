/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:15:06 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/15 20:48:15 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack;
	{
        typedef T           value_type;
        typedef Container   container_type;
        typedef size_t      size_type;

        explicit stack (const container_type& ctnr = container_type());
bool empty() const;

    }
}

#endif
