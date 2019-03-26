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
	int		i;
	int		fd;
	int		tet_amount;
	char	*input;
	char	*initial_tets;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		input = get_input(fd);
		tet_amount = (ft_strlen(input) + 1) / 21;
		initial_tets = (char *)malloc(sizeof(char) * (tet_amount));
		if (fd == -1)
		{
			ft_putendl("error opening file");
			return (0);
		}
		if (input_is_valid(input, initial_tets) == 1)
		{
			i = 0;
			while (i < tet_amount)
			{
				ft_putnbr(initial_tets[i]);
				i++;
				ft_putchar(' ');
			}
		}
		else
			ft_putendl("error"); 
	}
	else
		ft_putendl("something something usage");
	return (0);
}
