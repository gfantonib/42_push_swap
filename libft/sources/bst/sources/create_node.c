/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:39:14 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/27 13:47:03 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

t_bst	*bst_create_node(int new_key)
{
	t_bst	*new_node;

	new_node = calloc(1, sizeof(t_bst));
	new_node->key = new_key;
	new_node->right_child = NULL;
	new_node->left_child = NULL;
	return (new_node);
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
		node->right_child
			= bst_insert(node->right_child, insert_key, was_inserted);
	}
	else if (insert_key < node->key)
	{
		node->left_child
			= bst_insert(node->left_child, insert_key, was_inserted);
	}	
	return (node);
}

t_bst	*bst_delete_node(t_bst *node, int delete_key, bool *was_deleted)
{
	*was_deleted = false;
	if (node == NULL)
		return (NULL);
	if (delete_key > node->key)
		node->right_child
			= bst_delete_node(node->right_child, delete_key, was_deleted);
	else if (delete_key < node->key)
		node->left_child
			= bst_delete_node(node->left_child, delete_key, was_deleted);
	else
	{
		if (node->left_child == NULL && node->right_child == NULL)
			return (left_right_child_null(node, was_deleted));
		else if (node->left_child == NULL)
			return (left_child_null(node, was_deleted));
		else if (node->right_child == NULL)
			return (right_child_null(node, was_deleted));
		else
			return (left_right_child(node, was_deleted));
	}		
	return (node);
}
