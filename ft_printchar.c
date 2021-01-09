/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:41:44 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/09 18:41:45 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printchar(t_list *list, unsigned char str)
{
	int				len;
	int				i;

	i = 0;
	len = 1;
	if (len > list->width)
		list->width = len;
	if (list->def)
	{
		write(1, &str, len);
		while (len++ < list->width)
			write(1, " ", 1);
	}
	else
	{
		while (i++ < list->width - len)
			write(1, &list->zap, 1);
		write(1, &str, len);
	}
	return (list->width);
}
