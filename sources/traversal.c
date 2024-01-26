/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:19:41 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/26 16:32:29 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

// Prints out a BST using a pre-order depth-first traversal
void	pre_order(t_bst *node)
{
	if (node == NULL)
		return ;
	printf("%d ", node->key);
	pre_order(node->left_child);
	pre_order(node->right_child);
}

// Prints out a BST using a in-order depth-first traversal
void	in_order(t_bst *node)
{
	if (node == NULL)
		return ;
	in_order(node->left_child);
	printf ("%d ", node->key);
	in_order(node->right_child);
}

// Prints out a BST using a reverse in-order depth-first traversal
void	reverse_in_order(t_bst *node)
{
	if (node == NULL)
		return ;
	reverse_in_order(node->right_child);
	printf("%d ", node->key);
	reverse_in_order(node->left_child);
}

// Prints out a BST using a post-order depth-first traversal
void	post_order(t_bst *node)
{
	if (node == NULL)
		return ;
	post_order(node->left_child);
	post_order(node->right_child);
	printf("%d ", node->key);
}


// Prints out a BST using depth to offset the key
void	simple_print(t_bst *node, int depth)
{
	if (node == NULL)
		return ;
	for (int i = 0; i < (depth * 3); i++)
		printf(" ");
	printf("%d\n", node->key);
	simple_print(node->left_child, depth + 1);
	simple_print(node->right_child, depth + 1);
}

// Breadth-first traveral of a BST
void	breadth_first(t_bst *node)
{	
	// nothing needs to be done for an empty tree
	if (node == NULL)
		return ;

	// Create a queue large enough to hold pointers to all nodes in the BST
	// set the front to the first element and rear to the next, and put the 
	// root node as the current node in the queue.
	int total = num_nodes(node);
	t_bst **queue = calloc(total, sizeof(t_bst*));
	int front = 0, rear = 1;

	// For each node, place its left and right children on he queue, and then 
	// increment the front of the queue
	queue[front] = node;
	while (front < total)
	{
		printf("%d ", queue[front]->key);
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