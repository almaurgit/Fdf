/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:39:52 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 16:19:16 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isintcolor(char *s, int start, int end)
{
	char *str;

	if (!(str = ft_strnstr(s + start, ",0x", end - start + 1)))
		return (0);
	if (ft_isint(s, start, start + (int)(str - s - start - 1))
			&& ft_ishexa(s, start + (int)(str - s - start) + 3, end))
		return (1);
	return (0);
}

static int	valid_line(t_fdf *fdf, int *nalt, t_lines *lines, int *i)
{
	int		next;
	int		alt;
	char	*line;

	line = lines->line;
	ft_skip_spaces(line, i);
	if (!line[*i])
		return (1);
	next = ft_next_space(line, *i);
	if (ft_isint(line, *i, next - 1))
		++(*nalt);
	else if (fdf->flag & COLOR_INPUT && ft_isintcolor(line, *i, next - 1))
		++(*nalt);
	else
	{
		fdf->err_line = lines->nline;
		return (err_int);
	}
	alt = ft_atoi(line + *i);
	if (fdf->max_alt < alt)
		fdf->max_alt = alt;
	if (fdf->min_alt > alt)
		fdf->min_alt = alt;
	*i = next;
	return (1);
}

int			ft_get_alts(t_fdf *fdf, char *line, int y)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = 0;
	while (x < fdf->dim_x)
	{
		ft_skip_spaces(line, &i);
		if (fdf->flag & COLOR_INPUT)
		{
			str = ft_strnstr(line + i, ",0x", ft_next_space(line, i) - i);
			if (fdf->flag & COLOR_INPUT && str
				&& str[3] && str[3] != ' ' && str[3] != '\t')
				fdf->colors_input[y * fdf->dim_x + x] = ft_atoi_base(str + 3,
														"0123456789ABCDEF");
		}
		fdf->map[y][x][0] = x - (double)fdf->dim_x / 2. + 0.5;
		fdf->map[y][x][1] = y - (double)fdf->dim_y / 2. + 0.5;
		fdf->map[y][x][2] = (double)ft_atoi(line + i);
		i = ft_next_space(line, i);
		++x;
	}
	return (1);
}

int			ft_valid_alts(t_fdf *fdf, t_lines *lines, char *line)
{
	int		*nalt;
	int		i;
	int		ret;

	i = 0;
	nalt = &(lines->nalt);
	while (line[i])
	{
		if ((ret = valid_line(fdf, nalt, lines, &i)) < 0)
			return (ret);
	}
	if (fdf->dim_x < *nalt)
		fdf->dim_x = *nalt;
	return (1);
}
