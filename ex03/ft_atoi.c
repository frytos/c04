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
int	ft_char_is_white_space(char *str);
int	ft_if_sign_which(char *str);
int	ft_if_numeric_which(char *str);
int	ft_add_significand(long *ptr_unsigned_long, char *str);

int	ft_atoi(char *str)
{
	int		index;
	int		sign;
	long	unsigned_long;
	long	*ptr_unsigned_long;
	long	signed_long;

	index = 0;
	while (ft_char_is_white_space(&str[index]))
		index++;
	sign = 1;
	while (ft_if_sign_which(&str[index]))
	{
		sign *= ft_if_sign_which(&str[index]);
		index++;
	}
	unsigned_long = 0;
	ptr_unsigned_long = &unsigned_long;
	if (ft_if_numeric_which(&str[index]))
		ft_add_significand(ptr_unsigned_long, &str[index]);
	else
		return (0);
	return ((int)sign * unsigned_long);
}

int	ft_char_is_white_space(char *str)
{
	if (str[0] == 32 || (str[0] >= 9 && str[0] <= 13))
		return (1);
	else
		return (0);
}

int	ft_if_sign_which(char *str)
{
	if (str[0] == 45)
		return (-1);
	else if (str[0] == 43)
		return (1);
	else
		return (0);
}

int	ft_if_numeric_which(char *str)
{
	if (str[0] >= 48 && str[0] <= 57)
		return (*str);
	else
		return (0);
}

int	ft_add_significand(long *ptr_unsigned_long, char *str)
{
	int		rank;
	int		index_rank;
	long	to_add;

	if (ft_if_numeric_which(&str[1]) && str[0] != 0)
	{
		rank = ft_add_significand(ptr_unsigned_long, &str[1]);
		index_rank = rank;
		to_add = str[0] - '0';
		while (index_rank >= 0)
		{
			to_add *= 10;
			index_rank--;
		}
		*ptr_unsigned_long += to_add;
		return (rank + 1);
	}
	else
	{
		*ptr_unsigned_long += str[0] - '0';
		return (0);
	}
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
// 	char s10[] = "    \n \f \r \t \v   --+-2147483649"; // INT_MIN-1 0
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
