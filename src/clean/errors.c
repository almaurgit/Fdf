/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:51:12 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 13:36:58 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error(t_fdf *fdf, int err)
{
	static char *g_error[] = {
		"An unknown error has occured",
		"Malloc error.",
		"Invalid file name.",
		"Empty file.",
		"Invalid file : an altitude is not an integer at line "
	};

	if (!(err >= -4 && err <= 0))
	{
		ft_putendl(g_error[0]);
		clean_file(fdf);
		return (0);
	}
	ft_putstr(g_error[err * (-1)]);
	if (err == err_int)
		ft_putnbr(fdf->err_line);
	write(1, "\n", 1);
	usage(fdf);
	clean_file(fdf);
	return (1);
}

void	usage(t_fdf *fdf)
{
	ft_putendl("usage: ./fdf [-ch] <filename>");
	if (!(fdf->flag & HELP))
		return ;
	ft_putendl("         -c: for maps with explicit colors");
	ft_putendl("         -h: help");
	ft_putendl("file format: Matrix of integers representing altitudes");
	ft_putendl("             separated by spaces or tabs on each column,");
	ft_putendl("             and by a new line on each line.");
	ft_putendl("             Each altitude must have this format :");
	ft_putendl("             N[,H], with N as a decimal int");
	ft_putendl("             and H as an hexadecimal int (starting with 0x,");
	ft_putendl("             and only when -c option is activated");
	ft_putendl("While on screen, press 'H' to display help");
}
