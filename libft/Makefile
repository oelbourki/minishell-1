# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 21:31:15 by ibaali            #+#    #+#              #
#    Updated: 2020/01/11 08:30:08 by ibaali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = libft/ft_atoi.c			\
	  libft/ft_bzero.c			\
	  libft/ft_calloc.c			\
	  libft/ft_isalnum.c		\
	  libft/ft_isalpha.c		\
	  libft/ft_isascii.c		\
	  libft/ft_isdigit.c		\
	  libft/ft_isprint.c		\
	  libft/ft_itoa.c			\
	  libft/ft_memccpy.c		\
	  libft/ft_memchr.c			\
	  libft/ft_memcmp.c			\
	  libft/ft_memmove.c		\
	  libft/ft_memset.c			\
	  libft/ft_putchar_fd.c		\
	  libft/ft_putendl_fd.c		\
	  libft/ft_putnbr_fd.c		\
	  libft/ft_putstr_fd.c		\
	  libft/ft_split.c			\
	  libft/ft_strchr.c			\
	  libft/ft_strdup.c			\
	  libft/ft_strjoin.c		\
	  libft/ft_strlcat.c		\
	  libft/ft_strlcpy.c		\
	  libft/ft_strlen.c			\
	  libft/ft_strmapi.c		\
	  libft/ft_strncmp.c		\
	  libft/ft_strnstr.c		\
	  libft/ft_strrchr.c		\
	  libft/ft_strtrim.c		\
	  libft/ft_substr.c			\
	  libft/ft_tolower.c		\
	  libft/ft_toupper.c		\
	  libft/ft_memcpy.c

OBJ = ft_atoi.o				\
	  ft_bzero.o			\
	  ft_calloc.o			\
	  ft_isalnum.o			\
	  ft_isalpha.o			\
	  ft_isascii.o			\
	  ft_isdigit.o			\
	  ft_isprint.o			\
	  ft_itoa.o				\
	  ft_memccpy.o			\
	  ft_memchr.o			\
	  ft_memcmp.o			\
	  ft_memmove.o			\
	  ft_memset.o			\
	  ft_putchar_fd.o		\
	  ft_putendl_fd.o		\
	  ft_putnbr_fd.o		\
	  ft_putstr_fd.o		\
	  ft_split.o			\
	  ft_strchr.o			\
	  ft_strdup.o			\
	  ft_strjoin.o			\
	  ft_strlcat.o			\
	  ft_strlcpy.o			\
	  ft_strlen.o			\
	  ft_strmapi.o			\
	  ft_strncmp.o			\
	  ft_strnstr.o			\
	  ft_strrchr.o			\
	  ft_strtrim.o			\
	  ft_substr.o			\
	  ft_tolower.o			\
	  ft_toupper.o			\
	  ft_memcpy.o

BSRC = ft_lstadd_back_bonus.c	\
	   ft_lstnew_bonus.c	\
	   ft_lstadd_front_bonus.c	\
	   ft_lstclear_bonus.c	\
	   ft_lstdelone_bonus.c	\
	   ft_lstiter_bonus.c	\
	   ft_lstlast_bonus.c	\
	   ft_lstmap_bonus.c	\
	   ft_lstsize_bonus.c

BOBJ = ft_lstadd_back_bonus.o	\
	   ft_lstnew_bonus.o	\
	   ft_lstadd_front_bonus.o	\
	   ft_lstclear_bonus.o	\
	   ft_lstdelone_bonus.o	\
	   ft_lstiter_bonus.o	\
	   ft_lstlast_bonus.o	\
	   ft_lstmap_bonus.o	\
	   ft_lstsize_bonus.o

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC = libft.h

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)

bonus: clean $(BOBJ)
	@ar rs $(NAME) $(BOBJ)

$(BOBJ): $(BSRC)
	@$(CC) $(CFLAGS) -c $(BSRC) -I $(INC)

clean:
	@rm -f $(OBJ)
	@rm -f $(BOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : clean fclean all bonus
