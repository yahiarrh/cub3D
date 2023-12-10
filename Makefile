NAME = cub3D

SRC	=	main.c parsing/parse.c parsing/utils_parse.c parsing/utils_parse2.c parsing/v_map.c \
		draw/calcul.c draw/init_texture.c draw/intersection.c draw/map.c draw/movs.c draw/player.c \
		draw/ray_cast.c draw/which.c get_ptr.c

GLFW = $(shell brew --prefix glfw)

framG = -framework Cocoa -framework OpenGL -framework IOKit

CFLAGS	= -Wall -Wextra -Werror -Ofast -O3 #-g -fsanitize=address

CC		= cc

RM 		= rm -rf

HEADERM = include/cub.h

LIBFT = libft/libft.a

OBJS	= $(SRC:.c=.o)

%.o : %.c $(HEADERM)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	cc $(OBJS) -o $(NAME) $(LIBFT) $(CFLAGS) libmlx42.a -Iinclude -lglfw -L"$(GLFW)/lib/"

clean :
	@make clean -C libft
	$(RM) $(OBJS)


fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re