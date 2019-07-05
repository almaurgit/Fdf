/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:04:40 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 18:59:50 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		malloc_map(t_fdf *fdf)
{
	int i;

	i = 0;
	if (!(fdf->map = ft_memalloc(sizeof(t_point *) * fdf->dim_y))
		|| !(fdf->copy = ft_memalloc(sizeof(t_point *) * fdf->dim_y)))
		return (0);
	while (i < fdf->dim_y)
	{
		if (!(fdf->map[i] = ft_memalloc(sizeof(t_point) * fdf->dim_x))
			|| !(fdf->copy[i] = ft_memalloc(sizeof(t_point) * fdf->dim_x)))
			return (0);
		++i;
	}
	if (fdf->flag & COLOR_INPUT)
		fdf->colors_input = ft_memalloc(sizeof(int) * fdf->dim_x * fdf->dim_y);
	return (1);
}

void	init_mlx(t_fdf *fdf)
{
	int			bpp;
	int			s_l;
	int			endian;
	const int	cols[5][2] = {
		{0x000000, 0xFFFFFF},
		{0xFF8811, 0xE8192F},
		{0x88BAF5, 0xFFFFFF},
		{0xD5B110, 0x30C830},
		{0x111222, 0xFBBAC8}
	};

	ft_bzero(fdf, sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 2400, 1200, "fdf");
	fdf->img = mlx_new_image(fdf->mlx, 2000, 1200);
	fdf->img_str = mlx_get_data_addr(fdf->img, &(bpp), &(s_l), &(endian));
	init_key(fdf);
	init_mouse(fdf);
	fdf->factor_zoom = 1.;
	fdf->factor_height = 1.;
	fdf->flag = NOCOLOR | ISO;
	ft_memcpy(fdf->colors, cols, sizeof(int) * 10);
}

void	options(t_fdf *fdf, int *i, char **av)
{
	int j;

	*i = 1;
	while (av[*i] && av[*i][0] == '-')
	{
		j = 1;
		while (av[*i][j])
		{
			if (av[*i][j] == 'c')
				fdf->flag |= COLOR_INPUT;
			else if (av[*i][j] == 'h')
				fdf->flag |= HELP;
			++j;
		}
		++(*i);
	}
}

int		main(int ac, char **av)
{
	t_fdf	fdf;
	int		ret;
	int		i;

	i = 1;
	init_mlx(&fdf);
	if (ac > 1)
		options(&fdf, &i, av);
	if (i < ac)
	{
		if ((ret = valid_file(&fdf, ac, av)) <= 0)
			return (error(&fdf, ret));
		if (!parse_file(&fdf))
			return (error(&fdf, err_malloc));
		map_foreach(&fdf);
		draw_matrix(&fdf);
		mlx_hook_fdf(&fdf);
	}
	else
		usage(&fdf);
	clean_file(&fdf);
	return (1);
}
