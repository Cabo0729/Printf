/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlos- <scarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:23:52 by scarlos-          #+#    #+#             */
/*   Updated: 2024/05/03 11:23:52 by scarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	print_str(char *s, int *len)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (s[i])
	{
		print_char(s[i], len);
		i++;
	}
}

static int	ft_conversion(va_list args, int *len, char c)
{
	if (c == 'c')
		print_char(va_arg(args, int), len);
	else if (c == 's')
		print_str(va_arg(args, char *), len);
	else if (c == 'p')
		print_hex_ptr(va_arg(args, void *), len);
	else if (c == 'd' || c == 'i')
		print_nbr(va_arg(args, int), len);
	else if (c == 'u')
		print_unsigned_nbr(va_arg(args, unsigned int), len);
	else if (c == 'x')
		print_hexadecimal(va_arg(args, unsigned int), len, c);
	else if (c == 'X')
		print_hexadecimal(va_arg(args, unsigned int), len, c);
	else if (c == '%')
		print_char('%', len);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (!ft_conversion(args, &len, s[i]))
				i--;
		}
		else
			print_char(s[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	char *str = "42, Lisboa";
	void *ptr = &str;

	ft_printf("My    : %c %c\n", 'A', 'B');
	printf("printf: %c %c\n", 'A', 'B');
	ft_printf("\n");

	int len_printed1 = ft_printf("%c\n", 'A');
	ft_printf("Num chars: %d\n", len_printed1);
	ft_printf("\n");

	ft_printf("My    : %s %s\n", "Hello", "world");
	printf("printf: %s %s\n", "Hello", "world");
	ft_printf("\n");

	int len_printed2 = ft_printf("%s %s\n", "Hello", "world");
	ft_printf("Num chars: %d\n", len_printed2);
	ft_printf("\n");

	ft_printf("My    : %s\n", (char *)NULL);
	printf("printf: %s\n", (char *)NULL);
	ft_printf("\n");

	ft_printf("My    : %p\n", ptr);
	printf("printf: %p\n", ptr);
	ft_printf("My    : %p\n", NULL);
	printf("printf: %p\n", NULL);
	ft_printf("\n");

	ft_printf("My    : %u\n", UINT_MAX);
	printf("printf: %u\n", UINT_MAX);
	ft_printf("\n");

	ft_printf("My    : %d\n", INT_MIN);
	printf("printf: %d\n", INT_MIN);
	ft_printf("\n");

	ft_printf("My    : %d\n", INT_MAX);
	printf("printf: %d\n", INT_MAX);
	ft_printf("\n");

	ft_printf("My    : %i %s\n", 42, "Lisboa");
	printf("printf: %i %s\n", 42, "Lisboa");
	ft_printf("\n");

	ft_printf("My    : %x\n", 124121415);
	printf("printf: %x\n", 124121415);
	ft_printf("\n");

	ft_printf("My    : %X\n", 124121415);
	printf("printf: %X\n", 124121415);
	ft_printf("\n");

	ft_printf("My    : %%100\n");
	printf("printf: %%100\n");
	ft_printf("\n");

	int len_printed3 = ft_printf("%s\n", "%100");
	ft_printf("Num chars: %d\n", len_printed3);

	return (0);
} */
