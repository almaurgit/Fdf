/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:55:38 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 15:15:08 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scrollup(t_fdf *fdf)
{
	if (fdf->factor_zoom <= 1.)
		fdf->factor_zoom *= 2.;
	else if (fdf->factor_zoom <= 10.)
		fdf->factor_zoom += 1.;
	else
		fdf->factor_zoom += 5;
	fdf->flag &= ~MOUSE_PRESS;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	scrolldown(t_fdf *fdf)
{
	if (fdf->factor_zoom <= 1.)
		fdf->factor_zoom /= 2.;
	else if (fdf->factor_zoom <= 10.)
		fdf->factor_zoom -= 1.;
	else
		fdf->factor_zoom -= 5;
	fdf->flag &= ~MOUSE_PRESS;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	but1(t_fdf *fdf)
{
	if (fdf->mouse_rot[1][0] != fdf->mouse_rot[0][0])
	{
		fdf->x_rot = fdf->mouse_rot[1][2] + fdf->mouse_rot[1][1];
		fdf->x_rot -= fdf->mouse_rot[0][1];
		fdf->y_rot = fdf->mouse_rot[0][2] + fdf->mouse_rot[1][0];
		fdf->y_rot -= fdf->mouse_rot[0][0];
	}
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	but2(t_fdf *fdf)
{
	if (fdf->mouse_move[1][0] != fdf->mouse_move[0][0])
	{
		fdf->move_x = fdf->mouse_move[1][2] + fdf->mouse_move[1][0];
		fdf->move_x -= fdf->mouse_move[0][0];
		fdf->move_y = fdf->mouse_move[0][2] + fdf->mouse_move[1][1];
		fdf->move_y -= fdf->mouse_move[0][1];
	}
	map_foreach(fdf);
	draw_matrix(fdf);
}
