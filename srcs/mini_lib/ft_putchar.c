/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:05:13 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/18 10:14:34 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
