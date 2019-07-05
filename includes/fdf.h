/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:46:40 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 15:41:44 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_types.h"

/*
** clean/errors.c
*/
int		error(t_fdf *fdf, int err);
void	usage(t_fdf *fdf);

/*
** clean/clean.c
*/
void	clean_file(t_fdf *fdf);

/*
** draw/draw.c
*/
void	draw_matrix(t_fdf *fdf);

/*
** draw/colors.c
*/
int		get_color_x(t_point start, t_point end, int x, int color[2]);
int		get_color_y(t_point start, t_point end, int x, int color[2]);
int		get_color_map(t_fdf *fdf, int x, int y);
int		get_color(t_fdf *fdf, int x, int y, int i);

/*
** draw/colors2.c
*/
double	percent(double start, double end, double current);
int		get_light(int start, int end, double percentage);

/*
** draw/line.c
*/
void	fill_pixel(char *img_str, int x, int y, int color);
void	draw_line(t_fdf *fdf, t_point a, t_point b, int color[2]);

/*
** draw/line_neg_slope.c
*/
void	draw_line_neg(t_fdf *fdf, t_point a, t_point b, int color[2]);
void	draw_line_neg2(t_fdf *fdf, t_point a, t_point b, int color[2]);
void	draw_line_neg3(t_fdf *fdf, t_point a, t_point b, int color[2]);
void	draw_line_neg4(t_fdf *fdf, t_point a, t_point b, int color[2]);

/*
** draw/line_pos_slope.c
*/
void	draw_line_pos(t_fdf *fdf, t_point a, t_point b, int color[2]);
void	draw_line_pos2(t_fdf *fdf, t_point a, t_point b, int color[2]);
void	draw_line_pos3(t_fdf *fdf, t_point a, t_point b, int color[2]);
void	draw_line_pos4(t_fdf *fdf, t_point a, t_point b, int color[2]);

/*
** map_processing/map_moves.c
*/
void	map_foreach(t_fdf *fdf);

/*
** map_processing/rot.c
*/
void	rot_x(t_fdf *fdf, int i, int j);
void	rot_y(t_fdf *fdf, int i, int j);
void	rot_z(t_fdf *fdf, int i, int j);
void	iso(t_fdf *fdf, int i, int j);

/*
** mlx_hook/mlx_key.c
*/
void	init_key(t_fdf *fdf);
int		key_press(int keyhook, t_fdf *fdf);
int		key_release(int keyhook, t_fdf *fdf);

/*
** mlx_hook/mlx_mouse.c
*/
void	init_mouse(t_fdf *fdf);
int		mouse_press(int button, int x, int y, t_fdf *fdf);
int		mouse_move(int x, int y, t_fdf *fdf);
int		mouse_release(int button, int x, int y, t_fdf *fdf);

/*
** mlx_hook/mlx_hook.c
*/
void	mlx_hook_fdf(t_fdf *fdf);
int		fct_hook(t_fdf *fdf);
int		quit(t_fdf *fdf);

/*
** mlx_hook/print_help.c
*/
int		print_help(t_fdf *fdf);
void	clear_help(t_fdf *fdf);

/*
** mlx_hook/key*.c, mlx_hook/mouse*.c
*/
void	key_0(t_fdf *fdf);
void	key_1(t_fdf *fdf);
void	key_2(t_fdf *fdf);
void	key_3(t_fdf *fdf);
void	key_4(t_fdf *fdf);
void	key_5(t_fdf *fdf);
void	key_c(t_fdf *fdf);
void	key_a(t_fdf *fdf);
void	key_s(t_fdf *fdf);
void	key_d(t_fdf *fdf);
void	key_w(t_fdf *fdf);
void	key_n4(t_fdf *fdf);
void	key_n6(t_fdf *fdf);
void	key_n2(t_fdf *fdf);
void	key_n8(t_fdf *fdf);
void	key_n1(t_fdf *fdf);
void	key_n9(t_fdf *fdf);
void	key_up(t_fdf *fdf);
void	key_down(t_fdf *fdf);
void	key_r(t_fdf *fdf);
void	key_i(t_fdf *fdf);
void	key_p(t_fdf *fdf);
void	key_h(t_fdf *fdf);
void	key_del(t_fdf *fdf);
void	key_esc(t_fdf *fdf);
void	scrollup(t_fdf *fdf);
void	scrolldown(t_fdf *fdf);
void	but1(t_fdf *fdf);
void	but2(t_fdf *fdf);

/*
** parser/file.c
*/
int		new_file(t_fdf *fdf, char *line);
int		add_line(t_fdf *fdf, char *line);
int		valid_file(t_fdf *fdf, int ac, char **av);
int		parse_file(t_fdf *fdf);

/*
** parser/file_lines.c
*/
int		ft_get_alts(t_fdf *fdf, char *line, int y);
int		ft_valid_alts(t_fdf *fdf, t_lines *lines, char *line);

#endif
