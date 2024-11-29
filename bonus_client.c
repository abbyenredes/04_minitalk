#include "minitalk.h"

int	g_signal = 0;

void	confirm_msg(int signal)
{
	if (signal == SIGUSR2)
		g_signal = 1;	
}


void	ft_binary_conversion(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) !=0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		
		// while (g_signal == 0)
		// pause();	
		// usleep(25); 
		// g_signal = 0;
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	struct	sigaction	msg_ok;

	i = 0;
	sigemptyset(&msg_ok.sa_mask);
	msg_ok.sa_flags = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_binary_conversion(pid, argv[2][i]);
			i++;
		}
		
		msg_ok.sa_handler = confirm_msg;
		sigaction(SIGUSR2, &msg_ok, NULL);
		ft_printf("signal recieved\n",  argv[2]);
		ft_binary_conversion(pid, '\n');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
