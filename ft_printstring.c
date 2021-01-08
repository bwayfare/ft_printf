#include "ft_printf.h"

int 	ft_printstring(p_list *list, va_list arg)
{
	int 		len;
	char		*str;
	int 		i;

	i = 0;
	str = va_arg(arg, char *);
	len = ft_strlen(str);
	if (len > list->pon && list->pon != -1)
		len = list->pon;
	else
		list->pon = len;
	if (len > list->width)
		list->width = len;
	if (list->def)
	{
		write(1, str, len);
		while (len++ < list->width)
			write(1, " ", 1);
	}
	else
	{
		while (i++ < list->width - len)
			write(1, " ", 1);
		write(1, str, len);
	}
	return (list->width);
}