/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:31:12 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/09 18:31:38 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexwidthpon(t_list *list, int len, int flag)
{
	if (list->flag == 1 && (list->width > list->pon))
		if (list->pon > len || list->pon > 0)
			list->zap = ' ';
	if (list->def == 1 || list->pon == 0)
		list->zap = ' ';
	if (flag == 1 && list->pon == 0)
	{
		list->flag = 5;
		list->width++;
		list->len--;
	}
	if (list->pon < 0 || list->pon < len)
		list->pon = len;
	if (list->width < 0)
		list->width = 0;
	list->width -= list->pon;
	list->pon -= len;
	if (list->pon < 0)
		list->pon = 0;
	if (list->width < 0)
		list->width = 0;
}

void	ft_hexprint(t_list *list, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (list->def)
	{
		while (j++ < list->pon)
			write(1, "0", 1);
		while (*str && list->flag != 5)
			write(1, str++, 1);
		while (i++ < list->width)
			write(1, &list->zap, 1);
	}
	else
	{
		while (i++ < list->width)
			write(1, &list->zap, 1);
		while (j++ < list->pon)
			write(1, "0", 1);
		while (*str && list->flag != 5)
			write(1, str++, 1);
	}
}
