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

t_list	*init_field(char *tets, int n_tets)
{
	t_list	*field;
	char	*row;
	int		i;
	int		n;

	n = ft_sqrt_floor(4 * n_tets);
	row = (char*)malloc(sizeof(char) * n);
	row = ft_memset('.', n);
	field = ft_lstnew(row, n);
	if (!field)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ft_lstadd(&field, ft_lstnew(row, n));
		i++;
	}
	free(row);
	return (field);
}

t_state	*init_state(char *tets, int n_tets)
{
	t_state	*state;

	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	state->field_rows = init_field(tets, n_tets);
	state->unplaced_tets = tets;
	state->n_unplaced_tets = n_tets;
	state->field_width = 0;
	state->field_height = 0;
	state->used_letters = 0x0;
	return (state);
}
