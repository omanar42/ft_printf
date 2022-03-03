/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:09:32 by omanar            #+#    #+#             */
/*   Updated: 2021/11/30 21:35:37 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c)
{
	int		i;
	char	*s;

	i = 0;
	s = "cspdiuxX%";
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_processing(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		count += ft_putpnt(va_arg(ap, unsigned long long));
	else if (c == 'i' || c == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		count += ft_putunb(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(ap, int), c);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_check(s[i + 1]))
		{
			count += ft_processing(args, s[i + 1]);
			i++;
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
