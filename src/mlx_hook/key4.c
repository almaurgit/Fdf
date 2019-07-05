/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:47:08 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 14:46:19 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_a(t_fdf *fdf)
{
	fdf->move_x += 10;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_d(t_fdf *fdf)
{
	fdf->move_x -= 10;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_s(t_fdf *fdf)
{
	fdf->move_y -= 10;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_w(t_fdf *fdf)
{
	fdf->move_y += 10;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_r(t_fdf *fdf)
{
	fdf->x_rot = 0;
	fdf->y_rot = 0;
	fdf->z_rot = 0;
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->factor_height = 1.;
	fdf->factor_zoom = 500. / (double)ft_max(fdf->dim_x, fdf->dim_y);
	map_foreach(fdf);
	draw_matrix(fdf);
}
