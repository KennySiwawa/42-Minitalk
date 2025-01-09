/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:40:48 by kchikwam          #+#    #+#             */
/*   Updated: 2025/01/09 14:40:51 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static volatile sig_atomic_t g_ack_received = 0;

void sig_ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

static int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}

static void ft_send_bit(int pid, int bit)
{
	g_ack_received = 0;
	if (kill(pid, bit ? SIGUSR2 : SIGUSR1) == -1)
	{
		perror("[ ERROR ]: Invalid PID");
		exit(EXIT_FAILURE);
	}
	while (!g_ack_received)
		usleep(100);
}

static void ft_send_char(int pid, char c)
{
	int	bit;

	for (bit = 7; bit >= 0; bit--)
		ft_send_bit(pid, (c >> bit) & 1);
}

static void ft_send_message(int pid, char *str)
{
	while (*str)
		ft_send_char(pid, *str++);
	ft_send_char(pid, '\0'); // Send null terminator
}

int main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
	{
		fprintf(stderr, "[ USAGE ]: %s [ PID ] [ MESSAGE ]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, sig_ack_handler);
	pid = ft_atoi(argv[1]);
	ft_send_message(pid, argv[2]);
	return (0);
}
