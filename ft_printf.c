/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:09:00 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/08/07 15:19:40 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
	return (1);
}

int	ft_print_type(const char *str, va_list args, int *i)
{
	if (str[*i] == 'c')
		return (ft_printchar(args));
	else if (str[*i] == 's')
		return (ft_printstring(args));
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_printnum(args));
	else if (str[*i] == 'u')
		return (ft_printuns(args));
	else if (str[*i] == 'p')
		return (ft_printhex(args, str[*i]) + 2);
	else if (str[*i] == 'x' || str[*i] == 'X')
		return (ft_printhex(args, str[*i]));
	else
	{
		write(1, "%", 1);
		if (str[*i] != '%')
			ft_putchar_fd(str[*i], 1);
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			j += ft_print_type(str, args, &i);
		}
		else
			j += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (j);
}
