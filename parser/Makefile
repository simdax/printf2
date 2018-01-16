#  ╓─────[ Target and vars ]─  
#  ╙───────────────────── ─ ─ 
NAME := parser
COMMIT_MSG := "tests $(NAME) OK"

#  ╓─────[ Compiler ]─  
#  ╙───────────────────── ─ ─ 
CC := gcc
CCFLAGS := -g3 #-Wall -Werror -Wextra -g
LDFLAGS := ../libft/libft.a

#────[ Functions ]─  
#  ╙───────────────────── ─ ─

SRC := tests/main.c parser.c 
INC := $(addprefix -I, includes ../libft)
OBJ := $(SRC:.c=.o)
LIB_OBJ = $(filter-out main.o, $(OBJ))	
vpath %.c srcs/

#  ╓─────[ Procedures ]─  
#  ╙───────────────────── ─ ─
all: $(NAME)

$(NAME): $(OBJ) 
	@echo -e "\n\033[0;32m [OK] \033[0m \033[0;33m Linking binary:\033[0m " $(NAME)
	@$(CC) $(OBJ) $(CCFLAGS) $(LDFLAGS) -o $(NAME)

%.o : %.c
	@echo -e "\033[0;32m [OK] \033[0m \033[0;33m Compiling:\033[0m " $@
	$(CC) $(CCFLAGS) $(INC) -c -o $@ $<

clean:
	@/bin/rm -Rf $(OBJ)
	@/bin/rm -rf $(OBJSPATH)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAME).a
	@echo -e  "\033[0;31m [✗] \033[0m \033[0;33m Removed last build: \033[0m " $(NAME)

re: fclean all

lib: re
	rm -rf $(NAME).a
	ar rc $(NAME).a $(LIB_OBJ) 
	ranlib $(NAME).a

test: all
	cd tests && ./main

commit: test
	git commit srcs Makefile tests includes -m $(COMMIT_MSG) && git push

prod:
	make CCFLAGS="-Wall -Wextra -Werror" re

debug:
	make CCFLAGS="-g" re 
	lldb ./$(NAME) '#0 '	

#  ╓─────[ Call me maybe ]─  
#  ╙───────────────────── ─ ─ 
.PHONY: all lib clean fclean re
