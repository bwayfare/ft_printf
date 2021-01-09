/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:28:59 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/09 18:30:19 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_goch(const char *str, const char *ch)
{
	int i;
	int flag;
	int j;

	i = 0;
	j = 0;
	flag = 0;
	while (str[j] && flag != 1)
	{
		while (ch[i] && flag != 1)
		{
			if (str[j + 1] == ch[i])
				flag = 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (j);
}

int		ft_singltype(char ch, char *set)
{
	while (*set != '\0')
	{
		if (ch == *set)
			return (1);
		set++;
	}
	return (2);
}

int		ft_checkflag(char ch, t_list *list)
{
	if ((ch == ' ' || ch == '0') && list->flag == 0)
	{
		list->zap = ch;
		return (1);
	}
	else if (ch == '-' && list->flag == 0)
	{
		list->def = 1;
		return (1);
	}
	else if (ch == '+' && list->flag == 0)
	{
		list->poz = 1;
		return (1);
	}
	else if (ch == '#' && list->flag == 0)
	{
		list->sharp = 1;
		return (1);
	}
	return (0);
}

int		ft_checkwidth(va_list *arg, const char *str, t_list *list)
{
	const char	*head;

	head = str;
	if (*str >= '0' && *str <= '9' && list->flag == 0)
		list->width = ft_atoi(str);
	else if (*str == '*' && list->flag == 0)
		list->width = va_arg(*arg, int);
	str += ft_goch(str, ".pducisxX%\0");
	if (list->width < 0)
	{
		list->width *= -1;
		list->def = 1;
	}
	return ((int)(str - head));
}

int		ft_checkpon(va_list *arg, const char *str,
				 t_list *list, const char *head)
{
	if (*str >= '0' && *str <= '9')
		list->pon = ft_atoi(str);
	else if (*str == '*')
		list->pon = va_arg(*arg, int);
	if (list->pon < 0)
		list->pon = -1;
	str += ft_goch(str, "pducisxX%\0");
	return ((int)(str - head));
}
