/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:09:00 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/08/06 22:13:49 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++ != 0)
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != 0)
	{
		while (s[i] != 0)
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

static size_t	ft_nbrlen(int n)
{
	size_t	i;
	int		nb;

	i = 0;
	if (n < 0)
	{
		i++;
		nb = n * -1;
	}
	else
		nb = n;
	while (nb / 10)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

static int	ft_ispos(int n)
{
	if (n < 0)
		return (0);
	return (1);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*itoa;
	size_t			i;

	itoa = (char *)malloc(ft_nbrlen(n) + 1);
	if (itoa == 0)
		return (0);
	i = 0;
	if (n < 0)
	{
		itoa[i] = '-';
		i++;
		nb = -n;
	}
	else
		nb = n;
	itoa[ft_nbrlen(n)] = '\0';
	while (i < ft_nbrlen(n))
	{
		itoa[ft_nbrlen(n) - i - ft_ispos(n)] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	return (itoa);
}
