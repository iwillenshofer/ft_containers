/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/15 09:45:18 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <map>

#include "map.hpp"



void print_node(ft::Node<int, int>& n)
{
	std::cout << "Key: " << n.Key();
	std::cout << ". Value: " << n.Value();
	std::cout << ". Address: " << &n;
	std::cout << ". Left: " << (n._left ? n._left->Key() : 0);
	std::cout << ". Right: " << (n._right ? n._right->Key() : 0);
	std::cout << ". Parent: " << (n._parent ? n._parent->Key() : 0);
	std::cout << ". Color: " << (n._color == 1 ? "RED" : "BLACK");

//	std::cout << ". Height: " << n.height();
//	std::cout << ". Balanced: " << n.balanced() << std::endl;
std::cout << std::endl;
}

void display(ft::RedBlackTree<int, int>::node_pointer root)
{
    if (!root )
   		return;
	display(root->_left);
	print_node(*root);
	display(root->_right);

}


void print_tree(ft::RedBlackTree<int, int>::node_pointer root)
{
    if (!root )
   		return;
	
	std::cout << " < " <<root->Key() << " > " << std::endl;
	print_tree(root->_left);
	print_tree(root->_right);

}



int main(void)
{
	ft::map<int, int> v;

	v.insert(ft::make_pair(11, 11));
	v.insert(ft::make_pair(2, 2));
	v.insert(ft::make_pair(14, 14));
	v.insert(ft::make_pair(1, 1));
	v.insert(ft::make_pair(7, 7));
	v.insert(ft::make_pair(15, 15));
	v.insert(ft::make_pair(5, 5));
	v.insert(ft::make_pair(8, 8));
	v.insert(ft::make_pair(16, 16));



	v.erase(16);
	v.erase(11);
	v.erase(2);


	for (ft::map<int,int>::iterator it = v.begin(); it != v.end(); it++)
		print_node(*(it.base()));


	v.erase(1);
	v.erase(5);
	v.erase(7);
	v.erase(8);
	v.erase(14);
	v.erase(15);


	std::cout << "AFTER ERASE" << std::endl;
	for (ft::map<int,int>::iterator it = v.begin(); it != v.end(); it++)
		print_node(*(it.base()));


}
/*
int main(void)
{
//	ft::Node<int, char> n*(ft::make_pair(10, 'c'));
	ft::RedBlackTree<int, int>::node_pointer n[10000];
	ft::RedBlackTree<int, int> tree;
	ft::RedBlackTreeIterator<ft::Node<int, int> > it;
	std::vector<int> v;
//	tree.insert(ft::make_pair(35, 3));



//	srand (time(NULL));
//for (int i = 0; i < 10000; i++)
//{
//	int rnd = rand() % 10000 + 1;
//	v.push_back(rnd);
//	n[i] = tree.insert(ft::make_pair(rnd, i)).first;
//}

	n[0] = tree.insert(ft::make_pair(3, 0)).first;
	n[1] = tree.insert(ft::make_pair(1,1)).first;
	n[2] = tree.insert(ft::make_pair(6,2)).first;
	n[3] = tree.insert(ft::make_pair(16,3)).first;
	n[4] = tree.insert(ft::make_pair(4,4)).first;
	n[5] = tree.insert(ft::make_pair(9,4)).first;
	n[6] = tree.insert(ft::make_pair(7,4)).first;
	n[6] = tree.insert(ft::make_pair(16,4)).first;




for (int i = 0; i < 7; i++)
{
	print_node(*n[i]);
}

	




	std::cout << std::endl;
*/

//for (int i = 0; i < 7; i++)
//{
//	std::cout << "I: " << i << std::endl << std::flush;
//	tree.erase(n[i]);
//}
//print_node(*(n[1]));
//std::cout << tree._root << std::endl;


/*

	ft::RedBlackTree<int, int>::iterator it3 = tree.begin();

while ( it3 != tree.end())
{
//	ft::RedBlackTree<int, int>::iterator it2 = it3 + 1;
//	print_node((*it3));
//	tree.erase(&(*it3));
//	it3 = it2;
	print_node((*it3));
//	tree.erase(&(*it3));

	it3++;

}
*/

//n[2]=	tree.insert(ft::make_pair(31, 3)).first;
//n[3]=	tree.insert(ft::make_pair(19, 3)).first;
//n[4]=	tree.insert(ft::make_pair(14, 3)).first;
//n[5]=	tree.insert(ft::make_pair(27, 3)).first;
//n[6]=	tree.insert(ft::make_pair(10, 3)).first;




//	tree.insert(ft::make_pair(18, 3));
//	tree.insert(ft::make_pair(8, 3));
//	tree.insert(ft::make_pair(22, 3));
//	tree.insert(ft::make_pair(6, 3));
//	tree.insert(ft::make_pair(9, 3));
//	tree.insert(ft::make_pair(21, 3));
//	tree.insert(ft::make_pair(43, 3));
//	tree.insert(ft::make_pair(20, 3));
//	tree.insert(ft::make_pair(63, 3));
//	tree.insert(ft::make_pair(50, 3));
//
//	//tree.insert(ft::make_pair(10, 3));
//
//	n[0] = tree.insert(ft::make_pair(2, 2)).first;
//	n[1] = tree.insert(ft::make_pair(6, 6)).first;
//	n[2] = tree.insert(ft::make_pair(4, 4)).first;
//
//	//tree.rotate_right(n[1]);
//	//tree.rotate_left(n[0]);
//
//
////	display(tree._root);
////	std::cout << "after erase: " << std::endl;
////	n =  tree.insert(ft::make_pair('g', 7)).first;
////	it = ft::RedBlackTreeIterator<ft::Node<char, int> >(tree._root->minimum());
////	ft::RedBlackTree<char, int>::iterator ite = tree.end();
//	tree.erase(n);


//	tree.rotate_left(n[0]);
//	tree.rotate_left(n[0]);
//	tree.rotate_left(n[0]);

//for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	std::n[6]=	tree.insert(ft::make_pair(, )).first;
//		print_node(*n[i]);


//ft::RedBlackTree<int, int>::const_iterator it2 = tree.end();
//it2--;

//	print_tree(tree._root);
//	display(tree._root);

//std::cout << "ROOT:" << std::endl;
//	print_node(*n[0]);
//	print_node(*n[3]);
/*
	tree.clear(tree._root);



	std::map<int, int> m;
	m.insert(std::pair<int,int>(3,3));
	m.insert(std::pair<int,int>(4,4));
	m.insert(std::pair<int,int>(5,5));
	m.insert(std::pair<int,int>(6,6));


	for (std::map<int,int>::iterator it9 = m.begin(); it9 != m.end(); ++it9)
	{
		m.erase(it9);
		break;
	}
	for (std::map<int,int>::iterator it9 = m.begin(); it9 != m.end(); ++it9)
	{
		std::cout << it9->first << std::endl;
	}

	ft::map<int, int> ft_m;
	ft_m.insert(ft::pair<int,int>(3,3));
	ft_m.insert(ft::pair<int,int>(4,4));
	ft_m.insert(ft::pair<int,int>(5,5));
	ft_m.insert(ft::pair<int,int>(6,6));


	for (ft::map<int,int>::iterator it9 = ft_m.begin(); it9 != ft_m.end(); ++it9)
	{
		ft_m.erase(it9);
		break;
	}
	for (ft::map<int,int>::iterator it9 = ft_m.begin(); it9 != ft_m.end(); ++it9)
	{
		std::cout << it9->first << std::endl;
	}




}
*/
