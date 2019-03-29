/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 19:56:34 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/26 19:56:35 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_state	*init_state(char *tets)
{
	t_state	*state;

	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	state->field_rows = NULL;
	state->unplaced_tets = tets;
	state->field_width = 0;
	state->field_height = 0;
	state->used_letters = 0x0;
	return (state);
}
