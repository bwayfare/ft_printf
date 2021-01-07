#include "ft_printf.h"

void 		ft_intzappoz(char *tstr, int len, p_list *list, int *i, int *j)
{
	int iter;

	iter = 1;
	if (*tstr == '-')
	{
		write(1, tstr, 1);
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		while (tstr[iter])
			write(1, &tstr[iter++], 1);
	}
	else
	{
		write(1, "+", 1);
		while ((*i)++ < list->width - 1)
			write(1, &list->zap, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		write(1, tstr, len);
	}
	*j -= 2;
}

void 		ft_intzap(char *tstr, int len, p_list *list, int *i, int *j)
{
	int iter;

	iter = 1;
	if (*tstr == '-')
	{
		write(1, tstr, 1);
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		while (tstr[iter])
			write(1, &tstr[iter++], 1);
	}
	else
	{
		while ((*i)++ < list->width)
			write(1, &list->zap, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		write(1, tstr, len);
	}
	*j -= 2;
}

void 		ft_intpoz(char *tstr, int len, p_list *list, int *i, int *j)
{
	int iter;

	iter = 1;
	if (*tstr == '-')
	{
		while ((*i)++ < list->width)
			write(1, " ", 1);
		write(1, tstr, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		while (tstr[iter])
			write(1, &tstr[iter++], 1);
	}
	else
	{
		while ((*i)++ < list->width)
			write(1, " ", 1);
		write(1, "+", 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		list->width++;
		write(1, tstr, len);
	}
	*j -= 2;
}

void 		ft_intpozelse(char *tstr, int len, p_list *list, int *i, int *j)
{
	int iter;

	iter = 1;
	if (*tstr == '-')
	{
		while ((*i)++ < list->width)
			write(1, " ", 1);
		write(1, tstr, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		while (tstr[iter])
			write(1, &tstr[iter++], 1);
	}
	else
	{
		while ((*i)++ < list->width)
			write(1, " ", 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		write(1, tstr, len);
	}
	*j -= 2;
}

void 		ft_intdef(char *tstr, int len, p_list *list, int *i, int *j)
{
	int iter;

	iter = 1;
	if (*tstr == '-')
	{
		write(1, tstr, 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		while (tstr[iter])
			write(1, &tstr[iter++], 1);
		while ((*i)++ < list->width)
			write(1, " ", 1);
	}
	else
	{
		if (list->poz == 1)
			write(1, "+", 1);
		while ((*j)++ < list->pon)
			write(1, "0", 1);
		write(1, tstr, len);
		while ((*i)++ < list->width)
			write(1, " ", 1);
	}
	*j -= 2;
}