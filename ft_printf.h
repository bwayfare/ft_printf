/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:50:16 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/09 19:38:40 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_print_list
{
	int				width;
	int				pon;
	int				len;
	int				poz;
	int				def;
	int				sharp;
	char			zap;
	int				flag;
}					t_list;

int					ft_printf(char *str, ...);
int					ft_singltype(char ch, char *set);
int					ft_goch(char *str, char *ch);
int					ft_printstring(t_list *list, char *str);
int					ft_checkflag(char ch, t_list *list);
int					ft_checkwidth(va_list *arg, char *str, t_list *list);
int					ft_checkpon(va_list *arg, char *str,
					t_list *list, char *head);
int					ft_printchar(t_list *list, va_list arg);
int					ft_printint(char *tstr, t_list *list, int i, int j);
void				ft_intdef(char *tstr, t_list *list, int *i, int *j);
void				ft_intpozelse(char *tstr, t_list *list, int *i, int *j);
void				ft_intpoz(char *tstr, t_list *list, int *i, int *j);
void				ft_intzap(char *tstr, t_list *list, int *i, int *j);
void				ft_intzappoz(char *tstr, t_list *list, int *i, int *j);
char				*ft_longtoa(long int number);
int					ft_uintcheck(long int temp, t_list *list);
int					ft_hexproc(t_list *list, long int temp, int flag);
void				ft_hexwidthpon(t_list *list, int len);
void				ft_hexprint(t_list *list, char *str);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t num, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_itoa(int number);
int					ft_printtype(char *str, va_list *arg, t_list *list);

#endif
