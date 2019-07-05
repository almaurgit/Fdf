/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:49:29 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 19:19:26 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_i(t_fdf *fdf)
{
	fdf->flag |= ISO;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_p(t_fdf *fdf)
{
	fdf->flag &= ~ISO;
	map_foreach(fdf);
	draw_matrix(fdf);
}

void	key_h(t_fdf *fdf)
{
	print_help(fdf);
}

void	key_del(t_fdf *fdf)
{
	clear_help(fdf);
}

void	key_esc(t_fdf *fdf)
{
	clean_file(fdf);
	exit(EXIT_SUCCESS);
}
