/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_pos_slope.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:44:01 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/02 17:17:27 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	draw_line_pos(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	int dx;
	int dy;
	int e;
	int x;
	int y;

	dx = b[0] - a[0];
	dy = b[1] - a[1];
	e = 0;
	x = a[0];
	y = a[1];
	while (x <= b[0])
	{
		if (fdf->flag & NOCOLOR)
			fill_pixel(fdf->img_str, x, y, 0xFFFFFF);
		else
			fill_pixel(fdf->img_str, x, y, get_color_x(a, b, x, color));
		e += dy;
		if ((e << 1) >= dx)
		{
			++y;
			e -= dx;
		}
		x++;
	}
}

void	draw_line_pos2(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	int dx;
	int dy;
	int e;
	int x;
	int y;

	dx = a[0] - b[0];
	dy = b[1] - a[1];
	e = 0;
	x = a[0];
	y = a[1];
	while (x >= b[0])
	{
		if (fdf->flag & NOCOLOR)
			fill_pixel(fdf->img_str, x, y, 0xFFFFFF);
		else
			fill_pixel(fdf->img_str, x, y, get_color_x(a, b, x, color));
		e += dy;
		if ((e << 1) >= dx)
		{
			++y;
			e -= dx;
		}
		x--;
	}
}

void	draw_line_pos3(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	int dx;
	int dy;
	int e;
	int x;
	int y;

	dx = b[0] - a[0];
	dy = b[1] - a[1];
	e = 0;
	x = a[0];
	y = a[1];
	while (y <= b[1])
	{
		if (fdf->flag & NOCOLOR)
			fill_pixel(fdf->img_str, x, y, 0xFFFFFF);
		else
			fill_pixel(fdf->img_str, x, y, get_color_y(a, b, y, color));
		e += dx;
		if ((e << 1) >= dy)
		{
			++x;
			e -= dy;
		}
		y++;
	}
}

void	draw_line_pos4(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	int dx;
	int dy;
	int e;
	int x;
	int y;

	dx = a[0] - b[0];
	dy = b[1] - a[1];
	e = 0;
	x = a[0];
	y = a[1];
	while (y <= b[1])
	{
		if (fdf->flag & NOCOLOR)
			fill_pixel(fdf->img_str, x, y, 0xFFFFFF);
		else
			fill_pixel(fdf->img_str, x, y, get_color_y(a, b, y, color));
		e += dx;
		if ((e << 1) >= dy)
		{
			--x;
			e -= dy;
		}
		++y;
	}
}
