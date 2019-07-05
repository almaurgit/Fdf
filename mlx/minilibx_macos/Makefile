#
#

_PURPLE=\x1b[35m
_RED=\x1b[31m
_GREEN=\x1b[32m
_BOLD=\x1b[1m
_DEFAULT=\x1b[0m

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2



all: $(NOM)
	@printf "${_BOLD}${_RED}[  mlx ok]${_DEFAULT}\n"

debug: CFLAGS += -g
debug: RULE=debug
debug: $(NOM)

asan: CFLAGS += -fsanitize=address -g
asan: RULE=asan
asan: $(NOM)

$(NOM):	$(OBJ)
	@printf "${_BOLD}${_RED}[     mlx]${_DEFAULT} ar -rc $(NOM) $(OBJ)\n"
	@ar -rc $(NOM) $(OBJ)
	@printf "${_BOLD}${_RED}[     mlx]${_DEFAULT} ranlib $(NOM)\n"
	@ranlib $(NOM)


%.o: %.c $(HEADER)
	@printf "${_BOLD}${_RED}[     mlx]${_DEFAULT} cc $(CFLAGS) -c -o $@ $<\n"
	@cc $(CFLAGS) -c -o $@ $<

%.o: %.m $(HEADER)
	@printf "${_BOLD}${_RED}[     mlx]${_DEFAULT} cc $(CFLAGS) -c -o $@ $<\n"
	@cc $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ) *~

fclean:
	@rm -f $(NOM)
	@rm -f mlx_app

re: fclean all
