/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:43:31 by ashirzad          #+#    #+#             */
/*   Updated: 2024/01/15 16:17:00 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "printf/ft_printf.h"

char	*char_to_bin(char c)
{
	char	*str;
	int		i;

	str = ft_calloc(sizeof(char), 9);
	ft_memset(str, '0', 8);
	i = 0;
	while (c != 0)
	{
		str[i] = (c % 2) + 48;
		c /= 2;
		i++;
	}
	return (str);
}

void	send_signal(char *str, int pid)
{
	char	*ptr;

	while (*str)
	{
		ptr = char_to_bin(*str);
		while (*ptr)
		{
			if (*ptr == '1')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			ptr++;
		}
		free(ptr - 8);
		str++;
	}
}

int	main(int args, char **argv)
{
	int		pid;
	char	*ptr;

	if (args < 3)
	{
		write(1, "Two arguments must be given (PID) (STR)\n", 41);
		return (0);
	}
	(void) args;
	pid = ft_atoi(argv[1]);
	send_signal(argv[2], pid);
	ptr = char_to_bin('\n');
	while (*ptr)
	{
		if (*ptr == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(5);
		ptr++;
	}
	free(ptr - 8);
	return (0);
}
