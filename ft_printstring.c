/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:54:57 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/09 18:54:59 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(t_list *list, char *str, int len)
{
	int i;

	i = 0;
	if (list->def)
	{
		write(1, str, len);
		while (len++ < list->width)
			write(1, " ", 1);
	}
	else
	{
		while (i++ < list->width - len)
			write(1, &list->zap, 1);
		write(1, str, len);
	}
}

int		ft_printstring(t_list *list, char *str)
{
	int		len;
	char	stemp[7];

	stemp[0] = '(';
	stemp[1] = 'n';
	stemp[2] = 'u';
	stemp[3] = 'l';
	stemp[4] = 'l';
	stemp[5] = ')';
	stemp[6] = '\0';
	if (str == NULL)
		str = stemp;
	len = ft_strlen(str);
	if (len > list->pon && list->pon != -1)
		len = list->pon;
	else
		list->pon = len;
	if (len > list->width)
		list->width = len;
	ft_printstr(list, str, len);
	return (list->width);
}
