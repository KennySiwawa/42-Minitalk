/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:08:50 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:08:51 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_putstr_fd - Output a string to a file descriptor.
 * @s: The string to be output.
 * @fd: The file descriptor on which to write.
 *
 * Description: This function writes the string 's' to the given file
 * descriptor 'fd'. It does not add a newline character.
 *
 * Return: None.
 */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

/**int main()
{
	ft_putstr_fd("Hello World", 1);
}*/