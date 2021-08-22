/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:14:55 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/22 18:57:46 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

/*
** Enable if implementation.
** if the boolean variable is true, enable_if has a member typedef 'type'.
** reference: https://eli.thegreenplace.net/2014/sfinae-and-enable_if/
** can be used to overload a function only when a specific requirement is true,
** passed as a specialization parameter.
** Example: template <class T, 
**	typename fr::enable_if<std::is_integral<T>::value, T>::type* = nullptr>.
** If the result of is_integral is false, enable_if won't have 'type', which
** causes the overload to fail (as expected).
*/

namespace ft
{
	template<bool, typename T = void>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T> {typedef T type;};

}

#endif
