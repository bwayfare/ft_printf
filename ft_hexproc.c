#include "ft_printf.h"

void 	ft_revhex(char *str)
{
	char temp;
	char *end;

	temp = '\0';
	end = str;
	while (*(end + 1) != '\0')
		end++;
	while (str != end && str < end)
	{
		temp = *str;
		*str = *end;
		*end = temp;
		end--;
		str++;
	}
}


char 	ft_getlowhex(long int tint)
{
	if (tint == 10)
		return ('a');
	else if (tint == 11)
		return ('b');
	else if (tint == 12)
		return ('c');
	else if (tint == 13)
		return ('d');
	else if (tint == 14)
		return ('e');
	else
		return ('f');
}

char 	ft_getuphex(long int tint)
{
	if (tint == 10)
		return ('A');
	else if (tint == 11)
		return ('B');
	else if (tint == 12)
		return ('C');
	else if (tint == 13)
		return ('D');
	else if (tint == 14)
		return ('E');
	else
		return ('F');
}

void 	ft_gethex(long int temp, char *tstr, int flag)
{
	long int tint;

	tint = 0;
	while (temp > 0)
	{
		tint = temp % 16;
		if (tint >= 10 && tint <=15)
		{
			if (flag == 1)
				*tstr++ = ft_getuphex(tint);
			else
				*tstr++ = ft_getlowhex(tint);
		}
		else
			*tstr++ = (char)(tint + '0');
		temp /= 16;
	}
	*tstr = '\0';
}

int		ft_hexproc(p_list *list, long int temp, int flag)
{
	char 		*tstr;
	char 		*head;
	int 		len;

	tstr = ft_calloc(100, 1);
	head = tstr;
	ft_gethex(temp, tstr, flag);
	ft_revhex(head);
	len = (int)(tstr - head);
	ft_hexwidthpon(list, len);
	ft_hexprint(list, head);
	free(tstr);
	return (len + list->width + list->pon);
}