/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:37:35 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/09 19:41:29 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printtype(char *str, va_list *arg, t_list *list)
{
	char	*tstr;

	if (*str == 's')
		return (ft_printstring(list, va_arg(*arg, char *)));
	if (*str == 'c')
		return (ft_printchar(list, *arg));
	if (*str == 'd' || *str == 'i')
	{
		tstr = ft_itoa(va_arg(*arg, int));
		list->flag = (int)ft_strlen(tstr) + ft_printint(tstr, list, 0, 0);
		free(tstr);
		return (list->flag);
	}
	if (*str == 'u')
		return (ft_uintcheck(va_arg(*arg, unsigned int), list));
	if (*str == 'X')
		return (ft_hexproc(list, va_arg(*arg, long int), 1));
	if (*str == 'x')
		return (ft_hexproc(list, va_arg(*arg, long int), 0));
	else
		return (ft_hexproc(list, va_arg(*arg, unsigned long), 2));
}
