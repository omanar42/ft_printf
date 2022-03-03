/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omanar <omanar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 03:41:40 by omanar            #+#    #+#             */
/*   Updated: 2021/11/30 17:58:33 by omanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int c, char h)
{
	char	*hex;
	int		count;

	count = 0;
	if (h == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (c >= 16)
		count += ft_puthex((c / 16), h);
	count += ft_putchar(hex[c % 16]);
	return (count);
}
