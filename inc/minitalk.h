#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/Headers/libft.h"
# include "../libft/Headers/get_next_line_bonus.h"
# include "../libft/Headers/ft_printf.h"

void	refresh(int *len,char **str, int *index);
void	sending(int pid, char c);
void	siglen(int pid, int len);
void	translation(int signal);
void	*begintranslation(int *bit, char **str, int *len, int signal);

#endif

