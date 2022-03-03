/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:02:17 by omanar            #+#    #+#             */
/*   Updated: 2021/11/30 17:51:11 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			count += ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
			count += ft_putnbr(n / 10);
		count += ft_putchar((n % 10 + '0'));
	}
	return (count);
}
