/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:17:28 by flim              #+#    #+#             */
/*   Updated: 2022/03/19 13:32:03 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_binary_to_str(int sig, siginfo_t *info, void *ptr)
{
	static char	c;
	static char	num_of_bits;

	(void) ptr;
	if (sig == SIGUSR1)
		c |= 1;
	if (sig == SIGUSR2)
		c |= 0;
	num_of_bits++;
	if (num_of_bits == 8)
	{
		ft_printf("%c", c);
		num_of_bits = 0;
		c = 0;
	}
	c <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
	{
		ft_printf(BRIGHT_RED
			"%s MUST HAVE 1 ARGUMENT!\n" RESET, argv[0]);
		exit(EXIT_FAILURE);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_binary_to_str;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf(BRIGHT_GREEN "Server PID: %u\n" RESET, getpid());
	while (1)
		pause();
	return (0);
}
