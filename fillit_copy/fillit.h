/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 12:09:41 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/17 14:55:52 by ccoers        ########   odam.nl         */
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

int				check_tetriminos(char *str, int **tet_array);
int				ft_strcmp_ignore_nl(const char *s1, const char *s2);
int				ft_strequ_in(char const *s1, char const *s2,
				int **array);
int				fillit_solve(int **tet_array, int tet_amount);
int				input_is_valid(char *input, int **tet_array);
char			*get_input(int fd);
unsigned char	*make_field(int tet_amount, int **tet_array, int i);
void			expand_field(unsigned char *field, int linelen,
				int **array);
void    		place_tetrimino(int *tetrimino, unsigned char *index_field, 
				int j);
void			remove_tetrimino(int *tetrimino, unsigned char *index_field);
int     		index_latest_clone(int **tet_array, int *tetrimino, int i);
int				is_legal(int **tet_array, const int i,
				const unsigned char *field,
				const int j);
int				is_legal2(int **tet_array, const int i,
				const unsigned char *field,
				const int j);
int     		was_bad_move(int **tet_array, const int tet_index_at_call,
				unsigned char *field, const int strlen);
int				was_bad_move2(int **tet_array, const int tet_index_at_call,
				unsigned char *field, int *j);
unsigned char	get_max_dots(const int tet_amount);
void			clean_field(unsigned char *field, int **tet_array);
int 			count_dots(const unsigned char *field, const int *tetrimino);

#endif
