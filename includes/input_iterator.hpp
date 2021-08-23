/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:52:15 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/23 14:51:04 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_ITERATOR_HPP
# define INPUT_ITERATOR_HPP

# include "iterators.hpp"

namespace ft
{
	template <typename T, typename Category = input_iterator_tag, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	class InputIterator
	{
		public:
			typedef Category																	iterator_category;
			typedef T																			value_type;
			typedef Distance																	difference_type;
			typedef Pointer																		pointer;
			typedef Reference																	reference;
			typedef ft::InputIterator<T, Category, Distance, Pointer, Reference>				iterator;
			typedef ft::InputIterator<T, Category, Distance, const Pointer, const Reference>	const_iterator;

			InputIterator(): _p(0x0) {};
			InputIterator(const InputIterator &b) { *this = b; };
			virtual ~InputIterator() {}
			InputIterator &operator=(InputIterator const &b)
			{
				this->_p = b._p;
				return (*this);
			}
		private:
			pointer	_p;
	};

	template <typename T, typename Category = bidirectional_iterator_tag, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	class BidirectionalIterator : public ft::InputIterator<T, Category, Distance, Pointer, Reference>
	{
		public:
			typedef Category																			iterator_category;
			typedef T																					value_type;
			typedef Distance																			difference_type;
			typedef Pointer																				pointer;
			typedef Reference																			reference;
			typedef ft::InputIterator<T, Category, Distance, Pointer, Reference>						base_class;
			typedef ft::BidirectionalIterator<T, Category, Distance, Pointer, Reference>				iterator;
			typedef ft::BidirectionalIterator<T, Category, Distance, const Pointer, const Reference>	const_iterator;

			BidirectionalIterator(): base_class() {};
			BidirectionalIterator(const BidirectionalIterator &b): base_class(b) {};
			virtual ~BidirectionalIterator() {}
			BidirectionalIterator &operator=(BidirectionalIterator const &b)
			{
				this->base_class::operator=(b);
				return (*this);
			}
	};

	template <typename T, typename Category = random_access_iterator_tag, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	class RandomAccessIterator : public ft::BidirectionalIterator<T, Category, Distance, Pointer, Reference>
	{
		public:
			typedef Category																	iterator_category;
			typedef T																			value_type;
			typedef Distance																	difference_type;
			typedef Pointer																		pointer;
			typedef Reference																	reference;
			typedef BidirectionalIterator<T, Category, Distance, Pointer, Reference>			base_class;
			typedef RandomAccessIterator<T, Category, Distance, Pointer, Reference>				iterator;
			typedef RandomAccessIterator<T, Category, Distance, const Pointer, const Reference>	const_iterator;

			RandomAccessIterator(): base_class() {};
			RandomAccessIterator(const RandomAccessIterator &b): base_class(b) {};
			virtual ~RandomAccessIterator() {}
			RandomAccessIterator &operator=(RandomAccessIterator const &b)
			{
				this->base_class::operator=(b);
				return (*this);
			}
	};
}


#endif