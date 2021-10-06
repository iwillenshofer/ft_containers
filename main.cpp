/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/06 16:32:11 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_binarytree.hpp"
#include "./includes/ft_binarytree_iterator.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


void print_node(ft::BinaryTree<int, int>::node_reference n)
{
	std::cout << "Key: " << n.Key();
	std::cout << ". Value: " << n.Value();
	std::cout << ". Address: " << &n;
	std::cout << ". Left: " << n._left;
	std::cout << ". Right: " << n._right;
	std::cout << ". Parent: " << n._parent;
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
//	ft::BinaryTree<int, int>::node_pointer n[50];
	ft::BinaryTree<int, int> tree;
	ft::BinaryTreeIterator<ft::Node<int, int> > it;

	tree.insert(ft::make_pair(35, 3));
	srand (time(NULL));

	for (int i = 0; i < 1000; i++)
		tree.insert(ft::make_pair(rand() % 10000 + 1, 3));
//n[2]=	tree.insert(ft::make_pair(31, 3)).first;
//n[3]=	tree.insert(ft::make_pair(19, 3)).first;
//n[4]=	tree.insert(ft::make_pair(14, 3)).first;
//n[5]=	tree.insert(ft::make_pair(27, 3)).first;
//n[6]=	tree.insert(ft::make_pair(10, 3)).first;




	//tree.insert(ft::make_pair(27, 3));
	//tree.insert(ft::make_pair(10, 3));



//	display(tree._root);
//	std::cout << "after erase: " << std::endl;
//	n =  tree.insert(ft::make_pair('g', 7)).first;
//	it = ft::BinaryTreeIterator<ft::Node<char, int> >(tree._root->minimum());
//	ft::BinaryTree<char, int>::iterator ite = tree.end();
//	tree.erase(n);
for (ft::BinaryTree<int, int>::iterator it = tree.begin(); it != tree.end(); ++it)
{
	print_node(*it);
}

ft::BinaryTree<int, int>::const_iterator it2 = tree.end();
it2--;

	print_tree(tree._root);
//	display(tree._root);
//	print_node(*n[2]);
//	print_node(*n[3]);

	tree.clear(tree._root);

}
