/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:22:06 by jimbaek           #+#    #+#             */
/*   Updated: 2021/06/21 18:02:55 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef	struct	s_info
{
	int			valid;
	int			minus;
	int			zero;
	int			width;
	int			precision;
	char		conversion;
	int			nbr_sign;
	int			nbr_base;
	int			nbr_prefix;
}				t_info;

int				print_data(va_list ap, t_info *info);
int				print_format(va_list ap, t_info	*info, char *format);
int				ft_printf(const char *format, ...);

int				print_chr(t_info *info, int data);
int				print_str(t_info *info, char *data);
int				print_nbr(t_info *info, unsigned long long data);

int				put_empty(int zero, int len);
int				put_chr(int data);
int				put_str(char *data, int len);
int				put_nbr(t_info *info, unsigned long long data, char **buf);
void			put_nbr_data(t_info *info, unsigned long long data, \
				int len, char **buf);

void			init_info(t_info *info);
void			check_width_and_precision(va_list ap, t_info *info, char c);
int				check_info(va_list ap, t_info *info, char c);
void			check_info_nbr(t_info *info, unsigned long long data);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
int				ft_nbrlen(unsigned long long nbr, int base);

char			*get_base(char conversion);

#endif
