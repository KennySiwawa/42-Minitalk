/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:00:44 by kchikwam          #+#    #+#             */
/*   Updated: 2024/12/23 19:58:40 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

static int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str ++;
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

static void	ft_sender_bin(int pid, char c)
{
	int	bit;
	int	n;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
			n = kill(pid, SIGUSR2);
		else
			n = kill(pid, SIGUSR1);
		if (n == -1)
		{
			ft_printf("[ PID ] : bad process ID");
			exit(EXIT_FAILURE);
		}
		c = c << 1;
		bit ++;
		usleep(700);
	}
}

static void	ft_sender_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_sender_bin(pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("[ INVALID ARGUMENTS ! ] : [ PID ] [ STRING ] \n");
		exit(EXIT_FAILURE);
	}
	while (argv[1][i])
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			ft_printf("Invalid PID : [ PID must contain only numbers ! ]");
			exit(EXIT_FAILURE);
		}
		i ++;
	}
	pid = ft_atoi(argv[1]);
	ft_sender_char(pid, argv[2]);
	return (0);
}