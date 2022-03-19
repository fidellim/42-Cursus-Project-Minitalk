/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:22:17 by flim              #+#    #+#             */
/*   Updated: 2022/03/19 15:14:04 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	are_args_valid(int pid, char *str)
{
	if (pid < MIN_PID || pid > MAX_PID)
	{
		ft_printf(BRIGHT_RED "ERROR: PID range: %d and %d\n"
			RESET, MIN_PID, MAX_PID);
		exit(EXIT_FAILURE);
	}
	if (!*str)
	{
		ft_printf(BRIGHT_RED "ERROR: string is empty"
			RESET);
		exit(EXIT_FAILURE);
	}
}

static void	ft_str_to_binary(int pid, char *str)
{
	int	i;
	int	b;

	i = 0;
	while (str[i])
	{
		b = 7;
		while (b >= 0)
		{
			if ((str[i] & (1 << b)) > 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			b--;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_printf(BRIGHT_RED
			"%s MUST HAVE 3 ARGUMENTS!\n" RESET, argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	are_args_valid(pid, argv[2]);
	ft_str_to_binary(pid, argv[2]);
	return (0);
}
