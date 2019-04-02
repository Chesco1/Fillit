/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:09:24 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/23 16:09:25 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*input;
	int		**tet_array;
	int		tet_amount;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		input = get_input(fd);
		tet_amount = (ft_strlen(input) + 1) / 21;
		tet_array = (int **)malloc(sizeof(int *) * (tet_amount + 1));
		if (fd == -1)
		{
			ft_putendl("error opening file");
			return (0);
		}
		if (input_is_valid(input, tet_array) == 1)
		{
			tet_array[tet_amount] = NULL;
//			ft_putendl("valid input");
			fillit_solve(tet_array, tet_amount);
		}
		else
			ft_putendl("error"); 
	}
	else
		ft_putendl("something something usage");
	return (0);
}