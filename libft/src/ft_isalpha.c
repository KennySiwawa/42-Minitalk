/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:06:56 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:06:59 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_isalpha - Check if a character is alphabetic.
 * @c: The character to be checked.
 *
 * Description: This function checks if the character 'c' is an alphabetic
 * letter. An alphabetic letter is defined as either an uppercase letter
 * (A-Z) or a lowercase letter (a-z).
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
