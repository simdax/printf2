#  ╓─────[ Target ]─  
#  ╙───────────────────── ─ ─ 
NAME := create_args

#  ╓─────[ Compiler ]─  
#  ╙───────────────────── ─ ─ 
CC := gcc
CCFLAGS := -g #ppWextra Wextra Wextra 
LDFLAGS := ../libft/libft.a
LIB := ../libft

#────[ Functions ]─   
#  ╙───────────────────── ─ ─

SRC := parse.c print.c 
INC := $(addprefix -I, includes ../libft)
OBJ := $(SRC:.c=.o)

vpath %.c srcs/

ARGS_DEBUG := 5 5 5

#  ╓─────[ Procedures ]─  
#  ╙───────────────────── ─ ─
all: $(NAME)

$(NAME): $(OBJ) ../libft/libft.a
	@$(CC) $(CCFLAGS) $(INC) main.c -c
	@$(CC) main.o $(OBJ) $(CCFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "\n\033[0;32m [OK] \033[0m \033[0;33m Linking binary:\033[0m " $(NAME)

../libft/libft.a:
	cd ../libft && make

%.o : %.c
	@echo "\033[0;32m [OK] \033[0m \033[0;33m Compiling:\033[0m " $@
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

lib:
	ar -rc $(NAME).a $(OBJ)
	ranlib $(NAME).a

debug: all
	lldb $(NAME) $(ARGS_DEBUG)

test: all
	cd tests && ./main

commit: test
	git commit -am "passe les tests"

#  ╓─────[ Call me maybe ]─  
#  ╙───────────────────── ─ ─ 
.PHONY: all lib clean fclean re
