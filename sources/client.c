/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:22:17 by flim              #+#    #+#             */
/*   Updated: 2022/03/19 13:24:23 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_str_len;

static void	handle_signal(int sig)
{
	static int	count_str;

	if (sig == SIGUSR1)
		count_str++;
	if (count_str == g_str_len)
	{
		ft_printf(BRIGHT_GREEN "%d byte/s received!" RESET, count_str);
		exit(EXIT_SUCCESS);
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
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	pid = ft_atoi(argv[1]);
	g_str_len = ft_strlen(argv[2]);
	ft_str_to_binary(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
