/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_traits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:14:55 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/13 15:47:10 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

#include "ft_iterator_traits.hpp"

namespace ft
{
	/*
	** Enable if implementation.
	** if the boolean variable is true, enable_if has a member typedef 'type'.
	** reference: https://eli.thegreenplace.net/2014/sfinae-and-enable_if/
	** can be used to overload a function only when a specific requirement is true,
	** passed as a specialization parameter.
	** Example: template <class T, 
	**	typename ft::enable_if<std::is_integral<T>::value, T>::type* = NULL>.
	** If the result of is_integral is false, enable_if won't have 'type', which
	** causes the overload to fail (as expected).
	*/	
	template<bool, typename T = void>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T> {typedef T type;};

	/*
	** integral_constant creates a type for true_type and false_type.
	** For this project's purposes, it could be bypassed by returning just
	** true or false on is_integral, but true_type and false_type were created
	** to follow the original implementation of is_integral as much as possible.
	** types that will return true are: bool, char, char16_t, char32_t, wchar_t,
	** short, int, long, long.
	** reference: https://en.cppreference.com/w/cpp/types/is_integral
	*/
	template <typename T, T val>
	struct integral_constant
	{
		static const T						value = val;
		typedef T							value_type;
		typedef integral_constant<T, value>	type;
		operator value_type() { return val; }
	};

	typedef ft::integral_constant<bool, true>	true_type;
	typedef ft::integral_constant<bool, false>	false_type;

	/*
	** Removes const and volatile qualifications. Added to complete
	** the original implementation of is_integral, making it work also
	** with const and volatile types.
	** helper is added to allow removing const/volatile before returning
	** is_integral.
	*/
	template<typename T>
	struct remove_const	{ typedef T	type; };

	template<typename T>
	struct remove_const<T const> { typedef T	type; };

	template<typename T>
	struct remove_volatile { typedef T	type; };

	template<typename T>
	struct remove_volatile<T volatile> { typedef T	type; };

	template<typename T>
	struct remove_cv { typedef typename remove_const<typename remove_volatile<T>::type>::type	type; };

	template <typename T>
	struct is_integral_helper : public false_type {};

	template <>
	struct is_integral_helper<bool> : public true_type {};
	template <>
	struct is_integral_helper<char> : public true_type {};
	template <>
	struct is_integral_helper<unsigned char> : public true_type {};
	template <>
	struct is_integral_helper<wchar_t> : public true_type {};
	template <>
	struct is_integral_helper<short> : public true_type {};
	template <>
	struct is_integral_helper<unsigned short> : public true_type {};
	template <>
	struct is_integral_helper<int> : public true_type {};
	template <>
	struct is_integral_helper<unsigned int> : public true_type {};
	template <>
	struct is_integral_helper<long> : public true_type {};
	template <>
	struct is_integral_helper<unsigned long> : public true_type {};
	template <typename T>
	struct is_integral : public ft::is_integral_helper<typename ft::remove_cv<T>::type>::type {};

	/*
	** is_bool is not part of stl, but is implemented for vector specialization
	*/
	template <typename T>
	struct is_bool_helper : public false_type {};

	template <>
	struct is_bool_helper<bool> : public true_type {};

	template <typename T>
	struct is_bool : public ft::is_bool_helper<typename ft::remove_cv<T>::type>::type {};

	/*
	** is_same to check if two types are the same.
	*/
	template<typename TL, typename TR>
    struct is_same : public false_type {};

  	template<typename T>
    struct is_same<T, T> : public true_type {};

}




#endif
