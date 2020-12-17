#include "ft_printf.h"

long int	ft_printchar(p_list *list, va_list arg)
{
	long int 		len;
	unsigned char	str;
	long int 		i;

	i = 0;
	str = (char)va_arg(arg, int);
	len = 1;
	if (len > list->width)
		list->width = len;
	if (list->def)
	{
		write(1, &str, len);
		while (len++ < list->width)
			write(1, " ", 1);
	}
	else
	{
		while (i++ < list->width - len)
			write(1, " ", 1);
		write(1, &str, len);
	}
	return (list->width);
}