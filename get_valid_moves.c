/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_valid_moves.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 16:47:21 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/29 16:47:22 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_substract(int x, int y)
{
	return (x - y);
}

static t_list	*ft_lstorder(t_list **alst, t_list **new, int (*f)(int, int))
{
	t_list	*cur_old;
	t_list	*cur_new;

	cur_old = *alst;
	if (!cur_old)
	{
		*alst = cur_new;
		return (*alst);
	}
	cur_new = ft_lstdequeue(new);
	while (cur_new)
	{
		while (cur_old->next && f(cur_old->next->SCORE, cur_new->SCORE) >= 0)
			cur_old = cur_old->next;
		cur_old = ft_lstinsert(cur_old, cur_new);
		cur_new = ft_lstdequeue(new);
	}
	return (*alst);
}

static t_list	*get_tet_moves()

t_list 			*get_valid_moves(t_list **alst)
{
	t_list	*current_node;
	t_list	*new_nodes;
	t_state	current_state;
	int		tet_index;

	current_node = ft_lstdequeue(alst);
	current_state = current_node->STATE;
	new_nodes = NULL;
	tet_index = 0;
	while (tet_index < current_node->N_UNPLACED_TETS)
	{
		new_nodes = order_nodes(&new_nodes,\
						get_tet_moves(current_state, tet_index), ft_substract);
		tet_index++;
	}
	*alst = order_nodes(alst, new_nodes, ft_substract);
	ft_lstnodedel(current_node);
	return (*alst);
}