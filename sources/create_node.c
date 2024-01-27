/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:23:44 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/27 10:41:31 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

t_bst*	bst_create_node(int new_key)
{
	t_bst *newNode = calloc(1, sizeof(t_bst));
	newNode->key = new_key;
	newNode->right_child = NULL;
	newNode->left_child = NULL;
	return (newNode);
}

t_bst	*bst_insert(t_bst *node, int insert_key, bool *was_inserted)
{
	*was_inserted = false;	
	
	if (node == NULL)
	{
		*was_inserted = true;
		return (bst_create_node(insert_key));
	}

	else if (insert_key > node->key)
	{
		node->right_child = bst_insert(node->right_child, insert_key, was_inserted);
	}

	else if (insert_key < node->key)
	{
		node->left_child = bst_insert(node->left_child, insert_key, was_inserted);
	}	

	return (node);
}

t_bst *bst_delete_node(t_bst *node, int delete_key, bool *was_deleted)
{
	t_bst *temp;
	int min_of_right_subtree;
	
	*was_deleted = false;
	
	if (node == NULL)
		return (NULL);	
	if (delete_key > node->key)
	{
		node->right_child = bst_delete_node(node->right_child, delete_key, was_deleted);
	}
	else if (delete_key < node->key)
	{
	  	node->left_child = bst_delete_node(node->left_child, delete_key, was_deleted);    
	}
	else
	{
	  	if (node->left_child == NULL && node->right_child == NULL)
	  	{
			*was_deleted = true;
			free(node);
			return (NULL);
	  	}
	  	else if (node->left_child == NULL)
	  	{
			*was_deleted = true;
			temp = node->right_child;
			free(node);
			return (temp);
	  	}
	  	else if (node->right_child == NULL)
	  	{
			*was_deleted = true;
			temp = node->left_child;
			free(node);
			return (temp);
	  	}
	  	else 
	  	{
			*was_deleted = true;
			min_of_right_subtree = bst_find_minimum(node->right_child);
			node->key = min_of_right_subtree;
			node->right_child = bst_delete_node(node->right_child, min_of_right_subtree, was_deleted);
			return (node);
	  	}
	}		
	return (node);
}