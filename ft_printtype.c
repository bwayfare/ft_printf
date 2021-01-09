#include "ft_printf.h"

int		ft_printtype(char *str, va_list *arg, t_list *list)
{
	if (*str == 's')
		return (ft_printstring(list, va_arg(*arg, char *)));
	if (*str == 'c')
		return (ft_printchar(list, *arg));
	if (*str == 'd' || *str == 'i')
		return (ft_printint(ft_itoa(va_arg(*arg, int)), list, 0, 0));
	if (*str == 'u')
		return (ft_uintcheck(va_arg(*arg, unsigned int), list));
	if (*str == 'X')
		return (ft_hexproc(list, va_arg(*arg, long int), 1));
	if (*str == 'x')
		return (ft_hexproc(list, va_arg(*arg, long int), 0));
	if (*str == 'p')
		return (ft_hexproc(list, va_arg(*arg, unsigned long), 2));
}