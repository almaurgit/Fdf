/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:21:10 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 19:19:25 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	center(t_fdf *fdf, int i, int j)
{
	fdf->copy[i][j][0] += 1000;
	fdf->copy[i][j][1] += 600;
}

static void	move(t_fdf *fdf, int i, int j)
{
	fdf->copy[i][j][0] += fdf->move_x;
	fdf->copy[i][j][1] += fdf->move_y;
}

static void	zoom(t_fdf *fdf, int i, int j)
{
	fdf->copy[i][j][0] *= fdf->factor_zoom;
	fdf->copy[i][j][1] *= fdf->factor_zoom;
}

static void	factor_height(t_fdf *fdf, int i, int j)
{
	fdf->copy[i][j][2] *= fdf->factor_height;
}

void		map_foreach(t_fdf *fdf)
{
	int i;
	int j;

	i = -1;
	while (++i < fdf->dim_y)
	{
		j = -1;
		while (++j < fdf->dim_x)
		{
			fdf->copy[i][j][0] = fdf->map[i][j][0];
			fdf->copy[i][j][1] = fdf->map[i][j][1];
			fdf->copy[i][j][2] = fdf->map[i][j][2] * 0.05 * (double)fdf->dim_x;
			fdf->copy[i][j][2] /= (double)(fdf->max_alt - fdf->min_alt);
			factor_height(fdf, i, j);
			rot_x(fdf, i, j);
			rot_y(fdf, i, j);
			rot_z(fdf, i, j);
			if (fdf->flag & ISO)
				iso(fdf, i, j);
			zoom(fdf, i, j);
			move(fdf, i, j);
			center(fdf, i, j);
		}
	}
}
