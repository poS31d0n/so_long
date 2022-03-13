/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:54:52 by hjanis            #+#    #+#             */
/*   Updated: 2021/11/12 18:33:37 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_print *tab, char f)
{
	char	c;

	if (f == '%')
		tab->length += write(1, "%", 1);
	if (f == 'c')
	{
		c = va_arg(tab->args, int);
		while (tab->wdt-- > 1 && tab->dash == 0)
			tab->length += write(1, " ", 1);
		tab->length += write(1, &c, 1);
		while (tab->wdt-- > 0 && tab->dash == 1)
			tab->length += write(1, " ", 1);
	}
}

void	ft_string(t_print *tab)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	while (tab->wdt-- > ft_strlen(str) && !tab->dash)
		tab->length += write(1, " ", 1);
	while (str[i])
		tab->length += write(1, &str[i++], 1);
	while (tab->wdt-- > ft_strlen(str) && tab->dash)
		tab->length += write(1, " ", 1);
}

void	ft_pointer(t_print *tab)
{
	unsigned long	n;

	n = (unsigned long)va_arg(tab->args, void *);
	while (tab->wdt-- > 11 && !tab->dash)
		tab->length += write(1, " ", 1);
	tab->length += write(1, "0x", 2);
	tab->length += ft_putnbr_base(n, "0123456789abcdef");
	while (tab->wdt-- > 11 && tab->dash)
		tab->length += write(1, " ", 1);
}
