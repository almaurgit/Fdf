/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:45:55 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 11:21:42 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_n6(t_fdf *fdf)
{
	++fdf->y_rot;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_n2(t_fdf *fdf)
{
	++fdf->x_rot;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_n8(t_fdf *fdf)
{
	--fdf->x_rot;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_n1(t_fdf *fdf)
{
	--fdf->z_rot;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_n9(t_fdf *fdf)
{
	++fdf->z_rot;
	map_foreach(fdf);
	draw_matrix(fdf);
}
