/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:17:28 by flim              #+#    #+#             */
/*   Updated: 2022/03/07 11:08:51 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minitalk.h>

// void	handle_int(int id)
// {	
// }

// void	handler(int sig, siginfo_t *info, void *ucontext)
// {
// 	printf(BRIGHT_GREEN "THIS HAS BEEN SIGNALLED %d\n", getpid());
// }

int	main(void)
{
	// struct sigaction	sa;

	// sa.sa_sigaction = ft_confirm;
	// sa.sa_flags = SA_SIGINFO;
	//sigaction(SIGINT, &sa, NULL);
	// sigaction(SIGUSR1, &sa, 0);
	// sigaction(SIGUSR2, &sa, 0);
	signal(SIGUSR1, ft_confirm);
	signal(SIGUSR2, ft_confirm);
	printf("Process ID: %d\n", getpid());
	while (1)
		;
	return (0);
	// while (1 == 1)
	// {
	// 	signal(SIGUSR1, ft_confirm);
	// 	signal(SIGUSR2, ft_confirm);
	// 	pause();
	// }
}
