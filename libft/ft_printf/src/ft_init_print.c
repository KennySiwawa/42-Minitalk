/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:04:32 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:04:34 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_print(t_print *print)
{
	print->dash = 0;
	print->zero = 0;
	print->point = 0;
	print->plus = 0;
	print->space = 0;
	print->hash = 0;
	print->width = 0;
	print->precision = 0;
	print->baselen = 0;
	print->specifier = 0;
	print->base = NULL;
	print->base_n = 0;
}
