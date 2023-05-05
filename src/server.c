#include "../inc/minitalk.h"

int	ft_iterative_power(int nb, int power)
{
	int	stock;

	stock = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
	{
		return (nb);
	}
	while (power != 1)
	{
		if (stock == 0)
			stock = nb * nb;
		else
			stock *= nb;
		power--;
	}
	return (stock);
}

void	refresh(int *len,char **str, int *index)
{
	*len = 0;
	if (str)
	{
		ft_printf("%s\n",*str);
		free(*str);
		*str = 0;
	}
	*index = 0;
}

void	translation(int signal)
{
	static	int	bit = 0;
	static	int	i = 0;
	static	int	len = 0;
	static	char	*answer;
	static	int	index = 0;

	if (!len)
		begintranslation(&bit, &answer, &len, signal);
	else
	{
		if (signal == SIGUSR1)
			i += ft_iterative_power(2, bit);
		if (bit == 7)
		{
			answer[index] = i;
			index++;
			bit = 0;
			if (i == 0)
				return (refresh(&len, &answer, &index));
			i = 0;
			return ;
		}
		bit++;
	}
}

void	*begintranslation(int *bit, char **str, int *len, int signal)
{
	static int	len_val = 0;

	if (signal == SIGUSR1)
		len_val += ft_iterative_power(2, *bit);
	if (*bit == 31)
	{
		*len = 1;
		*str = malloc(len_val + 1);
		if (!*str)
			return (NULL);
		*bit = 0;
		len_val = 0;
		return (0);
	}
	(*bit)++;
	return (0);
}

int	main(void)
{
	int pid;

	pid = getpid();
	ft_printf("Process Identification : %d\n",pid);
	ft_printf("Please give the PID to the client, I'll print out the information myself. \n");
	while (1)
	{
		signal(SIGUSR1,	translation);
		signal(SIGUSR2, translation);
		pause();
	}
	return (0);
}
