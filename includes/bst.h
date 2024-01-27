/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:17:51 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/27 10:53:27 by gfantoni         ###   ########.fr       */
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

void bst_simple_print(t_bst *node, int depth);
bool bst_verify(t_bst *node, int minkey, int maxkey);
t_bst* bst_create_node(int new_key);
t_bst *bst_insert(t_bst *node, int insert_key, bool *was_inserted);
int bst_find_minimum(t_bst *node);
int bst_find_maximum(t_bst *node);
bool bst_is_member(t_bst *node, int find_key);
t_bst *bst_delete_node(t_bst *node, int delete_key, bool *was_deleted);

void bst_pre_order(t_bst *node);
void bst_in_order(t_bst *node);
void bst_reverse_in_order(t_bst *node);
void bst_post_order(t_bst *node);
int bst_num_nodes(t_bst *node);
void bst_breadth_first(t_bst *node);

#endif