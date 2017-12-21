#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simdax </var/spool/mail/simdax>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 15:57:09 by simdax            #+#    #+#              #
#    Updated: 2017/12/20 17:48:52 by simdax           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := libftprintf.a
SRCS :=	flags.c parse.c print.c ft_printf.c
LIBFT_SRCS := libft/*.o
OBJS := $(SRCS:.c=.o)
INC := $(addprefix -I, libft)

all: $(NAME)

$(NAME): $(OBJS)
	@echo `tput setaf 4`ALLEZ ON LINK TOUT !!!!	
	@ar crsT $(NAME) $(OBJS) $(LIBFT_SRCS)
	@ranlib $(NAME)

%.o : %.c
	@echo `tput setaf 3`ALLEZ ON COMPILE $@ !!!!	
	@gcc -c $(INC) $< -o $@ 

clean:
	@echo `tput setaf 1`ALLEZ ON CASSE TOUT !!!!
	@rm -rf $(OBJS)

fclean: clean
	@echo `tput setaf 5`ALLEZ ON CASSE LE BIN !!!!
	@rm -rf $(NAME)

re: fclean all
	@echo `tput setaf 2`BRAVO LE REBUILD !!!!
