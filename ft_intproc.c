#include "ft_printf.h"

long int 	ft_printint(char *tstr, p_list *list, int i, int j)
{
	int		len;

	len = ft_strlen(tstr);
	list->width = len > list->width ? 0 : list->width - len;
	if (list->def == 0)
	{
		if (list->zap == '0')
		{
			if (list->poz == 1)
				ft_intzappoz(tstr, len, list, &i, &j);
			else
				ft_intzap(tstr, len, list, &i, &j);
		}
		else
		{
			if (list->poz == 1)
				ft_intpoz(tstr, len, list, &i, &j);
			else
				ft_intpozelse(tstr, len, list, &i, &j);
		}
	}
	else
		ft_intdef(tstr, len, list, &i, &j);
	free(tstr);
	return (i + j + len);
}