/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:18:08 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/16 13:01:52 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <list>
//#include "iterators.hpp"
//#include "input_iterator.hpp"
#include <typeinfo>  //for 'typeid' to work  
#include <typeinfo>
#include <vector>
#include <iostream>
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

#include <typeinfo>
#include <vector>
#include <iostream>
#include "vector.hpp"

template<typename T>
void test_insert()
{
	T vector(100);
	std::cout << vector.capacity() << std::endl;
	std::cout << "insert1: " << std::endl;
	vector.insert(vector.begin() + 3, 1);
	typename T::const_iterator std_it = vector.begin();
	typename T::const_iterator std_end = vector.end();
	std::cout << typeid(std_end).name() << '\n';
	std::cout << "insert2: " << std::endl;
	vector.insert(vector.begin() + 3, 1);
	while (std_it != std_end)
	{
		std::cout << *std_it << " | ";
		std_it++;
	}
	std::cout << std::endl;
	for (typename T::const_iterator it = vector.begin(); it != vector.end(); it += 1)
		std::cout << *it << " | ";
	std::cout << std::endl;
	std::cout << "Capacity: ";
	std::cout << vector.capacity() << std::endl;

}

template<typename T>
void test_capacity(void)
{
	T vec;
	
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	vec.reserve(0);
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	vec.reserve(1);

	std::cout << "Capacity: " << vec.capacity() << std::endl;
	vec.insert(vec.begin(), 1);
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	vec.insert(vec.begin(), 1);
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	int i[] = {1, 2, 3, 4, 5};
	typename T::iterator begin(&i[0]);
	typename T::iterator end(&i[5]);
	int size = 1000000;
	int arr[size];
	for (int z = 0; z < size; z++)
		arr[z] = z;
	vec.insert(vec.begin(), begin, end);
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	vec.insert(vec.begin() + 7, &arr[0], &arr[size] );
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	vec.insert(vec.begin(), 1);
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	for (typename T::const_iterator it = vec.begin(); it != vec.begin() + 50; it += 1)
		std::cout << *it << " | ";
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		test_insert< std::vector<int> >();
		test_capacity< std::vector<int> >();
	}
	else
	{
		test_insert< ft::vector<int> >();
		test_capacity< ft::vector<int> >();
	}

	(void)argv;
}

int main2()
{
//	ft::vector<std::string> cont;
	
/*	v.push_back(3);
	v.push_back(3);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	ft::vector<int> b(v);
	b.push_back(10);
	v = b;
//	v.insert(v.begin(), 1, 1);
//	v.insert(v.begin(), 1, 1);

	

//	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
//		std::cout << *it << std::endl;
//	std::cout << "INSERT:" << std::endl;
	v.insert(v.begin() + 1 , 3, 9996);

//	ft::vector<int>::reverse_iterator it2;
//	(void)it2;

    int a[] = {1, 2, 3, 4, 5};
	v.insert(v.end(), &a[0], &a[5]);
//	for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
//		std::cout << *it << std::endl;

//	std::cout << "SINGLE INSERT:" << std::endl;

	ft::vector<int>::iterator itnew = v.insert(v.begin() , 69);
	//ft::vector<int>::iterator itnew2 = v.erase(v.end());

	
//	v.erase(v.begin());

	for (ft::vector<int>::iterator it = itnew; it != v.end(); ++it)
		std::cout << *it << std::endl;

	while (v.size())
		v.erase(v.begin());
//	v.erase(v.begin(), v.end()-5);
	std::cout << "Erased: " << std::endl;
	for (ft::vector<int>::iterator it = itnew; it != v.end(); ++it)
		std::cout << *it << std::endl;
	ft::swap(v, b);
*/	
 //   for (ft::vector<int>::const_iterator it = v.end() - 1; it != v.begin() - 1; it -= 1)
 //       std::cout << *it << " | ";
 
//	std::cout << "Size : " << v.size() << std::endl;
//	v.erase(v.begin(),v.end());
//	v.push_back(0);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//

//	v.insert(v.begin() - 1, 5, 1);
//	for (ft::vector<int>::const_iterator it = v.begin(); it != v.end(); it += 1)
//		std::cout << *it << " | ";
//	std::cout << std::endl;


//	std::cout << ft::distance(v.end() - 1, v.end()) << std::endl;
//    ft::vector<int>::iterator iter;// = v.erase(v.end() - 1, v.end());
//	iter = v.erase(v.begin(), v.begin() + 1);

//    for (ft::vector<int>::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
//    {   
//		std::cout << *it << " | ";
//		//it++;
//	}

//	ft::vector<int>::const_reverse_iterator it = v.rbegin();
//	std::cout << std::endl  << it[0] << std::endl;



    ft::vector<int> v;


//	cont.push_back(std::string("String"));
//	ft::vector<std::string> tmp = cont;

//	std::cout << "size of tmp = " << tmp.size() << std::endl;

//	tmp.reserve(tmp.size() + 1);
	//std::cerr << "BEGIN:" << tmp.begin() << std::endl;
//    tmp.insert(tmp.begin(), cont.begin(), cont.end());
  //  if (!tmp.size())
    //{
   //      ft::vector<std::string>::iterator it = tmp.begin();
     //   ++it;
       // tmp.insert(it, cont.begin(), cont.end());/
//    }
   // tmp.insert(tmp.end(), cont.begin(), cont.end());
  //  tmp.insert(tmp.end(), cont.begin(), cont.begin());//	v.insert(v.begin() - 1, 5, 1);
  //  tmp.insert(tmp.begin(), cont.begin(), cont.end());

///	for (ft::vector<std::string>::const_iterator it = tmp.begin(); it != tmp.end(); it += 1)
	///	std::cout << *it << " | ";
	///std::cout << std::endl;
//	std::cout <<ft::equal(tmp.begin(), tmp.end(), cont.begin());

	ft::vector<int> bool3;

	ft::vector<bool> bool2;
	ft::vector<bool> booleano;
	//booleano.bool_function();
	booleano.push_back(true);
	booleano.push_back(false);
	booleano.push_back(true);
	booleano.push_back(false);
	booleano.insert(booleano.begin(), true);
	for (ft::vector<bool>::const_iterator it = booleano.begin(); it != booleano.end(); it += 1)
		std::cout << *it << " | ";
	std::cout << std::endl;
	bool2 = booleano;
//	bool2.flip();
	for (ft::vector<bool>::const_iterator it = bool2.begin(); it != bool2.end(); it += 1)
		std::cout << *it << " | ";
	std::cout << std::endl;
//	ft::vector<bool>::swap(bool2[0], bool2[2]);
	for (ft::vector<bool>::const_iterator it = bool2.begin(); it != bool2.end(); it += 1)
		std::cout << *it << " | ";
	std::cout << std::endl;

	ft::vector<int> myvector;
	for (int i=0; i<10; i++) myvector.push_back(i);


	typedef ft::vector<int>::iterator iter_type;

	ft::reverse_iterator<iter_type> rev_end (myvector.begin());
	ft::reverse_iterator<iter_type> rev_begin (myvector.end());

	std::cout << "myvector:";
	for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	int capacity = 10;
	ft::vector<int> capft(capacity);
	std::cout << "Capacity: ";
	std::cout << capft.capacity() << std::endl;
	capft.insert(capft.begin() + 3, 1);
	ft::vector<int>::const_iterator ft_it = capft.begin();
	ft::vector<int>::const_iterator ft_end = capft.end();
	capft.insert(capft.begin() + 3, 1);
	while (ft_it != ft_end)
	{
		std::cout << *ft_it << " | ";
		ft_it++;
	}
	std::cout << std::endl;
	for (ft::vector<int>::const_iterator it = capft.begin(); it != capft.end(); it += 1)
		std::cout << *it << " | ";
	std::cout << std::endl;

	std::vector<int> capstd(capacity);
	std::cout << "Capacity: ";
	std::cout << capstd.capacity() << std::endl;
	capstd.insert(capstd.begin() + 3, 1);
	std::vector<int>::const_iterator std_it = capstd.begin();
	std::vector<int>::const_iterator std_end = capstd.end();
	capstd.insert(capstd.begin() + 3, 1);
	while (std_it != std_end)
	{
		std::cout << *std_it << " | ";
		std_it++;
	}
	std::cout << std::endl;
	for (std::vector<int>::const_iterator it = capstd.begin(); it != capstd.end(); it += 1)
		std::cout << *it << " | ";
	std::cout << std::endl;

	return 0;

}
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