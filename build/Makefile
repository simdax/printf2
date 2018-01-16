NAME := libftprintf.a
SRCS := parse.c print.c ft_printf.c parser.c printf.c
LIBFT_SRCS := libft/*.o
OBJS := $(SRCS:.c=.o)
INC := $(addprefix -I, libft includes)

all: $(NAME)

$(NAME): $(OBJS)
	@ar cr $(NAME) $(OBJS) $(LIBFT_SRCS)
	@ranlib $(NAME)

%.o : %.c
	@gcc -c $(INC) $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(name)

re: fclean all

