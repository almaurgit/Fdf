/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:41:50 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 15:13:50 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_key(t_fdf *fdf)
{
	fdf->key[KEY_0] = key_0;
	fdf->key[KEY_1] = key_1;
	fdf->key[KEY_2] = key_2;
	fdf->key[KEY_3] = key_3;
	fdf->key[KEY_4] = key_4;
	fdf->key[KEY_5] = key_5;
	fdf->key[KEY_C] = key_c;
	fdf->key[KEY_A] = key_a;
	fdf->key[KEY_S] = key_s;
	fdf->key[KEY_D] = key_d;
	fdf->key[KEY_W] = key_w;
	fdf->key[KEY_NUM_4] = key_n4;
	fdf->key[KEY_NUM_6] = key_n6;
	fdf->key[KEY_NUM_2] = key_n2;
	fdf->key[KEY_NUM_8] = key_n8;
	fdf->key[KEY_NUM_1] = key_n1;
	fdf->key[KEY_NUM_9] = key_n9;
	fdf->key[KEY_UP] = key_up;
	fdf->key[KEY_DOWN] = key_down;
	fdf->key[KEY_R] = key_r;
	fdf->key[KEY_I] = key_i;
	fdf->key[KEY_P] = key_p;
	fdf->key[KEY_H] = key_h;
	fdf->key[KEY_DEL] = key_del;
	fdf->key[KEY_ESC] = key_esc;
}

int		key_press(int keyhook, t_fdf *fdf)
{
	fdf->flag |= KEY_PRESS;
	fdf->keyhook = keyhook;
	return (1);
}

int		key_release(int keyhook, t_fdf *fdf)
{
	if (keyhook)
		;
	fdf->flag &= ~KEY_PRESS;
	return (1);
}
