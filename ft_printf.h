/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlos- <scarlos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:39:03 by scarlos-          #+#    #+#             */
/*   Updated: 2024/05/02 15:39:03 by scarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // va_list/arg/start/end
# include <unistd.h> // write
# include <stddef.h> // site_t/NULL
# include <limits.h> // INT_MIN
# include <stdio.h>  // printf

int		ft_printf(const char *s, ...);
void	print_char(char c, int *len);
void	print_str(char *s, int *len);
void	print_nbr(int n, int *len);
void	print_unsigned_nbr(unsigned int n, int *len);
void	print_hex_ptr(void *ptr, int *len);
void	print_hexadecimal(size_t n, int *len, char c);

#endif
