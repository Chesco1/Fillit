/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 12:09:41 by ccoers        #+#    #+#                 */
/*   Updated: 2019/03/22 15:37:25 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>

# define SIZE_TET 21
# define MAX_TETS 26
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

int		check_tetriminos(char *str, int **array);
int		ft_strcmp_ignore_nl(const char *s1, const char *s2);
int		ft_strequ_in(char const *s1, char const *s2, int **array);
int		fillit_solve(int **tet_array, int tet_amount);
int		input_is_valid(char *input, int **array);
char	*get_input(int fd);
char	*make_field(int tet_amount, int **tet_array, int i);
void	expand_field(char *field, int linelen, int **array);
void	place_tetrimino(int *tetrimino, char *index_field);
void	remove_tetrimino(int *tetrimino, char *index_field);

#endif
