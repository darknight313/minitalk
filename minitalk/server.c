/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:44:29 by ashirzad          #+#    #+#             */
/*   Updated: 2024/01/15 16:34:48 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

int	ft_atoi_bin(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result = (result * 2) + (*str - 48);
		str++;
	}
	return (result);
}

void	fill_str(int binary_num)
{
	static int	i = 7;
	static char	str[9] = "00000000";
	int			b;

	if (binary_num)
		str[i] = '1';
	else
		str[i] = '0';
	i--;
	if (i < 0)
	{
		i = 7;
		b = ft_atoi_bin(str);
		write(1, &b, 1);
	}
}

void	sigusr1_handler(int signum)
{
	(void) signum;
	fill_str(1);
}

void	sigusr2_handler(int signum)
{
	(void) signum;
	fill_str(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "\n\n", 2);
	ft_printf("███╗   ███╗ ██╗███╗  ██╗██╗████████╗ █████╗ ██╗     ██╗ ██╗\n");
	ft_printf("████╗ ████║ ██║████╗ ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔\n");
	ft_printf("██╔████╔██║ ██║██╔██╗██║██║   ██║   ███████║██║     █████═╝\n");
	ft_printf("██║╚██╔╝██║ ██║██║╚████║██║   ██║   ██╔══██║██║     ██╔═██╗\n");
	ft_printf("██║ ╚═╝ ██║ ██║██║ ╚███║██║   ██║   ██║  ██║███████╗██║╚██╗\n");
	ft_printf("╚═╝     ╚═╝ ╚═╝╚═╝  ╚══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝ ╚═╝\n");
	ft_printf("\n                    \033[1;32mPID : (%d)\033[0m\n\n", pid);
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);
	while (1)
		sleep(10);
	return (0);
}
