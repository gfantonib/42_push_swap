/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:20:43 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/29 10:35:42 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

int	bst_find_minimum(t_bst *node)
{
	if (node == NULL)
	{
		ft_printf("ERROR: Cannot find minimum key of an empty BST.");
		return (INT_MIN);
	}	
	if (node->left_child == NULL)
		return (node->key);
	else
		return (bst_find_minimum(node->left_child));
}

int	bst_find_maximum(t_bst *node)
{
	if (node == NULL)
	{
		ft_printf("ERROR: Cannot find maximum key of an empty BST.");
		return (INT_MAX);
	}	
	if (node->right_child == NULL)
		return (node->key);
	else
		return (bst_find_maximum(node->right_child));
}
