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
		ft_lstinsert(cur_old, cur_new);
		cur_old = cur_new;
		cur_new = ft_lstdequeue(new);
	}
	return (*alst);
}

static t_list	*get_tet_moves(t_state *state, int tet_index)
{
	t_list	*moves;
	t_list	*current_line;
	t_pos	*move;
	int		tet_id;
	int		y;

	tet_id = state->unpalced_tets[tet_index];
	move = (t_pos*)malloc(sizeof(t_pos));
	move.y = 0;
	current_line = state->field;
	while (move.y <= state->field_height)
	{
		move.x = get_move(state, current_line, id);
		ft_lstorder(moves, place_tet(state, current_line, tet_index, move));
		current_line = current_line->next;
		move.y++;
	}
	return (moves);
}

t_list 			*get_valid_moves(t_list **alst)
{
	t_list	*current_node;
	t_list	*new_nodes;
	t_state	current_state;
	int		tet_stock;
	int		tet_index;

	current_node = ft_lstdequeue(alst);
	current_state = current_node->STATE;
	new_nodes = NULL;
	tet_index = 0;
	tet_stock = 0;
	while (tet_index < current_node->N_UNPLACED_TETS)
	{
		tet_index++;
		if (tet_stock & (1 << current_state->unpalced_tets[tet_index - 1]))
			continue ;
		tet_stock |= 1 << current_state->unpalced_tets[tet_index - 1];
		new_nodes = order_nodes(&new_nodes,\
						get_tet_moves(current_state, tet_index - 1), ft_substract);
	}
	*alst = order_nodes(alst, new_nodes, ft_substract);
	ft_lstnodedel(current_node);
	return (*alst);
}