/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 04:35:14 by omanar            #+#    #+#             */
/*   Updated: 2021/11/30 18:32:50 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexp(unsigned long long c, char h)
{
	char	*hex;
	int		count;

	count = 0;
	if (h == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (c >= 16)
		count += ft_puthexp((c / 16), h);
	count += ft_putchar(hex[c % 16]);
	return (count);
}

int	ft_putpnt(unsigned long long c)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_puthexp(c, 'x');
	return (count);
}
