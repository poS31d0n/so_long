/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:03:52 by hjanis            #+#    #+#             */
/*   Updated: 2021/11/12 18:32:17 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->length = 0;
	tab->dash = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = -1;
	res = 0;
	if (!format[0])
		return (0);
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_format(tab, format, i + 1);
		else
			res += write(1, &format[i], 1);
	}
	res += tab->length;
	va_end(tab->args);
	free (tab);
	return (res);
}
