/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:06:47 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:06:50 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check if a character is alphanumeric (a-z, A-Z, 0-9).
 *
 * @param c The character to check.
 * @return Non-zero if 'c' is alphanumeric, 0 otherwise.
 *
 * @details Determines if the character 'c' is alphanumeric
 * (a-z, A-Z, 0-9) according to the ASCII table.
 */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
