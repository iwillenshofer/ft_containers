/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/04 18:09:26 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_binarytree.hpp"
#include <iostream>


void print_node(ft::BinaryTree<char, int>::node_pointer n)
{
	std::cout << "Key: " << n->Key();
	std::cout << ". Value: " << n->Value();
	std::cout << ". Address: " << n;
	std::cout << ". Left: " << n->_left;
	std::cout << ". Right: " << n->_right;
	std::cout << ". Parent: " << n->_parent << std::endl;
}

void display(ft::BinaryTree<char, int>::node_pointer root)
{
    if (!root)
   		return;
	display(root->_left);
	print_node(root);
	display(root->_right);

}

int main(void)
{
//	ft::Node<int, char> n*(ft::make_pair(10, 'c'));

	ft::BinaryTree<char, int>::node_pointer n;
	ft::BinaryTree<char, int> tree;


	tree.insert(ft::make_pair('k', 3));
	tree.insert(ft::make_pair('z', 3));

	tree.insert(ft::make_pair('c', 3));

	tree.insert(ft::make_pair('d', 26));
	tree.insert(ft::make_pair('g', 26));

  tree.insert(ft::make_pair('e', 26));
 
	tree.insert(ft::make_pair('9', 3));

	tree.insert(ft::make_pair('y', 3));

	tree.insert(ft::make_pair('d', 26));
	tree.insert(ft::make_pair('g', 26));

n=	tree.insert(ft::make_pair('p', 26));
	tree.insert(ft::make_pair('x', 26));


	display(tree._root);
	tree.erase(n);
	std::cout << "after erase: " << std::endl;
	display(tree._root);

	tree.clear(tree._root);
}
