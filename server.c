/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigamas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:03:33 by abigamas          #+#    #+#             */
/*   Updated: 2024/09/12 13:25:02 by abigamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_title(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\x1b[36m----------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n");
	ft_printf("████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n");
	ft_printf("██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n");
	ft_printf("██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n");
	ft_printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\x1b[35mHi this is the PID: %d\x1b[0m\n", pid);
	ft_printf("\x1b[36m---------------------------------------------\x1b[0m\n");
	ft_printf("\n");
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
}

void	ft_reconstruct_char(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	t_signalaction;

	print_title();
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	t_signalaction.sa_sigaction = ft_reconstruct_char;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &signalaction, NULL);
		sigaction(SIGUSR2, &signalaction, NULL);
		if (sigaction(SIGUSR1, &signalaction, NULL) == -1)
			exit(1);
		if (sigaction(SIGUSR2, &signalaction, NULL) == -1)
			exit(1);
	}
	while (1)
	{
	}
	return (0);
}
