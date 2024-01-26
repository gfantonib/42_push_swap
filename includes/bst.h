/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:17:51 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/26 16:43:29 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_H
# define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_bst 
{
	int key;
	struct s_bst *left_child;
	struct s_bst *right_child; 
}		t_bst;

void simple_print(t_bst *node, int depth);
bool verifyBST(t_bst *node, int minkey, int maxkey);
t_bst* create_node(int new_key);
t_bst *insert(t_bst *node, int insert_key, bool *was_inserted);
int find_minimum(t_bst *node);
int find_maximum(t_bst *node);
bool is_member(t_bst *node, int find_key);
t_bst *delete_node(t_bst *node, int delete_key, bool *was_deleted);

void pre_order(t_bst *node);
void in_order(t_bst *node);
void reverse_in_order(t_bst *node);
void post_order(t_bst *node);
int num_nodes(t_bst *node);
void breadth_first(t_bst *node);

#endif