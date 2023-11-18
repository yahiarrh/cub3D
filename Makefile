NAME = cub3d

SRC	=	parse.c utils_parse.c utils_parse2.c v_map.c

GLFW = $(shell brew --prefix glfw)

framG = -framework Cocoa -framework OpenGL -framework IOKit

CFLAGS	= -Wall -Wextra -Werror  -fsanitize=address -g

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
	cc $(OBJS) -o $(NAME) $(LIBFT) $(CFLAGS) libmlx42.a -Iinclude -lglfw -L"$(GLFW)/lib/" $(framG)

clean :
	@make clean -C libft
	$(RM) $(OBJS)


fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re