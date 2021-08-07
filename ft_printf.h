/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:58:46 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/08/06 21:50:49 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//#include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printchar(va_list args, int k);
int	ft_printstring(va_list args, int k);
int	ft_printnum(va_list args, int k);
int	ft_printuns(va_list args, int k);
int ft_printhex(va_list args, char str, int k);
int	ft_printpointer(va_list args, int k);
int	ft_print_type(const char *str, va_list args, int *i, int *k);
int	ft_printf(const char *str, ...);

size_t	ft_strlen(const char *s);
int	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_ltoa_base(unsigned long n, char *base);
char	*ft_utoa_base(unsigned int n, char *base);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa(int n);

#endif