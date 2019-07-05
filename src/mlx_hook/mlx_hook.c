/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 12:10:03 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 17:57:04 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_hook_fdf(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 1L << 0, key_press, fdf);
	mlx_hook(fdf->win, 3, 1L << 1, key_release, fdf);
	mlx_hook(fdf->win, 4, 1L << 2, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 1L << 3, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 1L << 8, mouse_move, fdf);
	mlx_hook(fdf->win, 17, 1L << 5, quit, fdf);
	mlx_loop_hook(fdf->mlx, fct_hook, fdf);
	mlx_loop(fdf->mlx);
}

int		fct_hook(t_fdf *fdf)
{
	if (fdf->keyhook < 0 || fdf->keyhook > 261
		|| fdf->button < 0 || fdf->button > 7)
		return (0);
	if (fdf->flag & KEY_PRESS && fdf->key[fdf->keyhook])
		fdf->key[fdf->keyhook](fdf);
	if (fdf->flag & MOUSE_PRESS && fdf->mouse[fdf->button])
		fdf->mouse[fdf->button](fdf);
	return (1);
}

int		quit(t_fdf *fdf)
{
	clean_file(fdf);
	exit(EXIT_SUCCESS);
	return (1);
}
