/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:03:44 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:03:46 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(t_print *print)
{
	char	c;

	c = va_arg(print->args, int);
	if (print->width && !(print->dash))
		ft_right_align(print, 1);
	print->length += write(1, &c, 1);
	if (print->width && print->dash)
		ft_left_align(print, 1);
	ft_init_print(print);
}
