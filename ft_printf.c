/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:43:01 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/09 18:47:37 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_proc(va_list *arg, char *str, t_list *list)
{
	char *head;

	head = str;
	while (*str)
	{
		if (ft_singltype(*str, "pduicsxX\0"))
			return ((int)(str - head));
		if (*str == '.')
		{
			list->flag = 1;
			str++;
			if ((*str >= '0' && *str <= '9') || *str == '*')
				return (ft_checkpon(arg, str, list, head));
			else if (ft_singltype(*str, "pduicsxX\0"))
			{
				list->pon = 0;
				return ((int)(str - head));
			}
		}
		if (ft_checkflag(*str, list))
			str++;
		else if (list->flag == 0 && (str += ft_checkwidth(arg, str, list)))
			continue;
	}
	return ((int)(str - head));
}

int		ft_prin(va_list *arg, char *str, t_list *list, int flag)
{
	if (flag == 0)
	{
		write(1, str, 1);
		return (1);
	}
	if (*str == '%')
	{
		write(1, "%", 1);
		return (-2);
	}
	if (ft_singltype(*str, "pduicsxX\0"))
		return (ft_printtype(str, arg, list));
	return (1);
}

void	ft_initlist(t_list *list)
{
	list->def = 0;
	list->zap = 0;
	list->poz = 0;
	list->width = -1;
	list->pon = -1;
	list->sharp = 0;
	list->flag = 0;
}

int		ft_start(va_list *arg, t_list *list, int step, char *str)
{
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) != '%')
			{
				ft_initlist(list);
				step = ft_proc(arg, ++str, list);
				str += step;
				step = ft_prin(arg, str++, list, 1);
				if (step != -1)
					list->len += step;
				else
				{
					list->len = -1;
					return (-1);
				}
			}
			else
				str++;
		}
		list->len++;
		ft_prin(arg, str++, list, 0);
	}
	return (1);
}

int		ft_printf(char *str, ...)
{
	t_list		list;
	va_list		arg;

	list.len = 0;
	if (!str)
		return (0);
	va_start(arg, str);
	ft_start(&arg, &list, 0, str);
	va_end(arg);
	return (list.len);
}
