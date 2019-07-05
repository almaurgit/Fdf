/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:21:10 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 15:42:46 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPES_H
# define FDF_TYPES_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "keys_code.h"

# define PI 3.14159265358979323846
# define ANGLE PI / 100.
# define NOCOLOR 1
# define MAPCOLOR 2
# define COLORS 4
# define HUD 8
# define ISO 16
# define KEY_PRESS 32
# define MOUSE_PRESS 64
# define COLOR_INPUT 128
# define HELP 256

typedef double	t_point[3];
typedef void	(*t_key)();
typedef void	(*t_mouse)();

typedef struct	s_lines
{
	int				nline;
	char			*line;
	int				nalt;
	struct s_lines	*next;
}				t_lines;

typedef struct	s_color
{
	unsigned char		byte1 : 8;
	unsigned char		byte2 : 8;
	unsigned char		byte3 : 8;
	unsigned char		byte4 : 8;

}				t_color;

typedef struct	s_fdf
{
	t_lines		*lines;
	int			err_line;

	void		*mlx;
	void		*img;
	void		*win;
	char		*img_str;

	int			dim_x;
	int			dim_y;
	t_point		**map;
	t_point		**copy;

	int			keyhook;
	t_key		key[262];

	int			button;
	t_mouse		mouse[8];

	t_point		mouse_rot[2];
	t_point		mouse_move[2];

	int			flag;

	int			*colors_input;
	int			colors[5][2];
	int			num_color;

	int			max_alt;
	int			min_alt;

	double		x_rot;
	double		y_rot;
	double		z_rot;
	int			move_x;
	int			move_y;

	double		factor_zoom;
	double		factor_height;
}				t_fdf;

typedef struct	s_error
{
	int		err;
	char	*msg;
}				t_error;

enum	e_fdf
{
	err_int = -4,
	err_empty,
	err_filename,
	err_malloc,
	err_unk
};

#endif
