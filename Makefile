#  ╓─────[ Target ]─  
#  ╙───────────────────── ─ ─ 
NAME = printf

#  ╓─────[ Compiler ]─  
#  ╙───────────────────── ─ ─ 
CC = gcc
CCFLAGS = -g # -Wall -Werror -Wextra
MODULES = libft/libft.a parser/parser.a create_args/create_args.a
LDFLAGS = modules.a

#  ╓─────[ Functions ]─  
#  ╙───────────────────── ─ ─

SRC = ft_printf.c main.c
INC = $(addprefix -I, libft includes create_args/includes parser/includes)
OBJ = $(SRC:.c=.o)

vpath %.c srcs/

#  ╓─────[ Procedures ]─  
#  ╙───────────────────── ─ ─
all: $(NAME)

$(NAME): $(OBJ) modules
	@echo "\n\033[0;32m [OK] \033[0m \033[0;33m Linking binary:\033[0m " $(NAME)
	@$(CC) $(OBJ) $(CCFLAGS) $(LDFLAGS) -o $(NAME)

modules:
	ar crsT modules.a $(MODULES)

%.a :
	make -C $@ lib

%.o : %.c
	@echo "\033[0;32m [OK] \033[0m \033[0;33m Compiling:\033[0m " $@
	@echo	@$(CC) $(CCFLAGS) $(INC)  -c -o $@ $<
	@$(CC) $(CCFLAGS) $(INC)  -c -o $@ $<

clean:
	@/bin/rm -Rf $(OBJ)
	@/bin/rm -rf $(OBJSPATH)

fclean: clean
	@rm -f $(NAME)
	@echo  "\033[0;31m [✗] \033[0m \033[0;33m Removed last build: \033[0m " $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
debug: all
	lldb $(NAME)

test:
	cd tests && ./main

lib:
	@make -C $(LIBFT)

#  ╓─────[ Call me maybe ]─  
#  ╙───────────────────── ─ ─ 
.PHONY: all lib clean fclean re
