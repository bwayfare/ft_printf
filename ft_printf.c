#include "ft_printf.h"

int    ft_proc(va_list *arg, char *str, p_list *list)
{
	char *head = str;
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

int        ft_prin(va_list *arg, char *str, p_list *list, int flag)
{
	if (flag == 0)
	{
		write(1, str, 1);
		return (1);
	}
	if (*str == 's')
		return (ft_printstring(list, va_arg(*arg, char *)));
	if (*str == 'c')
		return (ft_printchar(list, *arg));
	if (*str == '%')
	{
		write(1, "%", 1);
		return (-2);
	}
	if (*str == 'd' || *str == 'i')
		return (ft_printint(ft_itoa(va_arg(*arg, int)), list, 0, 0));
	if (*str == 'u')
		return (ft_uintcheck(va_arg(*arg, unsigned int), list));
	if (*str == 'X')
		return (ft_hexproc(list, va_arg(*arg, long int), 1));
	if (*str == 'x')
		return (ft_hexproc(list, va_arg(*arg, long int), 0));
	if (*str == 'p')
		return (ft_hexproc(list, va_arg(*arg, unsigned long), 2));
	return (1);
}

void 		ft_initlist(p_list *list)
{
	list->def = 0;
	list->zap = 0;
	list->poz = 0;
	list->width = -1;
	list->pon = -1;
	list->sharp = 0;
	list->flag = 0;
}

int 	ft_start(va_list *arg, p_list *list, int step, char *str)
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
				continue;
			}
			else
				str++;
		}
		list->len++;
		ft_prin(arg, str++, list, 0);
	}
	return (1);
}

int    ft_printf(char *str, ...)
{
	p_list 		list;

	list.len = 0;
	if (!str)
		return (0);
	va_list arg;
	va_start(arg, str);
	ft_start(&arg, &list, 0, str);
	return (list.len);
}