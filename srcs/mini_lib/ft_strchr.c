/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:05:13 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/17 18:53:14 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

char	*ft_strchr(char *str, int value)
{
	int		i;
	char	*p;

	i = 0;
	if (value == '\0')
	{
		while (str[i] != value)
			i++;
		if (str[i] == value)
		{
			p = &str[i];
			return (p);
		}
		return (NULL);
	}
	while (str[i] != value && value != '\0')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	p = &str[i];
	return (p);
}
