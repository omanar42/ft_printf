/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 03:23:26 by omanar            #+#    #+#             */
/*   Updated: 2021/11/30 17:53:26 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunb(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10 + '0'));
	return (count);
}
