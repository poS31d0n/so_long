/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:12:41 by hjanis            #+#    #+#             */
/*   Updated: 2021/11/12 16:39:10 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *s1)
{
	int		i;
	size_t	len;
	char	*new_str;

	len = ft_strlen(s1);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str || !s1)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
