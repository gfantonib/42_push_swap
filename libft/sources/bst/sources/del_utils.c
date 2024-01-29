/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:37:55 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/27 13:47:06 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

t_bst	*left_right_child_null(t_bst *node, bool *was_deleted)
{
	*was_deleted = true;
	free(node);
	return (NULL);
}

t_bst	*left_child_null(t_bst *node, bool *was_deleted)
{
	t_bst	*temp;

	*was_deleted = true;
	temp = node->right_child;
	free(node);
	return (temp);
}

t_bst	*right_child_null(t_bst *node, bool *was_deleted)
{
	t_bst	*temp;

	*was_deleted = true;
	temp = node->left_child;
	free(node);
	return (temp);
}

t_bst	*left_right_child(t_bst *node, bool *was_deleted)
{
	int		min_of_right_subtree;

	*was_deleted = true;
	min_of_right_subtree = bst_find_minimum(node->right_child);
	node->key = min_of_right_subtree;
	node->right_child = bst_delete_node(
			node->right_child, min_of_right_subtree, was_deleted);
	return (node);
}
