#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct		print_list
{
	long int        wight;
	long int        pon;
	long int        len;
	int             poz;
	int             def;
	char            zap;
	int             flag;
}					p_list;


long int    ft_printf(char *str, ...);



#endif