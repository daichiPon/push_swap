/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 03:42:10 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/06/10 21:26:41 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	is_option(char *str)
{
	return (ft_strncmp(str, "--", 2) == 0);
}

static int	is_in_range(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (num * sign > 2147483647 || num * sign < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

void	flag_check(int argc, char *argv[], int *flag, int *bench)
{
	int	i;

	i = 1;
	*flag = 1;
	*bench = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			if (ft_strcmp(argv[i], "--adaptive") == 0)
				*flag = 1;
			else if (ft_strcmp(argv[i], "--simple") == 0)
				*flag = 2;
			else if (ft_strcmp(argv[i], "--medium") == 0)
				*flag = 3;
			else if (ft_strcmp(argv[i], "--complex") == 0)
				*flag = 4;
			else if (ft_strcmp(argv[i], "--*") == 0)
				*bench = 1;
		}
		i++;
	}
}

int	arg_check(int argc, char *argv[], int *flag, int *bench)
{
	int	i;
	int	j;

	flag_check(argc, argv, flag, bench);
	i = 1;
	while (i < argc)
	{
		if (!is_option(argv[i]) && !is_valid_number(argv[i]))
			return (1);
		if (!is_option(argv[i]) && !is_in_range(argv[i]))
			return (1);
		j = i + 1;
		while (!is_option(argv[i]) && j < argc)
		{
			if (!is_option(argv[j]) && ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
