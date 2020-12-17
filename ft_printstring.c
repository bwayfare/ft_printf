#include "ft_printf.h"

long int	ft_printstringdef(long int len, p_list *list, char *str)
{
	if (len > list->pon && list->pon != -1)
		len = list->pon;
	else
		list->pon = len;
	if (len > list->width)
		list->width = len;
	if (list->pon <= list->width)
	{
		write(1, str, len);
		while (len++ < list->width)
			write(1, " ", 1);
	}
	return (list->width);
}

long int 	ft_printstring(p_list *list, va_list arg)
{
	long int 	len;
	char		*str;
	long int 	i;

	i = 0;
	str = va_arg(arg, char *);
	len = ft_strlen(str);
	if (list->def)
		return (ft_printstringdef(len, list, str));
	else
	{
		if (len > list->pon && list->pon != -1)
			len = list->pon;
		else
			list->pon = len;
		if (len > list->width)
			list->width = len;
		if (list->pon <= list->width)
		{
			while (i++ < list->width - len)
				write(1, " ", 1);
			write(1, str, len);
		}
		return (list->width);
	}
}