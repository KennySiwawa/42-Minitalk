/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:41:33 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 14:41:48 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void sig_handler(int sig, siginfo_t *info, void *context)
{
	static int client_pid = 0;
	static int bit = 0;
	static unsigned char c = 0;

	(void)context;

	if (info->si_pid != client_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		bit = 0;
	}

	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;

	bit++;
	if (bit == 8)
	{
		if (c == 0)
		{
			printf("\n");
		}
		else
		{
			putchar(c);
			fflush(stdout);
		}
		c = 0;
		bit = 0;
	}

	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction action;

	printf("====> Server PID: %d\n", getpid());

	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);

	if (sigaction(SIGUSR1, &action, NULL) == -1 || sigaction(SIGUSR2, &action, NULL) == -1)
	{
		perror("[ ERROR ]: sigaction failed");
		return (EXIT_FAILURE);
	}

	while (1)
		pause();

	return (EXIT_SUCCESS);
}
