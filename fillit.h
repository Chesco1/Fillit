/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 12:09:41 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/01 18:26:27 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>

# define N_UNIQUE_TETS 19
# define SIZE_TET 21
# define MAX_TETS 26
# define LINE_LEN content_size
# define STATE content
# define SCORE value

# define T1 "####"
# define T2 "#...#...#...#"
# define T3 "##..##"
# define T4 "#...##...#"
# define T5 "##...##"
# define T6 "##.##"
# define T7 "#..##..#"
# define T8 "#...###"
# define T9 "##..#...#"
# define T10 "###...#"
# define T11 "#...#..##"
# define T12 "#.###"
# define T13 "#...#...##"
# define T14 "###.#"
# define T15 "##...#...#"
# define T16 "#..###"
# define T17 "#...##..#"
# define T18 "###..#"
# define T19 "#..##...#"

typedef struct		s_state
{
	s_list			*field_rows;
	char			*unplaced_tets;
	int				used_letters;
	char			n_unplaced_tets;
	char			field_width;
	char			field_height;
}					t_state;

typedef	struct		s_coordinates
{
	s_pos			pos1;
	s_pos			pos2;
	s_pos			pos3;
}					t_coordinates;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

int		ft_strcmp_ignore_nl(const char *s1, const char *s2);
int		ft_strequ_in(char const *s1, char const *s2, char *initial_tets);
int		input_is_valid(char *input, char *initial_tets);
char	*get_input(int fd);
int		check_tetriminos(char *str, char *initial_tets);
int		evaluate_state(t_state *state);
t_state	*init_state(char *tets, int n_tets);
t_state	*make_new_state(\
			t_state *state, t_list *current_line, int tet_index, t_pos *move);
int		get_move(\
			t_state *old_state, t_list *current_line, int id);

#endif
