#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct		print_list
{
	long int        width;
	long int        pon;
	long int        len;
	int             poz;
	int             def;
	char            zap;
	int             flag;
}					p_list;


long int			ft_printf(char *str, ...);
int 				ft_checkznak(char ch, p_list *list);
int 				ft_checkwidth(va_list *arg, char *str, p_list *list);
long int			ft_checkpon(va_list *arg, char *str, p_list *list, char *head);


#endif