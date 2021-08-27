/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:18:08 by iwillens          #+#    #+#             */
/*   Updated: 2021/08/27 17:30:16 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include "iterators.hpp"
#include "input_iterator.hpp"
#include <typeinfo>  //for 'typeid' to work  
#include "vector.hpp"

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
	int i[5] = {1, 2, 3, 4, 5};
	std::vector<int> v = {1, 2, 3, 4, 5};

	iterate(&i[0], &i[5]);
	iterate(v.begin(), v.end());
	
}
 //   ft::vector<int> v;
    //int a[] = {1, 2, 3, 4, 5};
    //const int b[] = {1, 2, 3, 4, 5};
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//    iterate(v.begin(), v.end());
//    std::cout << '\n';
//    iterate(a, a + 5);
//    std::cout << '\n';
//    iterate(b, b + 5);
//    std::cout << '\n';
	
//	ft::RandomAccessIterator<int> i;
//	ft::RandomAccessIterator<int> i2;
//	i = i2;
//	i2 = i;
//	i++;
//	i--;
//	++i;
//	--i;
//	ft::vector<int> v1;// = {10, 20, 30, 40, 50};
//	v1.push_back(30);
//	v1.push_back(10);
//	v1.push_back(15);
//	v1.pop_back();
//	v1.push_back(15);
//	v1.pop_back();
//	v1.pop_back();
//	v1.pop_back();
//
//	std::cout << "Size: " << v1.size() << std::endl;
//	std::cout << "Size: " << v1.max_size() << std::endl;
//	std::cout << "Capacity: " << v1.capacity() << std::endl;
//
//	ft::vector<int>::iterator it;
//	for (it=v1.begin(); it!=v1.end();++it)
//	{
//		std::cout << *it << std::endl;
//	}
//	ft::vector<int> v2;
//	(void)v2;
//	v1.reserve(38);
//	std::cout << "Capacity: " << v1.capacity() << std::endl;
//
//
//	std::vector<int>::iterator			orig_iterator;
//	std::vector<int>::const_iterator	orig_const_iterator;
//	orig_const_iterator = orig_iterator;

//	ft::vector<int>::iterator iterator;
//	ft::vector<int>::const_iterator const_iterator;
//	const_iterator = iterator;
//	(void)const_iterator;
//	(void)iterator;
//	//std::cout << i.it << std::endl;
//}