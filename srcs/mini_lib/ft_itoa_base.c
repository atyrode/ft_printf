/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:05:13 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/22 03:57:10 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

char	*ft_itoa_base(intmax_t value, int base)
{
	unsigned int	i;
	int				size;
	char			*ret;

	//value = (base != 10 && value < 0) ? -value : value;
	i = (base == 10 && value < 0) ? -value : value;
	size = 1 + (base == 10 && value < 0);
	while ((i /= base))
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = (base == 10 && value < 0) ? -value : value;
	ret[--size] = "0123456789ABCDEF"[i % base];
	while ((i /= base))
		ret[--size] = "0123456789ABCDEF"[i % base];
	if ((base == 10) && value < 0)
		ret[--size] = '-';
	return (ret);
}
