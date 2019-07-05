/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:23:17 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 15:12:36 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color_y(t_point start, t_point end, int y, int col[2])
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (col[0] == col[1])
		return (col[0]);
	percentage = percent(start[1], end[1], y);
	red = get_light((col[0] >> 16) & 0xFF, (col[1] >> 16) & 0xFF, percentage);
	green = get_light((col[0] >> 8) & 0xFF, (col[1] >> 8) & 0xFF, percentage);
	blue = get_light(col[0] & 0xFF, col[1] & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int		get_color_x(t_point start, t_point end, int x, int col[2])
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (col[0] == col[1])
		return (col[0]);
	percentage = percent(start[0], end[0], x);
	red = get_light((col[0] >> 16) & 0xFF, (col[1] >> 16) & 0xFF, percentage);
	green = get_light((col[0] >> 8) & 0xFF, (col[1] >> 8) & 0xFF, percentage);
	blue = get_light(col[0] & 0xFF, col[1] & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int		get_color_map(t_fdf *fdf, int x, int y)
{
	if (fdf->map[x][y][2] > 0.4 * (double)fdf->max_alt)
		return (0xFFFFFF);
	else if (fdf->map[x][y][2] > 0.1 * (double)fdf->max_alt)
		return (0x5B0000);
	else if (fdf->map[x][y][2] > 0.05 * (double)fdf->max_alt)
		return (0x008800);
	else if (fdf->map[x][y][2] > 0)
		return (0x00BB00);
	else if (fdf->map[x][y][2] < 0)
		return (0x777777);
	else if (fdf->map[x][y][2] == 0)
		return (0x0000FF);
	return (0);
}

int		get_color(t_fdf *fdf, int x, int y, int i)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;
	int		ret;

	red = 0;
	green = 0;
	blue = 0;
	if (fdf->flag & COLOR_INPUT)
		return (fdf->colors_input[x * fdf->dim_x + y]);
	else if (fdf->flag & COLORS)
	{
		percentage = percent(fdf->min_alt, fdf->max_alt, fdf->map[x][y][2]);
		red = get_light((fdf->colors[i][0] >> 16) & 0xFF,
						(fdf->colors[i][1] >> 16) & 0xFF, percentage);
		green = get_light((fdf->colors[i][0] >> 8) & 0xFF,
							(fdf->colors[i][1] >> 8) & 0xFF, percentage);
		blue = get_light(fdf->colors[i][0] & 0xFF,
						fdf->colors[i][1] & 0xFF, percentage);
	}
	else if ((ret = get_color_map(fdf, x, y)) > 0)
		return (ret);
	return ((red << 16) | (green << 8) | blue);
}
