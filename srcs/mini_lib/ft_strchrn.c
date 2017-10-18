/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:05:13 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/18 09:05:26 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

int			ft_strchrn(char *format, char c)
{
	int		i;
	int		count;

	i = -1;
	while(format[++i])
		if (format[i] == c)
			count++;
	return (count);
}
