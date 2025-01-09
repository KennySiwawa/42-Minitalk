/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:07:22 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:07:24 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check if a character is a printable ASCII character (32-126).
 *
 * @param c The character to check.
 * @return Non-zero if 'c' is a printable ASCII character, 0 otherwise.
 *
 * @details Determines if the character 'c' is a printable ASCII character,
 * which includes characters from space (32) to tilde (126) inclusive.
 */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
