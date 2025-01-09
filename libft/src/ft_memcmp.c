/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:07:45 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:07:48 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_memcmp - Compare two blocks of memory.
 * @s1: The first memory block to be compared.
 * @s2: The second memory block to be compared.
 * @n: The number of bytes to be compared.
 *
 * Description: This function compares the first 'n' bytes of the memory
 * areas 's1' and 's2'. The comparison is done byte by byte.
 *
 * Return: An integer less than, equal to, or greater than zero if the first
 * 'n' bytes of 's1' is found, respectively, to be less than, to match, or
 * be greater than the first 'n' bytes of 's2'.
 */

#include "libft.h"

int	ft_memcmp( const void *str1, const void *str2, size_t num)
{
	const unsigned char			*ptr1;
	const unsigned char			*ptr2;
	size_t						i;

	i = 0;
	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	if (num == 0)
		return (0);
	while (i < num)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
