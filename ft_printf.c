#include "ft_printf.h"

int        ft_goch(char *str, char *ch)
{
	int i;
	int flag;
	int j;

	i = 0;
	j = 0;
	flag = 0;
	while (str[j] && flag != 1)
	{
		while (ch[i] && flag != 1)
		{
			if (str[j + 1] == ch[i])
				flag = 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (j);
}

long int    ft_proc(va_list *arg, char *str, p_list *list)
{
	char *h = str;
	while (*str)
	{
		if ((*str == ' ' || *str == '0') && list->flag == 0)
			list->zap = *str;
		else if (*str == '-' && list->flag == 0)
			list->def = 1;
		else if (*str == '+' && list->flag == 0)
			list->poz = '1';
		else if (*str >= '0' && *str <= '9' && list->flag == 0)
		{
			list->wight = ft_atoi(str);
			str += ft_goch(str, ".\0");
		}
		else if (*str == '*' && list->flag == 0)
		{
			list->wight = va_arg(*arg, int);
			str = str + ft_goch(str, ".\0");
		}
		else if (*str >= '0' && *str <= '9')
		{
			list->pon = ft_atoi(str);
			str = str + ft_goch(str, "ducsxX\0");
			return (str - h);
		}
		else if (*str == '*')
		{
			list->pon = va_arg(*arg, int);
			str += ft_goch(str, "ducsxX\0");
			return (str - h);
		}
		if (*str == '.')
			list->flag = 1;
		str++;
	}
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
	p_list list;

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
			str += ft_proc(&arg, ++str, &list);
			ft_prin(&arg, str++, &list);
		}
		ft_putchar_fd(*str, 1);
		list.len++;
		str++;
	}
	return (list.len);
}