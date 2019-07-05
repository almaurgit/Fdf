/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:30:23 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 19:02:48 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_matrix_1(t_fdf *fdf, int color[2])
{
	int i;
	int j;

	i = 0;
	while (i < fdf->dim_y)
	{
		j = 0;
		while (j < fdf->dim_x)
		{
			if (fdf->flag & COLORS || fdf->flag & MAPCOLOR)
				color[0] = get_color(fdf, i, j, fdf->num_color);
			if ((fdf->flag & COLORS || fdf->flag & MAPCOLOR)
					&& j < fdf->dim_x - 1)
				color[1] = get_color(fdf, i, j + 1, fdf->num_color);
			if (j < fdf->dim_x - 1)
				draw_line(fdf, fdf->copy[i][j], fdf->copy[i][j + 1], color);
			if ((fdf->flag & COLORS || fdf->flag & MAPCOLOR)
					&& i < fdf->dim_y - 1)
				color[1] = get_color(fdf, i + 1, j, fdf->num_color);
			if (i < fdf->dim_y - 1)
				draw_line(fdf, fdf->copy[i][j], fdf->copy[i + 1][j], color);
			++j;
		}
		++i;
	}
}

void		draw_matrix(t_fdf *fdf)
{
	int color[2];

	ft_bzero(fdf->img_str, sizeof(char) * 1200 * 2000 * 4);
	ft_bzero(color, sizeof(color));
	draw_matrix_1(fdf, color);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
