/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ponproc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:43:01 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/15 05:45:37 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ponrevhex(char *str)
{
	char temp;
	char *end;

	temp = '\0';
	end = str;
	while (*(end + 1) != '\0')
		end++;
	while (str != end && str < end)
	{
		temp = *str;
		*str = *end;
		*end = temp;
		end--;
		str++;
	}
}

char	ft_pongetlowhex(long int tint)
{
	if (tint == 10)
		return ('a');
	else if (tint == 11)
		return ('b');
	else if (tint == 12)
		return ('c');
	else if (tint == 13)
		return ('d');
	else if (tint == 14)
		return ('e');
	else
		return ('f');
}

void	ft_pongethex(unsigned long int temp, char *tstr)
{
	unsigned int tint;

	tint = 0;
	if (temp == 0)
		*tstr++ = '0';
	while (temp > 0)
	{
		tint = temp % 16;
		if (tint >= 10 && tint <= 15)
			*tstr++ = ft_pongetlowhex(tint);
		else
			*tstr++ = (char)(tint + '0');
		temp /= 16;
	}
	*tstr++ = 'x';
	*tstr++ = '0';
	*tstr = '\0';
}

int		ft_ponproc(t_list *list, unsigned long int temp)
{
	char	*tstr;
	char	*head;
	int		len;

	if (temp == 0)
		list->sharp = 1;
	tstr = ft_calloc(100, 1);
	head = tstr;
	ft_pongethex(temp, tstr);
	ft_ponrevhex(head);
	len = (int)ft_strlen(head);
	ft_hexwidthpon(list, len, list->sharp);
	ft_hexprint(list, head);
	free(head);
	return (len + list->width + list->pon);
}
