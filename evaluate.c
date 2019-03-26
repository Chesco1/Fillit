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

int	evaluate_state(t_state *state)
{
	int score;

	score = ft_max(state->field_width, state->field_height);
	score += (state->n_unplaced_tets) * 4;
	return (score);
}
