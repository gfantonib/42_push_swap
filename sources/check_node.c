/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bst_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:25:54 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/26 16:31:21 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

// Verifies that a tree defined with t_bst actually conforms to BST 
// requirements.  It works by progressively tightening the acceptable range 
// of values for a key as it rescursively traverses the tree, by setting a 
// new max and/or min depending on the value of the current key and the 
// direction of the travesal.  If ever a key is out of range, we return 
// false, and if we encounter leaf nodes (or an empty tree) we return true, 
// and by continually "and-ing" the results we're able to verify the structure.
bool	verifyBST(t_bst *node, int minkey, int maxkey) 
{
    if (node == NULL)
		return (true);
    if (node->key < minkey || node->key > maxkey) 
		return (false);    
    return (verifyBST(node->left_child, minkey, node->key - 1) && verifyBST(node->right_child, node->key + 1, maxkey));
}


// Determines whether or not a key is a member of a BST or not.  It traverses 
// the tree until it finds where the node "should" be either because it finds 
// the node with that key, or it finds a NULL (either an empty list, or an 
// empty left or child child pointer).
bool	is_member(t_bst *node, int find_key)
{
	if (node == NULL)
		return (false);
	else if (find_key > node->key)
		return (is_member(node->right_child, find_key));
	else if (find_key < node->key)
		return (is_member(node->left_child, find_key));
	else 
		return (true);
}

// Returns the total number of nodes in a BST
int	num_nodes(t_bst *node)
{
	if (node == NULL) 
		return (0);
	else
		return (1 + num_nodes(node->right_child) + num_nodes(node->left_child));
}