/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:41:05 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/09 18:41:06 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_longgetsize(long int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_longcreateascii(char *res, long int n, int size, int len)
{
	res[size] = '\0';
	size--;
	while (size > len)
	{
		if (n > 9)
		{
			res[size] = n % 10 + '0';
			n = n / 10;
		}
		else
		{
			res[size] = n % 10 + '0';
			n = 0;
		}
		size--;
	}
	return (res);
}

char	*ft_longtoa(long int number)
{
	int			size;
	char		*res;
	long int	n;

	n = number;
	size = ft_longgetsize(number);
	if (n == 0)
		size = 1;
	if (n < 0)
		res = (char *)ft_calloc(sizeof(char), size + 2);
	else
		res = (char *)ft_calloc(sizeof(char), size + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		return (ft_longcreateascii(res, (n * -1), size + 1, 0));
	}
	else
		return (ft_longcreateascii(res, n, size, -1));
}
