#  ╓─────[ Target ]─  
#  ╙───────────────────── ─ ─ 
NAME = printf

#  ╓─────[ Compiler ]─  
#  ╙───────────────────── ─ ─ 
CC = gcc
LINK = ar rc
CCFLAGS = -g3 -Wall -Werror -Wextra
MODULES = libft/libft.a parser/parser.a create_args/create_args.a
LDFLAGS = modules.a

#  ╓─────[ Functions ]─  
#  ╙───────────────────── ─ ─

SRC = ft_printf.c create_args/srcs/*.c parser/srcs/*.c
INC = $(addprefix -I, .. libft includes create_args/includes parser/includes)
OBJ = $(SRC:.c=.o)

vpath %.c srcs/

#  ╓─────[ Procedures ]─  
#  ╙───────────────────── ─ ─
all: $(NAME)

$(NAME): $(OBJ) #modules
	@echo -e "\n\033[0;32m [OK] \033[0m \033[0;33m Linking binary:\033[0m " $(NAME)
	ar rc libft$(NAME).a ft_printf.o create_args/*o parser/*o libft/*o

alllibs:
	make -C libft
	make -C parser re
	make -C create_args re

modules:
	ar crsT modules.a $(MODULES)

%.a :
	make -C $@ lib

%.o : %.c
	@echo -e "\033[0;32m [OK] \033[0m \033[0;33m Compiling:\033[0m " $@
	@echo -e	@$(CC) $(CCFLAGS) $(INC)  -c -o $@ $<
	@$(CC) $(CCFLAGS) $(INC)  -c -o $@ $<

clean:
	@/bin/rm -Rf $(OBJ)
	@/bin/rm -rf $(OBJSPATH)

fclean: clean
	@rm -f $(NAME)
	@echo -e  "\033[0;31m [✗] \033[0m \033[0;33m Removed last build: \033[0m " $(NAME)

re:	alllibs
	@$(MAKE) fclean
	@$(MAKE) all

debug: b
	lldb tests/$(NAME)

test: b
	@$(CC) -g tests/main.c build/libft$(NAME).a -o tests/$(NAME)
	./tests/$(NAME)

lib:
	@make -C $(LIBFT)

b:
	./prod && make -C build

send: b
	cd build && git init
	cd build && make fclean && make -C libft fclean
	cd build &&	git add .
	cd build && git remote add 42 vogsphere@vogsphere.42.fr:intra/2018/activities/ft_printf/scornaz
	cd build && git commit -am gros_pushage
	cd build && git push -f 42 master

#  ╓─────[ Call me maybe ]─  
#  ╙───────────────────── ─ ─ 
.PHONY: all lib clean fclean re
