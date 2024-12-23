/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:17:59 by kchikwam          #+#    #+#             */
/*   Updated: 2024/12/23 12:02:52 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf/ft_printf.h"
// #include "ft_printf/libft/libft.h"
// #include <signal.h>
// #include <unistd.h>

// typedef struct s_msg
// {
// 	char	c;
// 	int		i;
// }	t_msg;

// t_msg g_msg = {0, 0};

// void	bit_handler(int bit)
// {
// 	g_msg.c += ((bit & 1) << g_msg.i);
// 	g_msg.i++;
// 	if (g_msg.i == 7)
// 	{
// 		ft_printf("%c", g_msg.c);
// 		if (!g_msg.c)
// 			ft_printf("\n");
// 		g_msg.c = 0;
// 		g_msg.i = 0;
// 	}
// }

// int	main(void)
// {
// 	ft_printf("Welcome To Pasquale's Server!\n");
// 	ft_printf("My Server PID is: %d\n", getpid());
// 	while (1)
// 	{
// 		signal(SIGUSR2, bit_handler);
// 		signal(SIGUSR1, bit_handler);
// 		pause();
// 	}
// 	return (0);
// }

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <signal.h>
#include <unistd.h>

typedef struct s_msg
{
    char	c;
    int		i;
}	t_msg;

t_msg g_msg = {0, 0};
// volatile sig_atomic_t g_running = 1;

void	bit_handler(int bit)
{
    g_msg.c += ((bit & 1) << g_msg.i);
    g_msg.i++;
    if (g_msg.i == 8) // changed from 7 to 8
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