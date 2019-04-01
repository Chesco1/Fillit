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

# define SIZE_TET 21
# define MAX_TETS 26
# define STATE content
# define SCORE value
# define N_UNPLACED_TETS content_size

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
	char			**field_rows;
	char			*unplaced_tets;
	char			field_width;
	char			field_height;
	char			used_letters;
}					t_state;

typedef struct      s_coordinates
{
    int				x_1;
	int 			y_1;
	int	    	    x_2;
    int	    	    y_2;
	int	    	    x_3;
    int	    	    y_3;
}                   t_coordinates;

int		ft_strcmp_ignore_nl(const char *s1, const char *s2);
int		ft_strequ_in(char const *s1, char const *s2, char *initial_tets);
int		input_is_valid(char *input, char *initial_tets);
char	*get_input(int fd);
int		check_tetriminos(char *str, char *initial_tets);
int		evaluate_state(t_list *node);
t_state	*init_state(char *tets);

#endif
