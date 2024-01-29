/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:25:54 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/27 13:46:59 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

bool	bst_verify(t_bst *node, int minkey, int maxkey)
{
	if (node == NULL)
		return (true);
	if (node->key < minkey || node->key > maxkey)
		return (false);
	return (bst_verify(node->left_child, minkey, node->key - 1)
		&& bst_verify(node->right_child, node->key + 1, maxkey));
}

bool	bst_is_member(t_bst *node, int find_key)
{
	if (node == NULL)
		return (false);
	else if (find_key > node->key)
		return (bst_is_member(node->right_child, find_key));
	else if (find_key < node->key)
		return (bst_is_member(node->left_child, find_key));
	else
		return (true);
}

int	bst_num_nodes(t_bst *node)
{
	if (node == NULL)
		return (0);
	else
		return (1 + bst_num_nodes(node->right_child)
			+ bst_num_nodes(node->left_child));
}
