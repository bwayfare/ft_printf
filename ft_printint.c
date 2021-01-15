/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:53:45 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/09 19:39:20 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_intzappoz(char *tstr, t_list *list, int *i, int *j)
{
	int iter;

	iter = 1;
	if (*tstr == '-')
	{
		write(1, tstr, 1);
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		while (tstr[iter] && list->flag != 5)
			write(1, &tstr[iter++], 1);
	}
	else
	{
		write(1, "+", 1);
		while ((*i)++ < list->width - 1)
			write(1, &list->zap, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		if (list->flag != 5)
			write(1, tstr, ft_strlen(tstr));
	}
	*j -= 2;
}

void	ft_intzap(char *tstr, t_list *list, int *i, int *j)
{
	int iter;

	iter = 1;
	if (*tstr == '-')
	{
		write(1, tstr, 1);
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		while (tstr[iter] && list->flag != 5)
			write(1, &tstr[iter++], 1);
	}
	else
	{
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		if (list->flag != 5)
		write(1, tstr, ft_strlen(tstr));
	}
	*j -= 2;
}

void	ft_intpoz(char *tstr, t_list *list, int *i, int *j)
{
	int iter;

	iter = 1;
	if (*tstr == '-')
	{
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
		write(1, tstr, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		while (tstr[iter] && list->flag != 5)
			write(1, &tstr[iter++], 1);
	}
	else
	{
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
		write(1, "+", 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		list->width++;
		if (list->flag != 5)
			write(1, tstr, ft_strlen(tstr));
	}
	*j -= 2;
}

void	ft_intpozelse(char *tstr, t_list *list, int *i, int *j)
{
	int iter;

	iter = 1;
	if (*tstr == '-')
	{
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
		write(1, tstr, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		while (tstr[iter] && list->flag != 5)
			write(1, &tstr[iter++], 1);
	}
	else
	{
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		if (list->flag != 5)
			write(1, tstr, ft_strlen(tstr));
	}
	*j -= 2;
}

void	ft_intdef(char *tstr, t_list *list, int *i, int *j)
{
	int iter;

	iter = 1;
	if (*tstr == '-')
	{
		write(1, tstr, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		while (tstr[iter] && list->flag != 5)
			write(1, &tstr[iter++], 1);
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
	}
	else
	{
		if (list->poz == 1)
			write(1, "+", 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		if (list->flag != 5)
			write(1, tstr, ft_strlen(tstr));
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
	}
	*j -= 2;
}
