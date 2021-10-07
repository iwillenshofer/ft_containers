/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/07 17:51:33 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_binarytree.hpp"
#include "./includes/ft_binarytree_iterator.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>


void print_node(ft::BinaryTree<int, int>::node_reference n)
{
	std::cout << "Key: " << n.Key();
	std::cout << ". Value: " << n.Value();
	std::cout << ". Address: " << &n;
	std::cout << ". Left: " << (n._left ? n._left->Key() : 0);
	std::cout << ". Right: " << (n._right ? n._right->Key() : 0);
	std::cout << ". Parent: " << (n._parent ? n._parent->Key() : 0);
	std::cout << ". Height: " << n.height();
	std::cout << ". Balanced: " << n.balanced() << std::endl;
std::cout << std::endl;
}

void display(ft::BinaryTree<int, int>::node_pointer root)
{
    if (!root )
   		return;
	display(root->_left);
	print_node(*root);
	display(root->_right);

}


void print_tree(ft::BinaryTree<int, int>::node_pointer root)
{
    if (!root )
   		return;
	
	std::cout << " < " <<root->Key() << " > " << std::endl;
	print_tree(root->_left);
	print_tree(root->_right);

}


int main(void)
{
//	ft::Node<int, char> n*(ft::make_pair(10, 'c'));
	ft::BinaryTree<int, int>::node_pointer n[10000];
	ft::BinaryTree<int, int> tree;
	ft::BinaryTreeIterator<ft::Node<int, int> > it;
	std::vector<int> v;
//	tree.insert(ft::make_pair(35, 3));
	srand (time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		int rnd = rand() % 10000 + 1;
		v.push_back(rnd);
		n[i] = tree.insert(ft::make_pair(rnd, 3)).first;
	}

tree.erase(n[1]);

for (ft::BinaryTree<int, int>::iterator it = tree.begin(); it != tree.end(); ++it)
{
	print_node(*it);
}


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
////	it = ft::BinaryTreeIterator<ft::Node<char, int> >(tree._root->minimum());
////	ft::BinaryTree<char, int>::iterator ite = tree.end();
//	tree.erase(n);


//	tree.rotate_left(n[0]);
//	tree.rotate_left(n[0]);
//	tree.rotate_left(n[0]);

//for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	std::n[6]=	tree.insert(ft::make_pair(, )).first;
//		print_node(*n[i]);


//ft::BinaryTree<int, int>::const_iterator it2 = tree.end();
//it2--;

//	print_tree(tree._root);
//	display(tree._root);

//std::cout << "ROOT:" << std::endl;
//	print_node(*n[0]);
//	print_node(*n[3]);

	tree.clear(tree._root);

}
