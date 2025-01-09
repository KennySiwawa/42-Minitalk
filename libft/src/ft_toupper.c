/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:11:09 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:11:11 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_toupper - Convert a lowercase letter to an uppercase letter.
 * @c: The character to be converted.
 *
 * Description: This function converts a lowercase letter to the
 * corresponding uppercase letter. If the character is not a lowercase
 * letter, it is returned unchanged.
 *
 * Return: The uppercase equivalent of the character if it is a lowercase
 * letter, otherwise the character itself.
 */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
