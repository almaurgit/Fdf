/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:27:06 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 11:22:08 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_1(t_fdf *fdf)
{
	fdf->flag &= ~NOCOLOR;
	fdf->flag &= ~MAPCOLOR;
	fdf->flag |= COLORS;
	fdf->num_color = 0;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_2(t_fdf *fdf)
{
	fdf->flag &= ~NOCOLOR;
	fdf->flag &= ~MAPCOLOR;
	fdf->flag |= COLORS;
	fdf->num_color = 1;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_3(t_fdf *fdf)
{
	fdf->flag &= ~NOCOLOR;
	fdf->flag &= ~MAPCOLOR;
	fdf->flag |= COLORS;
	fdf->num_color = 2;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_4(t_fdf *fdf)
{
	fdf->flag &= ~NOCOLOR;
	fdf->flag &= ~MAPCOLOR;
	fdf->flag |= COLORS;
	fdf->num_color = 3;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_5(t_fdf *fdf)
{
	fdf->flag &= ~NOCOLOR;
	fdf->flag &= ~MAPCOLOR;
	fdf->flag |= COLORS;
	fdf->num_color = 4;
	map_foreach(fdf);
	draw_matrix(fdf);
}
