/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:09:57 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:09:59 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_strlen - Calculate the length of a string.
 * @str: The string to calculate the length of.
 *
 * Description: This function takes a string 'str' and returns its
 * length, not including the terminating null byte ('\0'). The function
 * iterates through the string until it encounters the null byte.
 *
 * Return: The length of the string.
 */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/**int main()
{
    char *str = "Hello, world!";
    size_t len = ft_strlen(str);
    printf("Length of '%s' is %zu\n", str, len);
    return 0;
}*/