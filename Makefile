# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 11:17:50 by amaurel           #+#    #+#              #
#    Updated: 2019/07/05 11:18:35 by amaurel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_PURPLE=\x1b[35m
_RED=\x1b[31m
_GREEN=\x1b[32m
_BOLD=\x1b[1m
_DEFAULT=\x1b[0m

CC=clang

MAKE=make

RM=rm

override CFLAGS += -Wall -Wextra -Werror -Iincludes -Ilibft/includes -Imlx/minilibx_macos/

override LDFLAGS += -Llibft -lft -L mlx/minilibx_macos -lmlx

override FRMFLAGS += -framework OpenGL -framework AppKit

NAME=	fdf

SRC = 	fdf.c \
		clean/errors.c \
		clean/clean.c \
		draw/draw.c \
		draw/line.c \
		draw/line_pos_slope.c \
		draw/line_neg_slope.c \
		draw/colors.c \
		draw/colors2.c \
		map_processing/rot.c \
		map_processing/map_moves.c \
		mlx_hook/print_help.c \
		mlx_hook/mlx_key.c \
		mlx_hook/key1.c \
		mlx_hook/key2.c \
		mlx_hook/key3.c \
		mlx_hook/key4.c \
		mlx_hook/key5.c \
		mlx_hook/mouse1.c \
		mlx_hook/mlx_mouse.c \
		mlx_hook/mlx_hook.c \
		parser/file.c \
		parser/file_lines.c \

SRC:=$(addprefix src/, ${SRC})


HEADER= keys_code.h fdf.h
HEADER:=$(addprefix includes/, ${HEADER})

LIBS=libft/libft.a mlx/minilibx_macos/libmlx.a

OBJ=${SRC:.c=.o}

.PHONY: all $(NAME) libft mlx clean fclean re

all: $(NAME)
	@printf "$(_BOLD)$(_GREEN)[  fdf ok]$(_DEFAULT)\n"

$(NAME): $(LIBS) $(OBJ)
	@printf "${_BOLD}${_GREEN}[     fdf]${_DEFAULT} $(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(FRMFLAGS)\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(FRMFLAGS)

%.o: %.c $(HEADER)
	@printf "${_BOLD}${_GREEN}[     fdf]${_DEFAULT} $(CC) $(CFLAGS) -c $< -o $@\n"
	@$(CC) $(CFLAGS) -c $< -o $@

libft: libft/libft.a

libft/libft.a:
	@printf "${_BOLD}${_PURPLE}[   libft]${_DEFAULT} $(MAKE) -C libft $(RULE)\n"
	@$(MAKE) -C libft $(RULE)

mlx: mlx/minilibx_macos/libmlx.a

mlx/minilibx_macos/libmlx.a:
	@printf "${_BOLD}${_RED}[     mlx]${_DEFAULT} $(MAKE) -C mlx/minilibx_macos $(RULE)\n"
	@$(MAKE) -C mlx/minilibx_macos $(RULE)

clean:
	@$(RM) -f $(OBJ)
	@$(MAKE) -C libft clean
	@$(MAKE) -C mlx/minilibx_macos clean

fclean: clean
	@$(RM) -f $(NAME)
	@$(RM) -rf $(NAME).dSYM
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx/minilibx_macos fclean


re: fclean all
