#include "ft_printf.h"

long int    ft_proc(va_list *arg, char *str, p_list *list)
{
	char *head = str;
	while (*str)
	{
		if (*str == '.')
		{
			list->flag = 1;
			str++;
			continue;
		}
		if (ft_checkflag(*str, list))
		{
			str++;
			continue;
		}
		else if (list->flag == 0 && (str += ft_checkwidth(arg, str, list)))
		{
			continue;
		}
		else if ((*str >= '0' && *str <= '9') || *str == '*')
			return (ft_checkpon(arg, str, list, head));
		str++;
	}
	return (str - head);
}

void        ft_prin(va_list *arg, char *str, p_list *list)
{
	char        *tstr;
	if (*str++ == 'd')
	{
		tstr = ft_itoa(va_arg(*arg, int));
		list->len += ft_strlen(tstr);
		ft_putstr_fd(tstr, 1);
		free(tstr);
		str++;
	}
}

long int    ft_printf(char *str, ...)
{
	p_list 		list;
	long int 	len;

	len = 0;
	list.len = 0;
	list.flag = 0;
	if (!str)
		return (0);
	va_list arg;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			len = ft_proc(&arg, ++str, &list);
			str += len;
			ft_prin(&arg, str++, &list);
		}
		ft_putchar_fd(*str, 1);
		list.len++;
		str++;
	}
	return (list.len);
}