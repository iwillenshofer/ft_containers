/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:18:08 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/23 17:29:00 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include "iterators.hpp"
#include "input_iterator.hpp"
#include <typeinfo>  //for 'typeid' to work  

template<class Iterator>
void iterate(Iterator first, Iterator last)
{
    typename ft::iterator_traits<Iterator>::difference_type n = std::distance(first, last);
	for (typename ft::iterator_traits<Iterator>::difference_type i = 0; i < n; i++)
	{
        std::cout << *first << ' ';
		first++;
    }
}
 
int main()
{
    std::vector<int> v;
    int a[] = {1, 2, 3, 4, 5};
    const int b[] = {1, 2, 3, 4, 5};
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
    iterate(v.begin(), v.end());
    std::cout << '\n';
    iterate(a, a + 5);
    std::cout << '\n';
    iterate(b, b + 5);
    std::cout << '\n';
	
	ft::RandomAccessIterator<int> i;
	ft::RandomAccessIterator<int> i2;
	i = i2;
	i2 = i;
	i++;
	i--;
	++i;
	--i;
	//std::cout << i.it << std::endl;
}