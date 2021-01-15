/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intproc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:34:40 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/09 19:36:57 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkponwidth(t_list *list, int len, char *tstr)
{
	if (*tstr == '-')
	{
		len--;
		list->width--;
	}
	if (list->flag == 1  && (list->width > list->pon))
		if (list->pon > len || list->pon > 0)
			list->zap = ' ';
	if (list->def == 1 || list->pon == 0)
		list->zap = ' ';
	if (*tstr == '0' && list->pon == 0)
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
}

int		ft_uintcheck(long int temp, t_list *list)
{
	char *tstr;

	if (temp < 0)
		return (0);
	else
	{
		tstr = ft_longtoa(temp);
		list->flag = ft_printint(tstr, list, 0, 0) + (int)ft_strlen(tstr);
		free(tstr);
		return (list->flag);
	}
}

int		ft_printint(char *tstr, t_list *list, int i, int j)
{
	ft_checkponwidth(list, ft_strlen(tstr), tstr);
	if (list->def == 0)
	{
		if (list->zap == '0')
		{
			if (list->poz == 1)
				ft_intzappoz(tstr, list, &i, &j);
			else
				ft_intzap(tstr, list, &i, &j);
		}
		else
		{
			if (list->poz == 1)
				ft_intpoz(tstr, list, &i, &j);
			else
				ft_intpozelse(tstr, list, &i, &j);
		}
	}
	else
		ft_intdef(tstr, list, &i, &j);
	return (i + j);
}
