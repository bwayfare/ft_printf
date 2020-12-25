#include "ft_printf.h"

void 		ft_intzappoz(char *tstr, int len, p_list *list, int i)
{
	if (*tstr == '-')
	{
		write(1, tstr, 1);
		tstr[0] = '\0';
		while (i++ < list->width)
			write(1, &list->zap, 1);
		write(1, tstr, len);
	}
	else
	{
		write(1, "+", 1);
		while (i++ < list->width - 1)
			write(1, &list->zap, 1);
		write(1, tstr, len);
	}
}

void 		ft_intzap(char *tstr, int len, p_list *list, int i)
{
	if (*tstr == '-')
	{
		write(1, tstr, 1);
		tstr[0] = '\0';
		while (i++ < list->width)
			write(1, &list->zap, 1);
		write(1, tstr, len);
	}
	else
	{
		while (i++ < list->width)
			write(1, &list->zap, 1);
		write(1, tstr, len);
	}
}

void 		ft_intpoz(char *tstr, int len, p_list *list, int i)
{
	if (*tstr == '-')
	{
		while (i++ < list->width)
			write(1, " ", 1);
		write(1, tstr, 1);
		tstr[0] = '\0';
		write(1, tstr, len);
	}
	else
	{
		while (i++ < list->width - 1)
			write(1, " ", 1);
		write(1, "+", 1);
		list->width++;
		write(1, tstr, len);
	}
}

void 		ft_intpozelse(char *tstr, int len, p_list *list, int i)
{
	if (*tstr == '-')
	{
		while (i++ < list->width)
			write(1, " ", 1);
		write(1, tstr, 1);
		tstr[0] = '\0';
		write(1, tstr, len);
	}
	else
	{
		while (i++ < list->width)
			write(1, " ", 1);
		write(1, tstr, len);
	}
}

void 		ft_intdef(char *tstr, int len, p_list *list, int i)
{
	if (*tstr == '-')
	{
		write(1, tstr, len);
		while (i++ < list->width)
			write(1, " ", 1);
	}
	else
	{
		if (list->poz == 1)
			write(1, "+", 1);
		write(1, tstr, len);
		while (i++ < list->width - 1)
			write(1, " ", 1);
	}
}