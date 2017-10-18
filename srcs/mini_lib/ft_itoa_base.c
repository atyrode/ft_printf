/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 20:05:13 by atyrode           #+#    #+#             */
/*   Updated: 2017/10/18 18:19:21 by atyrode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/ft_printf.h"

/*uintmax_t		pf_ft_sign(t_flag *f, intmax_t nbr)
{
	f->sign = '+';
	if (nbr < 0)
	{
		f->sign = '-';
		nbr = -nbr;
	}
	return ((uintmax_t)nbr);
}*/

char			*ft_itoa_base(uintmax_t nbr, int base, int low_up)
{
	static char	convert[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F'};
	intmax_t	i;
	uintmax_t	n;
	int			converted_nbr[64];
	char		*result;

	if (nbr == 0)
		return ("0");
	i = 0;
	n = (intmax_t)nbr;
	while (n > 0)
	{
		converted_nbr[i++] = n % base;
		n /= base;
	}
	result = (char*)malloc(sizeof(char) * --i);
	result[i + 1] = '\0';
	while (i >= 0)
		result[n++] = (low_up == 1) ? convert[converted_nbr[i--]] :
		ft_tolower(convert[converted_nbr[i--]]);
	return (result);
}
