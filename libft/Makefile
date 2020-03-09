NAME = ../libft.a
FLAGS = -Werror -Wall -Wextra
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
 		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		 ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c  ft_split.c \
 		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
 		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		 ft_tolower.c ft_toupper.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		 ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		 ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
		hexa.c numberpos.c numberneg.c string.c pointer.c char.c \
		libftprint.c itoa_base.c  ft_printf.c modulo.c unsigned.c \
		itoa_base10.c  what.c isin.c \
		whatl.c hexal.c charl.c stringl.c hexall.c whatll.c \
		unsignedll.c whath.c extra.c ft_putstr_fd.c\
		get_next_line.c
OBJ = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
 		ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
		 ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o  ft_split.o \
 		ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o \
 		ft_strmapi.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o \
		 ft_tolower.o ft_toupper.o ft_lstadd_back_bonus.o ft_lstadd_front_bonus.o \
		 ft_lstclear_bonus.o ft_lstdelone_bonus.o ft_lstiter_bonus.o ft_lstlast_bonus.o \
		 ft_lstmap_bonus.o ft_lstnew_bonus.o ft_lstsize_bonus.o \
		hexa.o numberpos.o numberneg.o string.o pointer.o char.o \
		libftprint.o itoa_base.o  ft_printf.o modulo.o unsigned.o \
		itoa_base10.o what.o isin.o \
		whatl.o hexal.o charl.o stringl.o hexall.o whatll.o \
		unsignedll.o whath.o extra.o ft_putstr_fd.o\
		get_next_line.o
all:$(NAME)
$(NAME): $(OBJ)
	@ar -rsc $(NAME) $(OBJ) 
$(OBJ): $(SRCS)
	@gcc -c $(SRCS) $(FLAGS)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: clean fclean all bonus 