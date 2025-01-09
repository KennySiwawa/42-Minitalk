/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:08:23 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 20:08:25 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_putchar_fd - Outputs the character 'c' to the given file descriptor.
 * @c: The character to output.
 * @fd: The file descriptor on which to write.
 *
 * Description: This function writes the character 'c' to the file descriptor
 * specified by 'fd'. If writing fails, the function does not perform any
 * error handling; it is the caller's responsibility to handle errors
 * appropriately.
 *
 * Return: This function does not return a value.
 */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/**int main()
{
	ft_putchar_fd('H', 1);
}**/