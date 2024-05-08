/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlos- <scarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:24:09 by scarlos-          #+#    #+#             */
/*   Updated: 2024/05/03 11:24:09 by scarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr(int n, int *len)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		print_char('-', len);
		nb *= -1;
	}
	if (nb > 9)
	{
		print_nbr(nb / 10, len);
	}
	print_char(nb % 10 + '0', len);
}

void	print_unsigned_nbr(unsigned int n, int *len)
{
	if (n > 9)
	{
		print_unsigned_nbr(n / 10, len);
	}
	print_char(n % 10 + '0', len);
}
