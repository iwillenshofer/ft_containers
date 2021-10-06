/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/05 15:14:49 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_binarytree.hpp"
#include "./includes/ft_binarytree_iterator.hpp"
#include <iostream>


void print_node(ft::BinaryTree<char, int>::node_reference n)
{
	std::cout << "Key: " << n.Key();
	std::cout << ". Value: " << n.Value();
	std::cout << ". Address: " << &n;
	std::cout << ". Left: " << n._left;
	std::cout << ". Right: " << n._right;
	std::cout << ". Parent: " << n._parent << std::endl;
}

void display(ft::BinaryTree<char, int>::node_pointer root)
{
    if (!root )
   		return;
	display(root->_left);
	print_node(*root);
	display(root->_right);

}

int main(void)
{
//	ft::Node<int, char> n*(ft::make_pair(10, 'c'));

	ft::BinaryTree<char, int>::node_pointer n;
	ft::BinaryTree<char, int> tree;
	ft::BinaryTreeIterator<ft::Node<char, int> > it;

	tree.insert(ft::make_pair('k', 3));
	tree.insert(ft::make_pair('z', 3));
	tree.insert(ft::make_pair('c', 3));
	tree.insert(ft::make_pair('d', 2));
	tree.insert(ft::make_pair('g', 8));
  	tree.insert(ft::make_pair('e', 6));
	tree.insert(ft::make_pair('9', 3));
	tree.insert(ft::make_pair('y', 3));
	tree.insert(ft::make_pair('d', 9));
	tree.insert(ft::make_pair('g', 7));
	tree.insert(ft::make_pair('p', 5));
	tree.insert(ft::make_pair('x', 1));


//	display(tree._root);
//	std::cout << "after erase: " << std::endl;
	n =  tree.insert(ft::make_pair('g', 7)).first;
	it = ft::BinaryTreeIterator<ft::Node<char, int> >(tree._root->minimum());
	ft::BinaryTree<char, int>::iterator ite = tree.end();
//	tree.erase(n);
for (ft::BinaryTree<char, int>::reverse_iterator it = tree.rbegin(); it != tree.rend(); ++it)
{
	print_node(*it);
}
			
ft::BinaryTree<char, int>::const_iterator it2 = tree.end();
it2--;

//	display(tree._root);

	tree.clear(tree._root);
}
