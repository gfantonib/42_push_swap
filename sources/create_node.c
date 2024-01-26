/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bst_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:23:44 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/26 16:31:35 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"


// Creates a new BST node with the given key
t_bst*	create_node(int new_key)
{
	t_bst *newNode = calloc(1, sizeof(t_bst));
	newNode->key = new_key;
	newNode->right_child = NULL;
	newNode->left_child = NULL;
	return (newNode);
}

// Inserts a node in a BST with insert_key.  Sets was_inserted to true if a new 
// node actually had to be inserted.
t_bst	*insert(t_bst *node, int insert_key, bool *was_inserted)
{
	*was_inserted = false;	
	// In the case of an empty tree, or that we have reached a NULL pointer, we 
	// create the node and return it
	if (node == NULL)
	{
		*was_inserted = true;
		return (create_node(insert_key));
	}
	// If the key to insert is greater than the current key, traverse the right
	// subtree to continue to look for the correct position to insert the key.
	// We keep setting the node pointers as we traverse the tree because we 
	// may modify the pointers... e.g. if right_child is NULL in this case, then 
	// on the next function call we'll be returning a new node (with the above) 
	// code, and we'll want right_child to point to that new node.  Otherwise 
	// we'll want it to keep pointing to the node it was pointing to before, 
	// which is achieved with the return node statement below.  
	else if (insert_key > node->key)
	{
		node->right_child = insert(node->right_child, insert_key, was_inserted);
	}
	// Same idea as above, except we traverse the left subtree if the key to 
	// insert is less than the current node's key.
	else if (insert_key < node->key)
	{
		node->left_child = insert(node->left_child, insert_key, was_inserted);
	}	
	// Returns the current node, this run if we are traversing the tree and 
	// are returning the existing left or right child node of another node, 
	// OR if we have found a node where insert_key == node->key in which case 
	// we are not actually needing to create a new node.
	return (node);
}

// Deletes a node with delete_key from a tree if it exists.  Sets was_deleted 
// true if a deletion actually occurs and false otherwise.
t_bst *delete_node(t_bst *node, int delete_key, bool *was_deleted)
{
	*was_deleted = false;
	// in the case of an empty tree we can simple return false
	if (node == NULL)
		return (NULL);	
	// If the key we are attempting to delete_node is greater than the current node's 
	// key than we traverse the right-subtree.  As with insert we're effectively 
	// "re-setting" the pointers as we traverse the tree given that our delete_node 
	// operation may alter the tree structure (like deleting a node).
	if (delete_key > node->key)
	{
		node->right_child = delete_node(node->right_child, delete_key, was_deleted);
	}
	// The same as above, except we traverse the left-subtree in the case the 
	// key we are attempting to delete_node is lower than the current node's key.
	else if (delete_key < node->key)
	{
	  	node->left_child = delete_node(node->left_child, delete_key, was_deleted);    
	}
	// in this case, we need to delete_node a node because we have found the key
	else
	{
	  	// if the node has no children, it is simple, we free the node, return NULL
	  	if (node->left_child == NULL && node->right_child == NULL)
	  	{
			*was_deleted = true;
			free(node);
			return (NULL);
	  	}
	  	// if the node has one RIGHT child, we return that child, and free the node
	  	else if (node->left_child == NULL)
	  	{
			*was_deleted = true;
			t_bst *temp = node->right_child;
			free(node);
			return (temp);
	  	}
	  	// if the node has one LEFT child, we return that child, and free the node
	  	else if (node->right_child == NULL)
	  	{
			*was_deleted = true;
			t_bst *temp = node->left_child;
			free(node);
			return (temp);
	  	}
	  	// If the node has 2 children we replace it with the minimum value of the 
	  	// node's right-subtree.  We do this because this value is known to be 
	  	// higher than all of the node's left subtree values, AND lower than all 
	  	// of the node's (other) right subtree values.  After setting the node to 
	  	// this new key value, we delete_node the node with that key from the right 
	  	// subtree (using the same function), and return the node.
	  	else 
	  	{
			*was_deleted = true;
			int min_of_right_subtree = find_minimum(node->right_child);
			node->key = min_of_right_subtree;
			node->right_child = delete_node(node->right_child, min_of_right_subtree, was_deleted);
			return (node);
	  	}
	}		
	// Will be returned as we traverse the tree in the case that no deletion 
	// occurs... the left_child or right_child of the node that called this 
	// function will be set to the previous left_child or right_child in this
	// case.
	return (node);
}