# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:30:32 by ibaali            #+#    #+#              #
#    Updated: 2020/03/09 15:10:57 by ibaali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	Parser/add_var_env_list.c					\
	 	Parser/print_command.c						\
		Parser/back_slach.c							\
		Parser/helped.c								\
		Parser/list_command.c						\
		Parser/parse.c								\
		Parser/parse_error.c						\
		Parser/pipe_rin_semicol.c					\
		Parser/rediriction_out.c					\
		Parser/set_dollar_value.c					\
		Parser/simple_double_qoute_optimize.c		\
		execution/builtin.c							\
		execution/builtin_echo.c					\
		execution/builtin_env.c						\
		execution/builtin_export.c					\
		execution/builtin_unset.c					\
		execution/convert.c							\
		execution/free.c							\
		execution/ft_exx.c							\
		execution/ft_exx1.c							\
		execution/functions.c						\
		execution/functions3.c						\
		execution/functions_1.c						\
		execution/functions_ex.c					\
		execution/hope.c							\
		execution/path.c							\
		execution/redirections.c					\
		execution/redirections1.c					\
		execution/signals.c							\
		execution/var.c								\
		minishell.c

LIBRARY = libft.a

NAME = minishell

# FLAGS = -Wextra -Wall -Werror -fsanitize=address -g
FLAGS = -Wextra -Wall -Werror
INCLUDE = include

CC = gcc

all : $(NAME)

# $(NAME) : $(LIBRARY)
# 	@$(CC) $(FLAGS) $(SRC) $(LIBRARY) -I $(INCLUDE) -o $(NAME)
# $(LIBRARY):
# 	@make -C libft

$(NAME) :
	@$(CC) $(FLAGS) $(SRC) libft/*.c -I $(INCLUDE) -o $(NAME)

clean :
	@rm -rf $(NAME)
	@rm -rf $(LIBRARY)

fclean : clean
	
re :  fclean all

.PHONY : all re fclean clean
