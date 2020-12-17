#include "ft_printf.h"

long int    ft_proc(va_list *arg, char *str, p_list *list)
{
	char *head = str;
	while (*str)
	{
		if (ft_singltype(*str, "ducsxX\0"))
			return (0);
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
	char        *tstr;
	if (*str == 's')
	{
		str++;
		return (ft_printstring(list, *arg, 0));
	}
	if (*str++ == 'd')
	{
		tstr = ft_itoa(va_arg(*arg, int));
		list->len += ft_strlen(tstr);
		ft_putstr_fd(tstr, 1);
		free(tstr);
		str++;
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

long int    ft_printf(char *str, ...)
{
	p_list 		list;
	long int 	step;

	step = 0;
	if (!str)
		return (0);
	va_list arg;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			ft_initlist(&list);
			step = ft_proc(&arg, ++str, &list);
			if (step == -1)
				return (-1);
			str += step;
			step = ft_prin(&arg, str++, &list);
			if (step != -1)
				list.len += step;
		}
		ft_putchar_fd(*str, 1);
		list.len++;
		str++;
	}
	return (list.len);
}