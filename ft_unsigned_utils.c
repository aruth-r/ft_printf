/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:16:16 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/08/08 13:59:00 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	make_str(unsigned int n, char *base, unsigned int pot, char **temp)
{
	unsigned int	num;
	unsigned int	cont;

	cont = 0;
	num = n;
	while (pot > 0)
	{
		*(*temp + cont) = base[num / pot];
		num = num % pot;
		pot /= (unsigned int)ft_strlen(base);
		cont++;
	}
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	unsigned int	cont;
	unsigned int	num;
	unsigned int	pot;
	char			*temp;

	num = n;
	cont = 1;
	while (num >= (unsigned int)ft_strlen(base) && cont++)
		num /= (unsigned int)ft_strlen(base);
	temp = malloc((cont + 1) * sizeof(char));
	if (!temp)
		return (0);
	*(temp + cont) = '\0';
	pot = 1;
	while (--cont)
		pot *= (unsigned int)ft_strlen(base);
	make_str(n, base, pot, &temp);
	return (temp);
}

static size_t	ft_nbrlen(int nb)
{
	size_t	i;

	i = 0;
	while (nb / 10)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*itoa;
	size_t			i;
	int				nb;

	nb = n;
	itoa = (char *)malloc(ft_nbrlen(n) + 1);
	i = 0;
	itoa[ft_nbrlen(n)] = '\0';
	while (i < ft_nbrlen(n))
	{
		itoa[ft_nbrlen(n)] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	return (itoa);
}
