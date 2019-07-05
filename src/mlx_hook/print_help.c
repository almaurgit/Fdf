/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:34:38 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 13:51:19 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_help_part_one(t_fdf *fdf, int i, int j)
{
	mlx_string_put(fdf->mlx, fdf->win, i + 100, j, 0x7070B0, "Perspective");
	mlx_string_put(fdf->mlx, fdf->win, i + 126, j + 20, 0xCBBAC8, "I / P");
	mlx_string_put(fdf->mlx, fdf->win, i + 126, j + 50, 0x7070B0, "Moves");
	mlx_string_put(fdf->mlx, fdf->win, i + 86, j + 70, 0xCBBAC8,
					"W - A - S - D");
	mlx_string_put(fdf->mlx, fdf->win, i + 98, j + 90, 0xCBBAC8, "Right click");
	mlx_string_put(fdf->mlx, fdf->win, i + 110, j + 120, 0x7070B0, "Rotations");
	mlx_string_put(fdf->mlx, fdf->win, i + 30, j + 140, 0xCBBAC8,
					"Num. 4 - 6 / 2 - 8 / 1 - 9");
	mlx_string_put(fdf->mlx, fdf->win, i + 106, j + 160, 0xCBBAC8,
					"Left click");
	mlx_string_put(fdf->mlx, fdf->win, i + 126, j + 190, 0x7070B0, "Colors");
	mlx_string_put(fdf->mlx, fdf->win, i + 18, j + 210, 0xCBBAC8,
					"1 -> 5 / C (World Map Colors)");
	mlx_string_put(fdf->mlx, fdf->win, i + 134, j + 240, 0x7070B0, "Zoom");
	mlx_string_put(fdf->mlx, fdf->win, i + 126, j + 260, 0xCBBAC8, "Scroll");
	mlx_string_put(fdf->mlx, fdf->win, i + 46, j + 290, 0x7070B0,
					"Increase / Decrase Alts");
	mlx_string_put(fdf->mlx, fdf->win, i + 54, j + 310, 0xCBBAC8,
					"Arrow UP / Arrow Down");
}

static void	print_back_help(t_fdf *fdf)
{
	int i;
	int j;

	i = 2010;
	j = 150;
	while (i <= 2390)
	{
		j = 150;
		while (j <= 740)
		{
			if (i < 2016 || i > 2384 || j < 156 || j > 734)
				mlx_pixel_put(fdf->mlx, fdf->win, i, j, 0x8080A0);
			else
				mlx_pixel_put(fdf->mlx, fdf->win, i, j, 0x161616);
			++j;
		}
		++i;
	}
}

void		clear_help(t_fdf *fdf)
{
	int i;
	int j;

	i = 2010;
	j = 150;
	while (i <= 2390)
	{
		j = 150;
		while (j <= 740)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, i, j, 0x000000);
			++j;
		}
		++i;
	}
}

int			print_help(t_fdf *fdf)
{
	int i;
	int j;

	i = 2040;
	j = 170;
	print_back_help(fdf);
	print_help_part_one(fdf, i, j);
	mlx_string_put(fdf->mlx, fdf->win, i + 130, j + 340, 0x7070B0, "Reset");
	mlx_string_put(fdf->mlx, fdf->win, i + 150, j + 360, 0xCBBAC8, "R");
	mlx_string_put(fdf->mlx, fdf->win, i + 96, j + 390, 0x7070B0,
					"Display Help");
	mlx_string_put(fdf->mlx, fdf->win, i + 126, j + 410, 0xCBBAC8, "H - Del");
	mlx_string_put(fdf->mlx, fdf->win, i + 134, j + 440, 0x7070B0, "Quit");
	mlx_string_put(fdf->mlx, fdf->win, i + 142, j + 460, 0xCBBAC8, "ESC");
	mlx_string_put(fdf->mlx, fdf->win, i + 67, j + 485,
					fdf->colors[fdf->num_color % 5][1], "   _         _   ");
	mlx_string_put(fdf->mlx, fdf->win, i + 70, j + 500,
					fdf->colors[fdf->num_color % 5][1], "  /   //   \\/   /");
	mlx_string_put(fdf->mlx, fdf->win, i + 75, j + 515,
					fdf->colors[fdf->num_color % 5][1], " /  / / /\\ /  /  ");
	mlx_string_put(fdf->mlx, fdf->win, i + 80, j + 530,
					fdf->colors[fdf->num_color % 5][1], "/ /  /   _/ /    ");
	return (1);
}
