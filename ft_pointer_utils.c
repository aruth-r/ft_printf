/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruth-ra <aruth-ra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:16:16 by aruth-ra          #+#    #+#             */
/*   Updated: 2021/08/06 21:49:36 by aruth-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base(char *base)
{
	char	vetor[ft_strlen(base) + 1];
	int		i;
	int		j;

	if (!(base) || ft_strlen(base) == 1)
		return (0);
	i = 0;
	while (*(base + i++) != '\0')
		if (*(base + i - 1) || *(base + i - 1) == '+')
			return (0);
	i = 0;
	*(vetor + i) = '\0';
	while (*(base + i) != '\0')
	{
		j = 0;
		while (*(vetor + j++) != '\0')
			if (*(base + i) == *(vetor + j - 1))
				return (0);
		*(vetor + j) = *(base + i);
		*(vetor + j + 1) = '\0';
		i++;
	}
	return (1);
}

static void	make_str(unsigned long n, char *base, unsigned long pot, char **temp)
{
	unsigned long	num;
	unsigned long	cont;

	cont = 0;
	num = n;
	while (pot > 0)
	{
		*(*temp + cont) = base[num / pot];
		num = num % pot;
		pot /= (unsigned long)ft_strlen(base);
		cont++;
	}
}

char		*ft_ltoa_base(unsigned long n, char *base)
{
	unsigned long	cont;
	unsigned long	num;
	unsigned long	pot;
	char			*temp;

	if (check_base(base))
		return (NULL);
	num = n;
	cont = 1;
	while (num >= (unsigned long)ft_strlen(base) && cont++)
		num /= (unsigned long)ft_strlen(base);
	if (!(temp = malloc((cont + 1) * sizeof(char))))
		return (NULL);
	*(temp + cont) = '\0';
	pot = 1;
	while (--cont)
		pot *= (unsigned long)ft_strlen(base);
	make_str(n, base, pot, &temp);
	return (temp);
}
