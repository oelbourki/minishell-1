/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:54:44 by oel-bour          #+#    #+#             */
/*   Updated: 2020/02/06 15:44:38 by oel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# define MAX(a,b) ((a < b) ? (b) : (a))

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

int							ft_putstr(int fd, char *s, int l);
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
