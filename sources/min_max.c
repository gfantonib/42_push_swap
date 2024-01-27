/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:20:43 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/27 10:49:05 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

// Finds the minimum by repeatedly traversing the left subtree until we cannot
// anymore. 
int	bst_find_minimum(t_bst *node)
{
	// Handles an empty BST with a printf and returning INT_MIN... this isn't the 
	// only way we could handle this, but this is one acceptable way.
	if (node == NULL)
	{
		printf("ERROR: Cannot find minimum key of an empty BST.");
		return (INT_MIN);
	}	
	if (node->left_child == NULL)
		return (node->key);
	else
		return (bst_find_minimum(node->left_child));
}

// Finds the maximum by repeatedly traversing the right subtree until we cannot
// anymore. 
int	bst_find_maximum(t_bst *node)
{
	// Handles an empty BST with a printf and returning INT_MAX... this isn't the 
	// only way we could handle this, but this is one acceptable way.  
	if (node == NULL)
	{
		printf("ERROR: Cannot find maximum key of an empty BST.");
		return (INT_MAX);
	}	
	if (node->right_child == NULL)
		return (node->key);
	else
		return (bst_find_maximum(node->right_child));
}