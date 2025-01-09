/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:09:08 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:09:10 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_strchr - Locate the first occurrence of a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Description: This function searches for the first occurrence of the
 * character 'c' in the string 's'. The terminating null byte is considered
 * part of the string, so if 'c' is '\0', the function locates the
 * terminating '\0'.
 *
 * Return: A pointer to the first occurrence of the character 'c' in the
 * string 's', or NULL if the character is not found.
 */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

/**int main()
{
    char *str = "Hello, world!";
    char *ptr = ft_strchr(str, 'w');
    if (ptr)
        printf("Character 'w' found at position: %ld\n", ptr - str);
    else
        printf("Character 'w' not found\n");
    return 0;
}*/