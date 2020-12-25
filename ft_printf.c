#include "ft_printf.h"

long int    ft_proc(va_list *arg, char *str, p_list *list)
{
	char *head = str;
	while (*str)
	{
		if (ft_singltype(*str, "ducsxX\0"))
			return (str - head);
		if (*str == '.')
		{
			list->flag = 1;
			str++;
			if ((*str >= '0' && *str <= '9') || *str == '*')
				return (ft_checkpon(arg, str, list, head));
			else if (ft_singltype(*str, "ducsxX\0"))
				{
					list->pon = 0;
					return (str - head);
				}
		}
		if (ft_checkflag(*str, list))
			str++;
		else if (list->flag == 0 && (str += ft_checkwidth(arg, str, list)))
			continue;
	}
	return (str - head);
}

long int        ft_prin(va_list *arg, char *str, p_list *list)
{
	if (*str == 's')
		return (ft_printstring(list, *arg));
	if (*str == 'c')
		return (ft_printchar(list, *arg));
	if (*str == '%')
	{
		write(1, "%", 1);
		return (-2);
	}
	if (*str == 'd')
	{
		return (ft_printint(ft_itoa(va_arg(*arg, int)), list, 0));
	}
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

long int 	ft_start(va_list *arg, p_list *list, long int step, char *str)
{
	list->len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) != '%')
			{
				ft_initlist(list);
				step = ft_proc(arg, ++str, list);
				if (step == -1)
					return (-1);
				str += step;
				step = ft_prin(arg, str++, list);
				if (step != -1)
					list->len += step;
				continue;
			}
			else
				str++;
		}
		ft_putchar_fd(*str, 1);
		list->len++;
		str++;
	}
	return (1);
}

long int    ft_printf(char *str, ...)
{
	p_list 		list;

	if (!str)
		return (0);
	va_list arg;
	va_start(arg, str);
	ft_start(&arg, &list, 0, str);
	return (list.len);
}