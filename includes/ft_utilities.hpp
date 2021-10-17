/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:42:01 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 20:42:05 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITIES_HPP
# define FT_UTILITIES_HPP

# include <climits>

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type	first;
			second_type	second;
		
		public:
			pair(): first(first_type()), second(second_type()) { }
			template<class U, class V>
			pair (const pair<U,V>& pr): first(first_type(pr.first)), second(second_type(pr.second)) { }
			pair (const first_type& a, const second_type& b): first(first_type(a)), second(second_type(b)) { }
			pair& operator= (const pair& pr)
			{
				this->first = first_type(pr.first);
				this->second = second_type(pr.second);
				return (*this);
			}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (!(lhs == rhs)); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (!(rhs < lhs)); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (rhs < lhs); }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) { return (!(lhs < rhs)); }

	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( ft::pair<T1,T2>(x, y) );
	}

	/*
	** structures to get first or second type/value of a Pair
	*/
	template <class Arg, class Result>
	struct unary_function
	{
		typedef Arg		argument_type;
		typedef Result	result_type;
	};
	template <class Pair>
	struct Select1st : public unary_function<Pair, typename Pair::first_type>
	{
		typename Pair::first_type &operator()(Pair& x) const { return x.first; }
		const typename Pair::first_type &operator()(const Pair& x) const { return x.first; }
	};

	template <class Pair>
	struct Select2nd : public unary_function<Pair,	typename Pair::second_type>
	{
		typename Pair::second_type &operator()(Pair& x) const { return x.second; }
		const typename Pair::second_type &operator()(const Pair& x) const { return x.second; }
	};

	template <class T>
	struct Identity : public unary_function<T,	T>
	{
		T &operator()(T& t) const { return t; }
		const T &operator()(const T& t) const { return t; }
	};

	template< class T >
	struct less
	{
		typedef T		first_argument_type; 
		typedef T		second_argument_type;
		typedef bool	result_type;	
		bool operator()(const T &lhs, const T &rhs) const 
		{
			return (lhs < rhs);
		}
	};
}

#endif
