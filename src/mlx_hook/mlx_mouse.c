/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 12:07:21 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 15:15:51 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mouse(t_fdf *fdf)
{
	fdf->mouse[SCROLLUP] = scrollup;
	fdf->mouse[SCROLLDOWN] = scrolldown;
	fdf->mouse[BUT1] = but1;
	fdf->mouse[BUT2] = but2;
}

int		mouse_press(int button, int x, int y, t_fdf *fdf)
{
	fdf->flag |= MOUSE_PRESS;
	fdf->button = button;
	if (button == BUT1)
	{
		fdf->mouse_rot[1][2] = fdf->x_rot;
		fdf->mouse_rot[0][2] = fdf->y_rot;
		fdf->mouse_rot[0][0] = (double)x;
		fdf->mouse_rot[0][1] = (double)y;
	}
	else if (button == BUT2)
	{
		fdf->mouse_move[1][2] = fdf->move_x;
		fdf->mouse_move[0][2] = fdf->move_y;
		fdf->mouse_move[0][0] = (double)x;
		fdf->mouse_move[0][1] = (double)y;
	}
	return (1);
}

int		mouse_move(int x, int y, t_fdf *fdf)
{
	fdf->mouse_rot[1][0] = (double)x;
	fdf->mouse_rot[1][1] = (double)y;
	fdf->mouse_move[1][0] = (double)x;
	fdf->mouse_move[1][1] = (double)y;
	return (1);
}

int		mouse_release(int button, int x, int y, t_fdf *fdf)
{
	if (x || y || button)
		;
	fdf->flag &= ~MOUSE_PRESS;
	return (1);
}
