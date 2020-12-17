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
	int 			sharp;
	char            zap;
	int             flag;
}					p_list;


long int			ft_printf(char *str, ...);
int 				ft_singltype(char ch, char *set);
int					ft_goch(char *str, char *ch);
long int			ft_printstring(p_list *list, va_list arg);
int 				ft_checkflag(char ch, p_list *list);
long int			ft_checkwidth(va_list *arg, char *str, p_list *list);
long int			ft_checkpon(va_list *arg, char *str, p_list *list, char *head);
long int			ft_printchar(p_list *list, va_list arg);

#endif