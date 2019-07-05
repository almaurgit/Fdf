/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:09:16 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 17:56:57 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_lines(t_lines *lines)
{
	if (lines)
	{
		if (lines->next)
			free_lines(lines->next);
		free(lines->line);
		free(lines);
	}
}

static void	free_mlx(t_fdf *fdf)
{
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
		mlx_del(fdf->mlx);
}

void		clean_file(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < fdf->dim_y)
	{
		if (fdf->map[i])
			free(fdf->map[i]);
		if (fdf->copy[i])
			free(fdf->copy[i]);
		++i;
	}
	if (fdf->map)
		free(fdf->map);
	if (fdf->copy)
		free(fdf->copy);
	if (fdf->colors_input)
		free(fdf->colors_input);
	free_lines(fdf->lines);
	free_mlx(fdf);
}
