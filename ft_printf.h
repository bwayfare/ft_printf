#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct		print_list
{
	int        		width;
	int        		pon;
	int        		len;
	int             poz;
	int             def;
	int 			sharp;
	char            zap;
	int             flag;
}					p_list;


int					ft_printf(char *str, ...);
int 				ft_singltype(char ch, char *set);
int					ft_goch(char *str, char *ch);
int					ft_printstring(p_list *list, char *str);
int 				ft_checkflag(char ch, p_list *list);
int					ft_checkwidth(va_list *arg, char *str, p_list *list);
int					ft_checkpon(va_list *arg, char *str, p_list *list, char *head);
int					ft_printchar(p_list *list, va_list arg);
int					ft_printint(char *tstr, p_list *list, int i, int j);
void 				ft_intdef(char *tstr, int len, p_list *list, int *i, int *j);
void 				ft_intpozelse(char *tstr, int len, p_list *list, int *i, int *j);
void 				ft_intpoz(char *tstr, int len, p_list *list, int *i, int *j);
void 				ft_intzap(char *tstr, int len, p_list *list, int *i, int *j);
void 				ft_intzappoz(char *tstr, int len, p_list *list, int *i, int *j);
char				*ft_longtoa(long int number);
int 				ft_uintcheck(long int temp, p_list *list);
int					ft_hexproc(p_list *list, long int temp, int flag);
void 				ft_hexwidthpon(p_list *list, int len);
void 				ft_hexprint(p_list *list, char *str);

#endif