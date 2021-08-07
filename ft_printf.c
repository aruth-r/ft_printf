/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:09:00 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/08/04 23:22:41 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
	return (1);
}

int	ft_print_type(const char *str, va_list args, int *i, int *k)
{
	*k = *k + 1;
	if (str[*i] == 'c')
		return (ft_printchar(args, *k));
	else if (str[*i] == 's')
		return (ft_printstring(args, *k));
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_printnum(args, *k));
	else if (str[*i] == 'u')
		return (ft_printuns(args, *k));
	else if (str[*i] == 'p')
		return (ft_printhex(args, str[*i], *k) + 2);
	else if (str[*i] == 'x' || str[*i] == 'X')
		return (ft_printhex(args, str[*i], *k));
	else
	{
		write(1, "%", 1);
		if (str[*i] != '%')
			ft_putchar_fd(str[*i], 1);
		*k = *k - 1;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;
	int 	k;

	i = 0;
	j = 0;
	k = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			{
				i++;
				j += ft_print_type(str, args, &i, &k);
			}
		else
			j += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (j);
}
