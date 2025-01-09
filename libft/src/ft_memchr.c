/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:07:37 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:07:39 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_memchr - Locate a byte in memory.
 * @s: The memory area to be searched.
 * @c: The byte to be located.
 * @n: The number of bytes to be searched.
 *
 * Description: This function searches the first 'n' bytes of the memory area
 * pointed to by 's' for the first occurrence of the byte 'c'. The search stops
 * when the byte is found or 'n' bytes have been searched.
 *
 * Return: A pointer to the matching byte or NULL if the byte is not found.
 */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t						i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/**int main()
{
	const char str[] = "jkashd jas daksjd alksjd aksjd";
	char c = 'd';
	
	char *result = ft_memchr(str, c, 8);
	char *result1 = memchr(str, c, 8);
	printf("My ft is %p\n", result);
	printf("The og is %p\n", result1);
}*/