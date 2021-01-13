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
	if (list->flag == 1)
		list->zap = ' ';
	if (list->pon == 0 && tstr[0] == '0')
	{
		list->flag = 5;
		list->len -= 1;
	}
	if (tstr[0] == '-' || list->poz == 1)
	{
		if (list->pon >= list->width || list->pon > len)
			list->pon++;
	}
	if (list->width < list->pon)
	{
		list->width = 0;
		list->pon -= len;
	}
	else if (list->pon != -1 && list->pon > len)
	{
		list->width -= list->pon;
		list->pon -= len;
	}
	else if (list->flag != 5)
	{
		list->pon = 0;
		if (list->width > len)
			list->width -= len;
		else
			list->width = 0;
	}
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
	if (list->flag != 4)
	{
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
	}
	return (i + j);
}
