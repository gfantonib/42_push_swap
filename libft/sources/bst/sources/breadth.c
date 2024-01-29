/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:03:23 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/29 10:36:15 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

static void	bst_breadth(t_bst **queue, int front, int total, int rear);

void	bst_simple_print(t_bst *node, int depth)
{
	int	i;

	if (node == NULL)
		return ;
	i = 0;
	while (i < (depth * 3))
	{
		ft_printf(" ");
		i++;
	}
	ft_printf("%d\n", node->key);
	bst_simple_print(node->left_child, depth + 1);
	bst_simple_print(node->right_child, depth + 1);
}

void	bst_breadth_first(t_bst *node)
{	
	t_bst	**queue;
	int		total;
	int		front;
	int		rear;

	total = bst_num_nodes(node);
	queue = calloc(total, sizeof(t_bst *));
	front = 0;
	rear = 1;
	if (node == NULL)
		return ;
	queue[front] = node;
	bst_breadth(queue, front, total, rear);
}

static void	bst_breadth(t_bst **queue, int front, int total, int rear)
{
	while (front < total)
	{
		ft_printf("%d ", queue[front]->key);
		if (queue[front]->left_child != NULL)
		{
			queue[rear] = queue[front]->left_child;
			rear++;
		}
		if (queue[front]->right_child != NULL)
		{
			queue[rear] = queue[front]->right_child;
			rear++;
		}
		front++;
	}
}
