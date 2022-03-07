/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:22:17 by flim              #+#    #+#             */
/*   Updated: 2022/03/07 11:08:44 by flim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minitalk.h>

//kill(atoi(argv[1]), SIGINT);
int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
	{
		printf("wrong number of arguments\n");
		return (0);
	}
	pid = atoi(argv[1]);
	bits = ft_to_bit(argv[2], 0, 0);
	if (bits == NULL)
	{
		printf("allocation went wrong\n");
		return (0);
	}
	ft_send_msg(pid, bits);
	free(bits);
}
