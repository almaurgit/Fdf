/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:29:46 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 11:22:15 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_0(t_fdf *fdf)
{
	fdf->flag |= NOCOLOR;
	fdf->flag &= ~MAPCOLOR;
	fdf->flag &= ~COLORS;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_c(t_fdf *fdf)
{
	fdf->flag &= ~NOCOLOR;
	fdf->flag |= MAPCOLOR;
	fdf->flag &= ~COLORS;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_up(t_fdf *fdf)
{
	if (fdf->factor_height <= 1.)
		fdf->factor_height *= 2.;
	else
		fdf->factor_height += 1.;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_down(t_fdf *fdf)
{
	if (fdf->factor_height <= 1.)
		fdf->factor_height /= 2.;
	else
		fdf->factor_height -= 1.;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_n4(t_fdf *fdf)
{
	--fdf->y_rot;
	map_foreach(fdf);
	draw_matrix(fdf);
}
