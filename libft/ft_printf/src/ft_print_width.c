/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:04:41 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:04:44 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_width(t_print *print, const char *str, int pos)
{
	int	res;

	res = 0;
	while (ft_isdigit(str[pos]) && !ft_strchr(".cspdiuoxX%", str[pos]))
	{
		res = res * 10 + str[pos] - '0';
		pos++;
	}
	print->width = res;
	return (--pos);
}

int	ft_get_precision(t_print *print, const char *str, int pos)
{
	int	res;

	res = 0;
	while (ft_isdigit(str[pos]) && !ft_strchr("cspdiuoxX%", str[pos]))
	{
		res = res * 10 + str[pos] - '0';
		pos++;
	}
	print->precision = res;
	return (--pos);
}
