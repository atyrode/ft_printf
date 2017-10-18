/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:44:13 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/18 15:57:12 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

char    ft_search_val(char c, char *charset)
{
    int i;

   i = 0;
    while (charset[i] != '\0')
    {
        if (charset[i] == c)
            return (charset[i]);
        i++;
    }
    return (0);
}

int   ft_search(char c, char *charset)
{
    int i;

   i = 0;
    while (charset[i] != '\0')
    {
        if (charset[i] == c)
            return (1);
        i++;
    }
    return (0);
}
