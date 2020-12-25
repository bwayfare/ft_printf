#include "ft_printf.h"

long int 	ft_printint(va_list arg, p_list *list)
{
	char	*tstr;
	int		len;
	int		i;

	i = 0;
	tstr = ft_itoa(va_arg(arg, int));
	len = ft_strlen(tstr);
	list->width = len > list->width ? 0 : list->width - len;
	if (list->def == 0)
	{
		if (list->zap == '0')
		{
			if (list->poz == 1)
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
			else
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
		}
		else
		{
			if (list->poz == 1)
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
			else
			{
				if (*tstr == '-')
				{
					while (i++ < list->width)
						write(1, " ", 1);
					write(1, tstr, 1);
					tstr[0] = '\0';
					write(1, tstr, len);
				} else
				{
					while (i++ < list->width)
						write(1, " ", 1);
					write(1, tstr, len);
				}
			}
		}
	}
	else
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
	free(tstr);
	return (list->width + len);
}