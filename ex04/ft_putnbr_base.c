/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:42:49 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/16 06:21:11 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void	ft_recursive_print(long n, char *base, int len_base);
int		check_base_get_size(char *base);
void	ft_putnbr_base(int nbr, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbr_long;
	int		len_base;

	len_base = check_base_get_size(base);
	if (len_base < 2)
		return ;
	nbr_long = nbr;
	if (nbr_long < 0)
	{
		write(1, "-", 1);
		nbr_long = -nbr_long;
	}
	ft_recursive_print(nbr_long, base, len_base);
}

void	ft_recursive_print(long n, char *base, int len_base)
{
	if (n / len_base > 0)
		ft_recursive_print(n / len_base, base, len_base);
	write(1, &base[n % len_base], 1);
}

int	check_base_get_size(char *base)
{
	int	len_base;
	int	search_index;

	len_base = 0;
	while (base[len_base])
	{
		if (base[len_base] == '+' || base[len_base] == '-')
			return (0);
		search_index = 1;
		while (base[len_base + search_index])
		{
			if (base[len_base] == base[len_base + search_index])
				return (0);
			search_index ++;
		}
		len_base++;
	}
	return (len_base);
}

// int	main(void)
// {
// 	char s1[] = "x";
// 	char s2[] = "lol";
// 	char s3[] = "a+b";
// 	char s4[] = "ab-";
// 	char s5[] = "01234";
// 	char s6[] = "abcdefghijklmnopqrstuvwxyz";
// 	char s7[] = "0123456789";

// 	ft_putnbr_base(10, s1); write(1, "\n", 1);
// 	ft_putnbr_base(96, s2); write(1, "\n", 1);
// 	ft_putnbr_base(80, s3); write(1, "\n", 1);
// 	ft_putnbr_base(80, s4); write(1, "\n", 1);
// 	ft_putnbr_base(153, s5); write(1, "\n", 1);
// 	ft_putnbr_base(-105893, s5); write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, s6); write(1, "\n", 1);
// 	ft_putnbr_base(2147483647, s6); write(1, "\n", 1);
// 	ft_putnbr_base(0, s6); write(1, "\n", 1);
// 	//ft_putnbr_base(-2147483649, s6); write(1, "\n", 1);
// 	//ft_putnbr_base(2147483648, s6); write(1, "\n", 1);

// 	ft_putnbr_base(153, s7); write(1, "\n", 1);
// 	ft_putnbr_base(-105893, s7); write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, s7); write(1, "\n", 1);
// 	ft_putnbr_base(2147483647, s7); write(1, "\n", 1);
// 	ft_putnbr_base(0, s7); write(1, "\n", 1);
// 	//ft_putnbr_base(-2147483649, s7); write(1, "\n", 1);
// 	//ft_putnbr_base(2147483648, s7); write(1, "\n", 1);

// 	return (0);
// }

// int	main(int argc, char *argv[])
// {
// 	(void) argc;
// 		ft_putnbr_base(atoi(argv[1]), argv[2]);
// }