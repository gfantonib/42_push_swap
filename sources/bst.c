#include "push_swap.h"

t_bst	*fill_bst_values(int ac, char **av)
{
	t_bst		*bst;
	long int	nb;
	int			i;
	bool	was_inserted;

	was_inserted = false;
	bst = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_long_atoi(av[i]);
		// if (nb > INT_MAX || nb < INT_MIN)
		// 	exit_error(&bst, NULL); // make error and free for tree
		bst = bst_insert(bst, nb, &was_inserted);
		i++;
	}
	return (bst);
}

void	bst_in_order_indexing(t_bst *node)
{
	static int bst_indexing;
	bst_indexing = 1;
	if (node == NULL)
		return ;
	bst_in_order_indexing(node->left_child);
	ft_printf ("%d ", node->key);
	node->index = bst_indexing;
	ft_printf ("%d ", node->index);
	bst_indexing++;
	bst_in_order_indexing(node->right_child);
}

// void	bst_in_order_idx(t_bst *node)
// {
// 	if (node == NULL)
// 		return ;
// 	bst_in_order_indexing(node->left_child);
// 	ft_printf ("key: %d | index: %d\n", node->key, node->index);
// 	bst_in_order_indexing(node->right_child);
// }