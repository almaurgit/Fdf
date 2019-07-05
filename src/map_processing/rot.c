/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:18:20 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 13:47:59 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(t_fdf *fdf, int i, int j)
{
	double x;
	double y;
	double z;

	x = fdf->copy[i][j][0];
	y = fdf->copy[i][j][1];
	z = fdf->copy[i][j][2];
	fdf->copy[i][j][0] = x;
	fdf->copy[i][j][1] = y * cos(fdf->x_rot * ANGLE);
	fdf->copy[i][j][1] += z * sin(fdf->x_rot * ANGLE);
	fdf->copy[i][j][2] = -y * sin(fdf->x_rot * ANGLE);
	fdf->copy[i][j][2] += z * cos(fdf->x_rot * ANGLE);
}

void	rot_y(t_fdf *fdf, int i, int j)
{
	double x;
	double y;
	double z;

	x = fdf->copy[i][j][0];
	y = fdf->copy[i][j][1];
	z = fdf->copy[i][j][2];
	fdf->copy[i][j][0] = x * cos(fdf->y_rot * ANGLE);
	fdf->copy[i][j][0] += z * sin(fdf->y_rot * ANGLE);
	fdf->copy[i][j][1] = y;
	fdf->copy[i][j][2] = -x * sin(fdf->y_rot * ANGLE);
	fdf->copy[i][j][2] += z * cos(fdf->y_rot * ANGLE);
}

void	rot_z(t_fdf *fdf, int i, int j)
{
	double x;
	double y;
	double z;

	x = fdf->copy[i][j][0];
	y = fdf->copy[i][j][1];
	z = fdf->copy[i][j][2];
	fdf->copy[i][j][0] = x * cos(fdf->z_rot * ANGLE);
	fdf->copy[i][j][0] -= y * sin(fdf->z_rot * ANGLE);
	fdf->copy[i][j][1] = x * sin(fdf->z_rot * ANGLE);
	fdf->copy[i][j][1] += y * cos(fdf->z_rot * ANGLE);
	fdf->copy[i][j][2] = z;
}

void	iso(t_fdf *fdf, int i, int j)
{
	double x;
	double y;
	double z;

	x = fdf->copy[i][j][0];
	y = fdf->copy[i][j][1];
	z = fdf->copy[i][j][2];
	fdf->copy[i][j][0] = (x - y) * cos(0.523599);
	fdf->copy[i][j][1] = -z + (x + y) * sin(0.523599);
}
