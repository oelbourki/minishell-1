/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaali <ibaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:40:27 by ibaali            #+#    #+#             */
/*   Updated: 2019/11/13 10:27:17 by ibaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_flag
{
	int			minus;
	int			zero;
	int			dot;
	int			width;
	int			precesion;
	char		conver;
	int			star_wid;
	int			star_pres;
}				t_flag;

int				ft_printf(const char *format, ...);
int				ft_putchar_fd(char c, int fd);
void			chose_convertion(const char *format, int *ret,
														int i, va_list ap);
char			*ft_strchr(const char *str, int c);
int				ft_isdigit(int c);
int				ft_atoi(char *str);
int				get_number(const char *format, int *i, va_list ap);
void			init_flag_strc(t_flag *strc);
int				fill_flag_strc(const char *format, int i,
												va_list ap, t_flag *strc);
void			optimize_stuct(t_flag *strc);
void			integer_process(t_flag *strc, va_list ap, int *ret);
void			ft_putnbr_fd(long n, int fd);
void			ft_putstr_fd(char *s, int fd);
int				cnt_digit(long number);
int				nb_betwen_percnt_conv(t_flag *strc);
int				put_nbr(int number, t_flag *strc, int *ret);
int				no_flag(t_flag *strc);
int				flag_zero(t_flag *strc);
int				flag_minus(t_flag *strc);
void			no_flag_process_int(t_flag *strc, va_list ap, int *ret);
void			put_zero(int nb_zero);
void			put_space(int nb_space);
void			zero_flag_process_int(t_flag *strc, va_list ap, int *ret);
void			resume_zero_flag_int(t_flag *strc, long *number, int nb_space);
void			minus_flag_process_int(t_flag *strc, va_list ap, int *ret);
void			unsigned_int_process(t_flag *strc, va_list ap, int *ret);
void			unsigned_int_no_flag(t_flag *strc, va_list ap, int *ret);
void			putnbr_unsigned_fd(unsigned int n, int fd);
int				unsigned_cnt_digit(unsigned int number);
void			unsigned_int_zero_flag(t_flag *strc, va_list ap, int *ret);
void			unsigned_int_minus_flag(t_flag *strc, va_list ap, int *ret);
char			*itoa_base(unsigned int number, int base);
void			hex_process(t_flag *strc, va_list ap, int *ret);
void			hex_no_flag(t_flag *strc, va_list ap, int *ret);
void			ft_strrev(char *str);
int				ft_strlen(const char *s);
char			*string_toupper(char *str);
void			hex_zero_flag(t_flag *strc, va_list ap, int *ret);
void			hex_minus_flag(t_flag *strc, va_list ap, int *ret);
char			*unsigned_l_itoa_base(size_t number, int base);
void			poinet_no_flag(t_flag *strc, va_list ap, int *ret);
void			pointer_process(t_flag *strc, va_list ap, int *ret);
void			poinet_minus_flag(t_flag *strc, va_list ap, int *ret, int nul);
void			no_flag_process_char(t_flag *strc, va_list ap, int *ret);
void			minus_flag_process_char(t_flag *strc, va_list ap, int *ret);
void			char_process(t_flag *strc, va_list ap, int *ret);
void			ft_putstr_limit_fd(char *s, int fd, int limit);
void			string_process(t_flag *strc, va_list ap, int *ret);
void			flag_process_string_nodot(t_flag *strc, va_list ap,
														int *ret, int minus);
void			flag_process_string_dot(t_flag *strc, va_list ap,
														int *ret, int minus);
char			*ft_strdup(const char *s1);
void			module_process(t_flag *strc, int *ret);
void			no_flag_process_module(t_flag *strc, int *ret, int minus);
void			zero_flag_process_module(t_flag *strc, int *ret);

#endif
