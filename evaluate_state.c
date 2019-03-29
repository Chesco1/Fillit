/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   evaluate_state.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 20:11:02 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/26 20:11:03 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	evaluate_state(t_list *node)
{
	int 	score;
	t_state	*state;

	state = node->STATE;
	score = ft_max(state->field_width, state->field_height);
	score += (node->N_UNPLACED_TETS) * 4;
	return (score);
}
