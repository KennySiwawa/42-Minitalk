/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:02:07 by kchikwam          #+#    #+#             */
/*   Updated: 2024/12/30 22:26:39 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// static void	sig_handler(int sig, siginfo_t *info, void *context)
// {
// 	static int	client_pid =;
// 	static int	bit;
// 	static int	c;

// 	(void)context;
// 	if (info->si_pid != client_pid)
// 	{
// 		c = 0;
// 		bit = 0;
// 		client_pid = info->si_pid;
// 	}
// 	c <<= 1;
// 	c = c | (sig == SIGUSR2);
// 	bit ++;
// 	if (bit == 8)
// 	{
// 		ft_printf("%c", c);
// 		c = 0;
// 		bit = 0;
// 	}
// }
static void sig_handler(int sig, siginfo_t *info, void *context)
{
	static int client_pid = 0;
	static int bit = 0;
	static unsigned char c = 0;

	(void)context;

	// Check if the client PID has changed (new message)
	if (info->si_pid != client_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		bit = 0;
	}

	// Shift the character and add the new bit
	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;

	bit++;

	// If 8 bits are received, print the character
	if (bit == 8)
	{
		if (c == 0) // End of string (null terminator)
		{
			ft_printf("\n"); // Print a new line for better formatting
		}
		else
		{
			ft_printf("%c", c);
		}
		c = 0;
		bit = 0;
	}
}



int	main(void)
{
	int	pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("====> welcome to Kenny's server, ");
	ft_printf("my process ID is: [ %d ]\n", pid);
	
	action.sa_sigaction = &sig_handler;
	action.sa_flags = SA_SIGINFO;

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	
	if (sigaction(SIGUSR1, &action, NULL) == -1 || sigaction(SIGUSR2, &action, NULL) == -1)
	{
		perror("sigaction");
		return (EXIT_FAILURE);
	}

	while (1)
		pause();

	return (EXIT_SUCCESS);
}