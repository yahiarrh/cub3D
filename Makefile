NAME = cub

SRC	=	parse.c utils_parse.c utils_parse2.c v_map.c

 
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

CC		= cc

RM 		= rm -rf

HEADERM = cub.h

LIBFT = libft/libft.a

OBJS	= $(SRC:.c=.o)

%.o : %.c $(HEADERM)
	$(CC) $(CFLAGS) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	cc $(OBJS) -o $(NAME) $(LIBFT) $(CFLAGS)

clean :
	@make clean -C libft
	$(RM) $(OBJS)


fclean : clean
	@make fclean -C libft
	@$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re