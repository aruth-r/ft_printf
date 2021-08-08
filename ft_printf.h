/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:58:46 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/08/08 14:00:20 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printchar(va_list args);
int		ft_printstring(va_list args);
int		ft_printnum(va_list args);
int		ft_printuns(va_list args);
int		ft_printhex(va_list args, char str);
int		ft_printpointer(va_list args);
int		ft_print_type(const char *str, va_list args, int *i);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_ltoa_base(unsigned long n, char *base);
char	*ft_utoa_base(unsigned int n, char *base);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa(int n);

#endif