/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:42:36 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/27 12:36:27 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

int	main(void)
{
	t_bst	*tree1 = NULL;
	bool	was_inserted = false;
	int to_insert[] = {8,3,10,1,6,14,4,7,13};
	for (int i = 0; i < 9; i++) tree1 = bst_insert(tree1, to_insert[i], &was_inserted);
	printf("Breadth first: ");
	bst_breadth_first(tree1);
	printf("\n");

	tree1 = bst_delete_node(tree1, 8, &was_inserted);
	printf("Breadth first: ");
	bst_breadth_first(tree1);
	printf("\n");

	tree1 = bst_delete_node(tree1, 3, &was_inserted);
	printf("Breadth first: ");
	bst_breadth_first(tree1);
	printf("\n");

	tree1 = bst_delete_node(tree1, 6, &was_inserted);
	printf("Breadth first: ");
	bst_breadth_first(tree1);
	printf("\n");
}
