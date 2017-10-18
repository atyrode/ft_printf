/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:06:11 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/18 22:06:21 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

char	*ft_strdup(char *str)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(str);
	dup = (char*)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	dup[len] = '\0';
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
