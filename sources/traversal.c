/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:19:41 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/27 11:03:14 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

void	bst_pre_order(t_bst *node)
{
	if (node == NULL)
		return ;
	printf("%d ", node->key);
	bst_pre_order(node->left_child);
	bst_pre_order(node->right_child);
}

void	bst_in_order(t_bst *node)
{
	if (node == NULL)
		return ;
	bst_in_order(node->left_child);
	printf ("%d ", node->key);
	bst_in_order(node->right_child);
}

void	bst_reverse_in_order(t_bst *node)
{
	if (node == NULL)
		return ;
	bst_reverse_in_order(node->right_child);
	printf("%d ", node->key);
	bst_reverse_in_order(node->left_child);
}

void	bst_post_order(t_bst *node)
{
	if (node == NULL)
		return ;
	bst_post_order(node->left_child);
	bst_post_order(node->right_child);
	printf("%d ", node->key);
}
