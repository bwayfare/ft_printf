#include "ft_printf.h"

void 	ft_hexwidthpon(p_list *list, int len)
{
	if (list->width < list->pon)
	{
		list->width = 0;
		list->pon -= len;
	}
	else if (list->pon != -1 && list->pon > len)
	{
		list->width -= list->pon;
		list->pon -= len;
	}
	else
	{
		list->pon = 0;
		list->width -= len + 1;
	}
}

void 	ft_hexprint(p_list *list, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (list->def)
	{
		while (j++ < list->pon - 1)
			write(1, "0", 1);
		while (*str)
			write(1, str++, 1);
		while (i++ < list->width)
			write(1, " ", 1);
	}
	else
	{
		while (i++ < list->width)
			write(1, " ", 1);
		while (j++ < list->pon - 1)
			write(1, "0", 1);
		while (*str)
			write(1, str++, 1);
	}
}