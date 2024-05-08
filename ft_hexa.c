/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlos- <scarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:23:43 by scarlos-          #+#    #+#             */
/*   Updated: 2024/05/03 11:23:43 by scarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexadecimal(size_t n, int *len, char c)
{
	if (n >= 16)
		print_hexadecimal(n / 16, len, c);
	if (c == 'X')
		print_char("0123456789ABCDEF"[n % 16], len);
	if (c == 'x')
		print_char("0123456789abcdef"[n % 16], len);
}

void	print_hex_ptr(void *ptr, int *len)
{
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	print_char('0', len);
	print_char('x', len);
	print_hexadecimal((size_t)ptr, len, 'x');
}
// pointers começa com 0x, para indicar que o número é representado em hexa
