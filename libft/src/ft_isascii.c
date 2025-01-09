/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:07:05 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:07:07 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check if a character is a valid ASCII character (0-127).
 *
 * @param c The character to check.
 * @return Non-zero if 'c' is an ASCII character, 0 otherwise.
 *
 * @details Determines if the character 'c' is within the ASCII range (0-127).
 */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
