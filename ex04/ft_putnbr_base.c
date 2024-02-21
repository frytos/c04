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

void	ft_putnbr_base(int nbr, char *base);
int		check_base_and_size(char *str);
void	ft_putchar(char c);
void	get_and_print_significand(long long_nbr, int base_number, char *base);
char	convert_in_base(int significand, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_number;
	long	long_nbr;

	long_nbr = nbr;
	if (check_base_and_size(base) > 1)
		base_number = check_base_and_size(base);
	else
		return ;
	if (long_nbr < 0)
	{
		ft_putchar('-');
		long_nbr = -long_nbr;
	}
	get_and_print_significand(long_nbr, base_number, base);
}

void	get_and_print_significand(long long_nbr, int base_number, char *base)
{
	if (long_nbr / base_number)
	{
		get_and_print_significand(long_nbr / base_number, base_number, base);
		ft_putchar(convert_in_base(long_nbr % base_number, base));
	}
	else
		ft_putchar(convert_in_base(long_nbr % base_number, base));
}

char	convert_in_base(int significand, char *base)
{
	return (base[significand]);
}

int	check_base_and_size(char *str)
{
	int	len;
	int	search_index;

	len = 0;
	while (str[len] != 0)
	{
		if (str[len] == 43 || str[len] == 45)
			return (-3);
		search_index = 1;
		while (str[len + search_index] != 0)
		{
			if (str[len] == str[len + search_index])
				return (-2);
			search_index++;
		}
		len++;
	}
	if (len > 1)
		return (len);
	else
		return (-1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

// 	ft_putnbr_base(10, s1); ft_putchar(10);
// 	ft_putnbr_base(96, s2); ft_putchar(10);
// 	ft_putnbr_base(80, s3); ft_putchar(10);
// 	ft_putnbr_base(80, s4); ft_putchar(10);
// 	ft_putnbr_base(153, s5); ft_putchar(10);
// 	ft_putnbr_base(-105893, s5); ft_putchar(10);
// 	ft_putnbr_base(-2147483648, s6); ft_putchar(10);
// 	ft_putnbr_base(2147483647, s6); ft_putchar(10);
// 	ft_putnbr_base(0, s6); ft_putchar(10);
// 	//ft_putnbr_base(-2147483649, s6); ft_putchar(10);
// 	//ft_putnbr_base(2147483648, s6); ft_putchar(10);

// 	ft_putnbr_base(153, s7); ft_putchar(10);
// 	ft_putnbr_base(-105893, s7); ft_putchar(10);
// 	ft_putnbr_base(-2147483648, s7); ft_putchar(10);
// 	ft_putnbr_base(2147483647, s7); ft_putchar(10);
// 	ft_putnbr_base(0, s7); ft_putchar(10);
// 	//ft_putnbr_base(-2147483649, s7); ft_putchar(10);
// 	//ft_putnbr_base(2147483648, s7); ft_putchar(10);

// 	return (0);
// }