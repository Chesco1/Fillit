/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_new_state.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 14:21:05 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/05 14:21:05 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static char	set_char(int *used_letters, int index)
{
	int	unused_letters_seen;
	int	letter;
	int	bit_pointer;

	unused_letters_seen = 0;
	bit_pointer = 0x1;
	letter = 0;
	while (unused_letters_seen <= index)
	{
		if (~(*used_letters) & bit_pointer)
			unused_letters_seen++;
		if (unused_letters_seen == index)
			(*used_letters) |= bit_pointer;
		else
		{
			letter++;
			bit_pointer <<= 1;
		}
	}
	return ((unsigned char)(letter + 'A'));
}

static char	*set_unplaced_tets(\
	t_state *old_state, int n_unplaced_tets, int tet_index)
{
	char	*unplaced_tets;

	unplaced_tets = (char*)malloc(sizeof(char) * n_unplaced_tets);
	unplaced_tets = ft_memcpy(\
		unplaced_tets, old_state->unplaced_tets, tet_index);
	unplaced_tets[tet_index] = ft_memcpy(\
		unplaced_tets[tet_index], old_state->unplaced_tets[tet_index + 1],\
		n_unplaced_tets - tet_index);
	return (unplaced_tets);
}

t_state		*make_new_state(\
	t_state *state, t_list *current_line, int tet_index, t_pos *move)
{
	t_state	*new_state;
	char	c;

	new_state = (t_state*)malloc(sizeof(t_state));
	new_state->n_unplaced_tets = (state->n_unplaced_tets) - 1;
	new_state->unplaced_tets = set_unplaced_tets(\
		state, new_state->n_unplaced_tets, tet_index);
	new_state->used_letters = state->used_letters;
	c = set_char(&(new_state->used_letters), tet_index);
	return (new_state);
}
