/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:41:08 by oel-bour          #+#    #+#             */
/*   Updated: 2020/03/09 09:45:59 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define BUFFER_SIZE 1024
# define MAX(a,b) ((a < b) ? (b) : (a))

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct				s_print
{
	int						h;
	int						h1;
	int						left;
	int						zero;
	int						min;
	int						prec;
	int						prec_val;
	char					type;
	char					*arg;
	wchar_t					*arg1;
	char					c;
	wchar_t					c1;
	long long int			i;
	int						*r;
	long int				*r1;
	long long int			*r2;
	int						l;
	int						lon;
	unsigned long int		u;
	unsigned long long int	lu;
	signed char				*s;
	short int				*s1;
	size_t					base;
	int						precs;
}							t_print;

void			ft_lstdelone(t_list *lst, void (*del)(void*));
int				ft_lstsize(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));
int				ft_atoi(const char *s);
void			ft_bzero(void *s, size_t len);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *h, const char *n, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				get_next_line(int fd, char **line);

int							ft_putstr(int fd, char *s, int l);
int							ft_free_p(void *s);
int							isin(char c);
int							handel(t_print *ele);
int							what(t_print *ele, va_list ap, int n);
int							handelc(t_print *ele);
char						*itoa_base(long long int h, int base, int g);
int							handen(t_print *ele);
int							handex(t_print *ele);
int							handep(t_print *tmp, char *arg);
int							isin1(char c);
int							handen1(t_print *ele);
int							ft_printf(const char *s, ...);
int							handelper(t_print *ele);
int							handeu(t_print *ele);
char						*itoa_base10(unsigned long long h,
	int base, int g);
int							printspaces(int l);
int							printzeros(int l);
int							detect_base(char c);
int							detect(char c);
int							isin2(char c);
void						*ft_calloc(size_t count, size_t size);
size_t						ft_strlen(const char *s);
void						ft_bzero(void *s, size_t n);
int							ft_isdigit(int c);
int							whatl(t_print *ele, va_list ap);
int							whatl1(t_print *ele, va_list ap);
int							handexl(t_print *ele);
int							handelcl(t_print *ele);
int							handels(t_print *ele);
size_t						wcslen1(wchar_t *wcs);
int							handeull(t_print *ele);
int							handexll(t_print *ele);
int							whatll(t_print *ele, va_list ap);
int							whath(t_print *ele, va_list ap);
void						what2(t_print *ele, va_list ap, int n);
void						taskoned4(const char *s, int *i, t_print *tmp1);
void						taskoned5(const char *s, int *i, t_print *tmp1);
void						init(t_print *tmp);
int							ft_atoi(const char *s);

#endif
