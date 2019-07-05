/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:44:53 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 19:20:10 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_get_next.h"
#include <fcntl.h>

static int	malloc_map(t_fdf *fdf)
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

int			new_file(t_fdf *fdf, char *line)
{
	if (!(fdf->lines = ft_memalloc(sizeof(t_lines))))
		return (err_malloc);
	fdf->lines->nline = 1;
	fdf->dim_y = 1;
	fdf->lines->line = line;
	fdf->lines->next = NULL;
	return (ft_valid_alts(fdf, fdf->lines, line));
}

int			add_line(t_fdf *fdf, char *line)
{
	t_lines		*tmp;
	int			ret;

	if (!line)
		return (1);
	tmp = fdf->lines;
	if (!fdf->lines)
	{
		if ((ret = new_file(fdf, line)) <= 0)
			return (ret);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_memalloc(sizeof(t_lines))))
			return (err_malloc);
		tmp->next->line = line;
		tmp->next->nline = tmp->nline + 1;
		fdf->dim_y = tmp->nline + 1;
		tmp->next->next = NULL;
		return (ft_valid_alts(fdf, tmp->next, line));
	}
	return (1);
}

int			valid_file(t_fdf *fdf, int ac, char **av)
{
	char	*line;
	int		ret;
	int		fd;

	if ((fd = open(av[ac - 1], O_RDONLY)) < 0)
		return (err_filename);
	while ((get_next_line(fd, &line)) > 0)
		if ((ret = add_line(fdf, line)) <= 0)
		{
			fdf->dim_x = 0;
			fdf->dim_y = 0;
			return (ret);
		}
	return (1);
}

int			parse_file(t_fdf *fdf)
{
	t_lines *lines;

	if (!malloc_map(fdf))
		return (0);
	lines = fdf->lines;
	while (lines)
	{
		ft_get_alts(fdf, lines->line, lines->nline - 1);
		lines = lines->next;
	}
	fdf->factor_zoom = 500. / (double)ft_max(fdf->dim_x, fdf->dim_y);
	return (1);
}
