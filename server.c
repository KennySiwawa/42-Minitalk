/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:02:07 by kchikwam          #+#    #+#             */
/*   Updated: 2024/12/27 13:34:53 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	client_pid;
	static int	bit;
	static int	c;

	(void)context;
	if ((*info).si_pid != client_pid)
	{
		c = 0;
		bit = 0;
		client_pid = (*info).si_pid;
	}
	c <<= 1;
	c = c | (sig == SIGUSR2);
	bit ++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	action.sa_sigaction = &sig_handler;
	ft_printf("====> welcome to Kenny's server, my process ID is: [ %d ]\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	exit(EXIT_FAILURE);
}