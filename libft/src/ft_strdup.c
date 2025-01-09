/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:09:18 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:09:20 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_strdup - Duplicate a string.
 * @s1: The string to be duplicated.
 *
 * Description: This function takes a string 's1' and allocates memory
 * to create a copy of it. The copy is created and a pointer to it is
 * returned. The memory for the new string is dynamically allocated
 * and should be freed by the caller. If the allocation fails, the
 * function returns NULL.
 *
 * Return: A pointer to the duplicated string, or NULL if memory
 * allocation fails.
 */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int			len;
	char		*result;

	len = ft_strlen(s);
	result = ((char *)malloc(sizeof(char) * (len + 1)));
	if (result == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		result[len] = s[len];
		len++;
	}
	result[len] = '\0';
	return (result);
}
