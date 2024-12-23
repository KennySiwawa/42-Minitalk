
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:17:19 by kchikwam          #+#    #+#             */
/*   Updated: 2024/12/23 12:01:06 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h> // Include the standard I/O library for debugging

void send_bit(int pid, char *str, size_t len)
{
    int		shift;
    size_t	i;

    i = 0;
    while (i <= len)
    {
        shift = 0;
        while (shift < 8) //changed from 7 to 8
        {
            if ((str[i] >> shift) & 1)
            {
                if (kill(pid, SIGUSR2) == -1)
                {
                    ft_printf("Error sending SIGUSR2\n");
                    return;
                }
				printf("Sending SIGUSR2 for bit 1\n"); // Debug print
            }
            else
            {
                if (kill(pid, SIGUSR1) == -1)
                {
                    ft_printf("Error sending SIGUSR1\n");
                    return;
                }
				printf("Sending SIGUSR1 for bit 0\n"); // Debug print
            }
            shift++;
            usleep(300);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int		pid;
    char	*str;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        str = argv[2];
        send_bit(pid, str, ft_strlen(str));
        // Send the null terminator
        send_bit(pid, "\0", 1);
    }
    else
    {
        ft_printf("\nUsage: %s <PID> <message>\n", argv[0]);
    }
    return 0;
}
