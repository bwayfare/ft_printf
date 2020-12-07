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

int 		ft_checkflag(char ch, p_list *list)
{
	if ((ch == ' ' || ch == '0') && list->flag == 0)
	{
		list->zap = ch;
		return (1);
	}
	else if (ch == '-' && list->flag == 0)
	{
		list->def = 1;
		return (1);
	}
	else if (ch == '+' && list->flag == 0)
	{
		list->poz = 1;
		return (1);
	}
	else if (ch == '#' && list->flag == 0)
	{
		list->sharp = 1;
		return (1);
	}
	return (0);
}

long int	 ft_checkwidth(va_list *arg, char *str, p_list *list)
{
	char	*head;

	head = str;
	if (*str >= '0' && *str <= '9' && list->flag == 0)
	{
		list->width = ft_atoi(str);
		str += ft_goch(str, ".\0");
		return (str - head);
	}
	else if (*str == '*' && list->flag == 0)
	{
		list->width = va_arg(*arg, int);
		str = str + ft_goch(str, ".\0");
		return (1);
	}
	return (1);
}

long int	ft_checkpon(va_list *arg, char *str, p_list *list, char *head)
{
	if (*str >= '0' && *str <= '9')
	{
		list->pon = ft_atoi(str);
		str = str + ft_goch(str, "ducsxX\0");
		return (str - head);
	}
	else if (*str == '*')
	{
		list->pon = va_arg(*arg, int);
		str += ft_goch(str, "ducsxX\0");
		return (str - head);
	}
	return (str - head);
}