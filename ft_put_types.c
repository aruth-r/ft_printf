/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:09:00 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/08/08 13:58:57 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(va_list args)
{	
	int	arg;

	arg = va_arg(args, int);
	ft_putchar_fd(arg, 1);
	return (1);
}

int	ft_printstring(va_list args)
{
	char	*arg;

	arg = va_arg(args, char *);
	if (arg == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(arg, 1);
	return (ft_strlen(arg));
}

int	ft_printnum(va_list args)
{
	char	*numtostr;
	int		arg;
	int		i;

	arg = va_arg(args, int);
	numtostr = ft_itoa(arg);
	ft_putstr_fd(numtostr, 1);
	i = ft_strlen(numtostr);
	free(numtostr);
	return (i);
}

int	ft_printuns(va_list args)
{
	char			*numtostr;
	unsigned long	arg;
	int				i;

	arg = va_arg(args, unsigned long);
	numtostr = ft_utoa_base(arg, "0123456789");
	ft_putstr_fd(numtostr, 1);
	i = ft_strlen(numtostr);
	free(numtostr);
	return (i);
}

int	ft_printhex(va_list args, char str)
{
	char			*hextostr;
	unsigned long	arg;
	int				i;

	arg = va_arg(args, unsigned long);
	if (str == 'x')
		hextostr = ft_utoa_base(arg, "0123456789abcdef");
	if (str == 'p')
	{
		write(1, "0x", 2);
		hextostr = ft_ltoa_base(arg, "0123456789abcdef");
	}
	if (str == 'X')
		hextostr = ft_utoa_base(arg, "0123456789ABCDEF");
	ft_putstr_fd(hextostr, 1);
	i = ft_strlen(hextostr);
	free(hextostr);
	return (i);
}
