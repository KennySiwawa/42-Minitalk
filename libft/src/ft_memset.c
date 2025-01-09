/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:08:15 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:08:17 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_memset - Fill a block of memory with a specific value.
 * @b: The memory area to be filled.
 * @c: The value to be set.
 * @len: The number of bytes to be set to the value.
 *
 * Description: This function fills the first 'len' bytes of the memory area
 * pointed to by 'b' with the constant byte 'c'.
 *
 * Return: A pointer to the memory area 'b'.
 */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*ptr;
	size_t				i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
