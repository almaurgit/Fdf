/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_neg_slope.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:42:03 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/03 20:12:14 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	draw_line_neg(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	int dx;
	int dy;
	int e;
	int x;
	int y;

	dx = b[0] - a[0];
	dy = a[1] - b[1];
	e = 0;
	x = a[0];
	y = a[1];
	while (x <= b[0])
	{
		if (fdf->flag & NOCOLOR)
			fill_pixel(fdf->img_str, x, y, 0xFFFFFF);
		else
			fill_pixel(fdf->img_str, x, y, get_color_x(a, b, x, color));
		e -= dy;
		if ((e << 1) <= -1 * dx)
		{
			--y;
			e += dx;
		}
		x++;
	}
}

void	draw_line_neg2(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	int dx;
	int dy;
	int e;
	int x;
	int y;

	dx = a[0] - b[0];
	dy = a[1] - b[1];
	e = 0;
	x = a[0];
	y = a[1];
	while (x >= b[0])
	{
		if (fdf->flag & NOCOLOR)
			fill_pixel(fdf->img_str, x, y, 0xFFFFFF);
		else
			fill_pixel(fdf->img_str, x, y, get_color_x(a, b, x, color));
		e -= dy;
		if ((e << 1) <= -1 * dx)
		{
			--y;
			e += dx;
		}
		x--;
	}
}

void	draw_line_neg3(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	int dx;
	int dy;
	int e;
	int x;
	int y;

	dx = b[0] - a[0];
	dy = a[1] - b[1];
	e = 0;
	x = a[0];
	y = a[1];
	while (y >= b[1])
	{
		if (fdf->flag & NOCOLOR)
			fill_pixel(fdf->img_str, x, y, 0xFFFFFF);
		else
			fill_pixel(fdf->img_str, x, y, get_color_y(a, b, y, color));
		e -= dx;
		if ((e << 1) <= -1 * dy)
		{
			++x;
			e += dy;
		}
		y--;
	}
}

void	draw_line_neg4(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	int dx;
	int dy;
	int e;
	int x;
	int y;

	dx = a[0] - b[0];
	dy = a[1] - b[1];
	e = 0;
	x = a[0];
	y = a[1];
	while (y >= b[1])
	{
		if (fdf->flag & NOCOLOR)
			fill_pixel(fdf->img_str, x, y, 0xFFFFFF);
		else
			fill_pixel(fdf->img_str, x, y, get_color_y(a, b, y, color));
		e -= dx;
		if ((e << 1) <= -1 * dy)
		{
			--x;
			e += dy;
		}
		y--;
	}
}
