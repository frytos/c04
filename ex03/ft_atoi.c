/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:24:03 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/16 03:34:01 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_atoi(char *str);
int	ft_add_significand(int n, char *str);

int	ft_atoi(char *str)
{
	int		index;
	int		sign;
	int		n;

	index = 0;
	sign = 1;
	n = 0;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	if ('0' <= str[index] && str[index] <= '9')
		n = ft_add_significand(n, &str[index]);
	n = sign * n;
	return (n);
}

int	ft_add_significand(int n, char *str)
{
	n = 10 * n + (str[0] - '0');
	if ('0' <= str[1] && str[1] <= '9')
	{
		n = ft_add_significand(n, &str[1]);
		return (n);
	}
	else
		return (n);
}

// int	main(void)
// {
// 	char s1[] = "arnaud"; // 0
// 	char s2[] = " "; // 0
// 	char s3[] = "    \n \f \r \t \v   -21"; // -21
// 	char s4[] = "--+-+--+--00075"; // -75
// 	char s5[] = "    \n \f \r \t \v   --+-+--+-00092as5465as"; // 92
// 	char s6[] = "    \n \f \r \t \v   --+- +--+-00092as5465as"; // 0
// 	char s7[] = "    \n \f \r \t \v   --+--2147483647"; // INT_MAX 2147483647
// 	char s8[] = "    \n \f \r \t \v   --+-2147483648"; // INT_MIN -2147483648
// 	char s9[] = "    \n \f \r \t \v   --+--2147483648"; // INT_MAX+1 0
// 	char s10[] = "-2147483649"; // INT_MIN-1 0
// 	printf("s1 = %d\n", ft_atoi(s1));
// 	printf("s2 = %d\n", ft_atoi(s2));
// 	printf("s3 = %d\n", ft_atoi(s3));
// 	printf("s4 = %d\n", ft_atoi(s4));
// 	printf("s5 = %d\n", ft_atoi(s5));
// 	printf("s6 = %d\n", ft_atoi(s6));
// 	printf("s7 = %d\n", ft_atoi(s7));
// 	printf("s8 = %d\n", ft_atoi(s8));
// 	printf("s9 = %d\n", ft_atoi(s9));
// 	printf("s10 = %d\n", ft_atoi(s10));
// 	return (0);
// }
// // ABCDEFGHIJKLMNOPQRSTUVWXYZ
// // 0123456789ABCDEFGHIJKLMNOP
// //https://jalu.ch/coding/base_converter.php
