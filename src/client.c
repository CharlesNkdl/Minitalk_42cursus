#include "../inc/minitalk.h"

void	sending(int pid, char c)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		if (c & 0x01)
			kill(pid,SIGUSR1);
		else
			kill(pid,SIGUSR2);
		c = c >> 1;
		usleep(500);
		//bit++;
	}
}

void	siglen(int pid, int len)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		len = len >> 1;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		if (kill(ft_atoi(argv[1]), 0) < 0)
		{
			ft_printf("PID is Invalid, maybe try again. \n");
			return (1);
		}
		pid = ft_atoi(argv[1]);
		siglen(pid, ft_strlen(argv[2]));
		while (argv[2][i] != '\0')
		{
			sending(pid, argv[2][i]);
			i++;
		}
		sending(pid, argv[2][i]);
	}
	else
	{
		ft_printf("As the client, i receive : ./client <PID> <String>, nothing else. \n");
		return (1);
	}
	return (0);
}
