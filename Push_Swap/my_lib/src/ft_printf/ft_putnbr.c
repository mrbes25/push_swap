/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:47:27 by bschmid           #+#    #+#             */
/*   Updated: 2023/11/06 10:47:34 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int		i;
	int		count;
	char	buffer[64];

	i = 0;
	count = 0;
	if (n == 0)
		count += write(1, "0", 1);
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
	{
		count += ft_putchar(buffer[i]);
	}
	return (count);
}
