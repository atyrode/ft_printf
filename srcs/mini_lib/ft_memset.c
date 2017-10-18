/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:03:29 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/18 22:02:15 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned long int	i;
	char				*str;

	str = ptr;
	i = 0;
	while (i < num)
	{
		str[i] = value;
		i++;
	}
	return (ptr);
}
