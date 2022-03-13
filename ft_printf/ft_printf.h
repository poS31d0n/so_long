/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:35:20 by hjanis            #+#    #+#             */
/*   Updated: 2022/03/07 20:03:03 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h> 
# include <stdarg.h>

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		dash;
	int		length;
}	t_print;

t_print	*ft_initialise_tab(t_print *tab);
int		ft_printf(const char *format, ...);
void	ft_int(t_print	*tab, char c);
int		ft_format(t_print *tab, const char *format, int pos);
void	ft_char(t_print *tab, char f);
void	ft_string(t_print *tab);
void	ft_percent(t_print *tab);
void	ft_pointer(t_print *tab);
void	ft_hex(t_print *tab, char c);
int		ft_putnbr_base(unsigned long n, char *base);
char	*ft_itoa_base(char *str, unsigned long n, int base, int c);
int		ft_numlenbase(unsigned int n, int base);
int		ft_strlen(const char *str);
char	*ft_unsigneditoa(unsigned int number);
int		ft_numlen(long int n);
int		ft_isdigit(int nb);
char	*ft_itoa(int n);
char	*ft_strdup(char *s1);

#endif