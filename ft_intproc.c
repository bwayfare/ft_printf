#include "ft_printf.h"

void		ft_checkponwidth(p_list *list, int len, char *tstr, int *i)
{
	if (list->pon == 0 && tstr[0] == '0')
	{
		list->flag = 5;
		*i -= 2;
	}
	if (tstr[0] == '-'|| list->poz == 1)
	{
		if (list->pon >= list->width || list->pon > len)
			list->pon++;
	}
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
		list->width -= len;
	}
}

long int ft_printint(char *tstr, p_list *list, int i, int j)
{
	int		len;

	len = ft_strlen(tstr);
	ft_checkponwidth(list, len, tstr, &i);
	if (list->flag != 5)
	{
		if (list->def == 0)
		{
			if (list->zap == '0')
			{
				if (list->poz == 1)
					ft_intzappoz(tstr, len, list, &i, &j);
				else
					ft_intzap(tstr, len, list, &i, &j);
			} else
			{
				if (list->poz == 1)
					ft_intpoz(tstr, len, list, &i, &j);
				else
					ft_intpozelse(tstr, len, list, &i, &j);
			}
		} else
			ft_intdef(tstr, len, list, &i, &j);
	}
	free(tstr);
	return (i + j + len);
}