/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:17:59 by kchikwam          #+#    #+#             */
/*   Updated: 2024/12/23 14:09:44 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h> // Include the standard I/O library for debugging

typedef struct s_msg
{
    char	c;
    int		i;
}	t_msg;

t_msg g_msg = {0, 0};
volatile sig_atomic_t g_running = 1;

void	bit_handler(int bit)
{
    printf("Signal received: %d\n", bit); // Debug print
    g_msg.c += ((bit & 1) << g_msg.i);
    g_msg.i++;
    printf("Current char: %c, bit position: %d\n", g_msg.c, g_msg.i); // Debug print
    if (g_msg.i == 8) //Adjust to 8 bits for a full character
    {
        ft_printf("%c", g_msg.c);
        if (!g_msg.c)
            ft_printf("\n");
        g_msg.c = 0;
        g_msg.i = 0;
    }
}

void	sigint_handler(int signum)
{
    (void)signum;
    printf("SIGINT received. Shutting down...\n"); // Debug print
    g_running = 0;
}

int	main(void)
{
    ft_printf("Welcome To Pasquale's Server!\n");
    ft_printf("My Server PID is: %d\n", getpid());

    signal(SIGUSR2, bit_handler);
    signal(SIGUSR1, bit_handler);
    signal(SIGINT, sigint_handler);

    while (g_running)
    {
        pause();
    }

    ft_printf("Server shutting down...\n");
    return (0);
}