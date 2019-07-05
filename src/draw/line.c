/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:45:30 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 13:45:11 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_pixel(char *img_str, int x, int y, int color)
{
	t_color tmp;

	tmp = *(t_color *)&color;
	if (x < 0 || x >= 2000 || y < 0 || y >= 1200)
		return ;
	img_str[0 + 4 * x + 8000 * y] = tmp.byte1;
	img_str[1 + 4 * x + 8000 * y] = tmp.byte2;
	img_str[2 + 4 * x + 8000 * y] = tmp.byte3;
	img_str[3 + 4 * x + 8000 * y] = tmp.byte4;
}

static void	draw_line_inc_x(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	if (b[1] > a[1])
	{
		if (b[1] - a[1] > b[0] - a[0])
			draw_line_pos3(fdf, a, b, color);
		else
			draw_line_pos(fdf, a, b, color);
	}
	else
	{
		if (a[1] - b[1] > b[0] - a[0])
			draw_line_neg3(fdf, a, b, color);
		else
			draw_line_neg(fdf, a, b, color);
	}
}

static void	draw_line_dec_x(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	if (b[1] > a[1])
	{
		if (b[1] - a[1] > a[0] - b[0])
			draw_line_pos4(fdf, a, b, color);
		else
			draw_line_pos2(fdf, a, b, color);
	}
	else
	{
		if (a[1] - b[1] > a[0] - b[0])
			draw_line_neg4(fdf, a, b, color);
		else
			draw_line_neg2(fdf, a, b, color);
	}
}

void		draw_line(t_fdf *fdf, t_point a, t_point b, int color[2])
{
	if (b[0] > a[0])
		draw_line_inc_x(fdf, a, b, color);
	else
		draw_line_dec_x(fdf, a, b, color);
}
