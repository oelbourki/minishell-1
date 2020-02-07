# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 18:01:58 by ibaali            #+#    #+#              #
#    Updated: 2019/11/08 11:38:48 by ibaali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= 	chose_conv.c			\
		fill_flag_strc.c		\
		flag_test.c				\
		ft_atoi.c				\
		ft_isdigit.c			\
		ft_printf.c				\
		ft_putchar_fd.c			\
		ft_putnbr_fd.c			\
		ft_putstr_fd.c			\
		ft_strchr.c				\
		helped1.c				\
		integer_process.c		\
		unsigned_int_process.c	\
		ft_strrev.c				\
		ft_strlen.c				\
		hex_process.c			\
		helped2.c				\
		pointer_process.c		\
		char_process.c			\
		string_process.c		\
		ft_strdup.c				\
		module_process.c

OBJ	= 	chose_conv.o			\
		fill_flag_strc.o		\
		flag_test.o				\
		ft_atoi.o				\
		ft_isdigit.o			\
		ft_printf.o				\
		ft_putchar_fd.o			\
		ft_putnbr_fd.o			\
		ft_putstr_fd.o			\
		ft_strchr.o				\
		helped1.o				\
		integer_process.o		\
		unsigned_int_process.o	\
		ft_strrev.o				\
		ft_strlen.o				\
		hex_process.o			\
		helped2.o				\
		pointer_process.o		\
		char_process.o			\
		string_process.o		\
		ft_strdup.o				\
		module_process.o

FLAG = -Wextra -Wall -Werror

NAME = libftprintf.a

all : $(NAME)

$(NAME) :
	@gcc -c $(FLAG) $(SRC)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :
	@rm -f $(OBJ)

re : fclean all

.PHONY : all clean fclean re
