/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:20:18 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/16 06:34:51 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int		ft_atoi_base(char *str, char *base);
int		check_n_size(char *base);
int		ft_if_char_in_base_which(char *str, char *base, int base_nb);
long	ft_add_coeff(char *str, char *base, int base_nb, long *ptr_u_long);

int	ft_atoi_base(char *str, char *base)
{
	int		index;
	int		sign;
	long	u_long;
	long	*ptr_u_long;

	if (check_n_size(base) <= 1)
		return (0);
	index = 0;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	sign = 1;
	while (str[index] == 45 || str[index] == 43)
	{
		sign *= 44 - str[index];
		index++;
	}
	u_long = 0;
	ptr_u_long = &u_long;
	if (ft_if_char_in_base_which(&str[index], base, check_n_size(base)) < 0)
		return (0);
	ft_add_coeff(&str[index], base, check_n_size(base), ptr_u_long);
	return ((int)(sign * u_long));
}

long	ft_add_coeff(char *str, char *base, int base_nb, long *ptr_u_long)
{
	int		rank;
	int		index_rank;
	long	to_add;

	if (ft_if_char_in_base_which(&str[1], base, base_nb) >= 0)
	{
		rank = ft_add_coeff(&str[1], base, base_nb, ptr_u_long);
		index_rank = rank;
		to_add = ft_if_char_in_base_which(&str[0], base, base_nb);
		while (index_rank >= 0)
		{
			to_add *= base_nb;
			index_rank--;
		}
		*ptr_u_long += to_add;
		return (rank + 1);
	}
	else
	{
		*ptr_u_long += ft_if_char_in_base_which(&str[0], base, base_nb);
		return (0);
	}
}

int	ft_if_char_in_base_which(char *str, char *base, int base_nb)
{
	int	base_index;

	base_index = 0;
	while (base_index < base_nb)
	{
		if (str[0] == base[base_index])
			return (base_index);
		else
			base_index++;
	}
	return (-1);
}

int	check_n_size(char *str)
{
	int	len;
	int	search_index;

	len = 0;
	while (str[len] != 0)
	{
		if (str[len] == 43 || str[len] == 45)
			return (-3);
		if (str[0] == 32 || (str[0] >= 9 && str[0] <= 13))
			return (-4);
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

// int	main(void)
// {
// // Test bases
// 	char empty[] = "";
// 	char single[] = "a";
// 	char duplicate[] = "abcda";
// 	char symbols[] = "ab+c";
// 	char white_space[] = "abc de";
// 	char base2ab[] = "ab";
// 	char base26[] = "abcdefghijklmnopqrstuvwxyz";
// 	char base5[] = "abcdr";
// 	char base36[] = "0123456789abcdefghijklmnopqrstuvwxyz";
// 	char base_inv[] = "9876543210";
// 	char base2[] = "XY";
// 	char base10[] = "0123456789";

// 	char b[] = "b"; 

// 	printf("b in empty = %d\n", ft_atoi_base(b, empty));
// 	printf("b in single = %d\n", ft_atoi_base(b, single));
// 	printf("b in duplicate = %d\n", ft_atoi_base(b, duplicate));
// 	printf("b in symbols = %d\n", ft_atoi_base(b, symbols));
// 	printf("b in white_space = %d\n", ft_atoi_base(b, white_space));
// 	printf("b in base2ab = %d\n", ft_atoi_base(b, base2ab));

// // Test whitespaces and +-
// 	char c1[] = "bdc";
// 	char c2[] = "  --++--+-ddd";
// 	char c3[] = "\n \f \r \t \v  --+- +--+-00092as5465as";

// 	printf("c1 = %d\n", ft_atoi_base(c1, base5));
// 	printf("c2 = %d\n", ft_atoi_base(c2, base5));
// 	printf("c3 = %d\n", ft_atoi_base(c3, base5));

// 	char i1[] = "0"; 
// 	char i2[] = "5"; 
// 	char i3[] = "-21";
// 	char i4[] = "123";
// 	char i5[] = "-98765";
// 	char i6[] = "    \n \f \r \t \v   --+--2147483647"; // INT_MAX 2147483647
// 	char i7[] = "    \n \f \r \t \v   --+-2147483648"; // INT_MIN -2147483648
// 	char i8[] = "    \n \f \r \t \v   --+--2147483648"; // INT_MAX+1 0
// 	char i9[] = "    \n \f \r \t \v   --+-2147483649"; // INT_MIN-1 0

// 	printf("i1 in base10 = %d\n", ft_atoi_base(i1, base10));
// 	printf("i2 in base10 = %d\n", ft_atoi_base(i2, base10));
// 	printf("i3 in base10 = %d\n", ft_atoi_base(i3, base10));
// 	printf("i4 in base10 = %d\n", ft_atoi_base(i4, base10));
// 	printf("i5 in base10 = %d\n", ft_atoi_base(i5, base10));
// 	printf("i6 in base10 = %d\n", ft_atoi_base(i6, base10));
// 	printf("i7 in base10 = %d\n", ft_atoi_base(i7, base10));
// 	printf("i8 in base10 = %d\n", ft_atoi_base(i8, base10));
// 	printf("i9 in base10 = %d\n", ft_atoi_base(i9, base10));

// 	char b1[] = "X"; 
// 	char b2[] = "Y"; 
// 	char b3[] = "YY";
// 	char b4[] = "-YXX";
// 	char b5[] = "YXYX";

// 	printf("b1 in base2 = %d\n", ft_atoi_base(b1, base2));
// 	printf("b2 in base2 = %d\n", ft_atoi_base(b2, base2));
// 	printf("b3 in base2 = %d\n", ft_atoi_base(b3, base2));
// 	printf("b4 in base2 = %d\n", ft_atoi_base(b4, base2));
// 	printf("b5 in base2 = %d\n", ft_atoi_base(b5, base2));

// 	char s1[] = "arnaud"; 
// 	char s2[] = "XYXYXXYYXYYXYYXYXYXYXY"; 
// 	char s3[] = "    \n \f \r \t \v   ---++-+-abracadabra"; // -21
// 	char s4[] = "--+-+--+--00075"; // -75
// 	char s5[] = "    \n \f \r \t \v   --+-+--+-0sf9s5a"; // 92
// 	char s6[] = "    \n \f \r \t \v   --+--2147483647"; // INT_MAX 2147483647
// 	char s7[] = "    \n \f \r \t \v   --+-2147483648"; // INT_MIN -2147483648

// 	printf("s1 in base26 (7997603) = %d\n", ft_atoi_base(s1, base26));
// 	printf("s2 in base2 (1366869) = %d\n", ft_atoi_base(s2, base2));
// 	printf("s3 in base5 (3548795)= %d\n", ft_atoi_base(s3, base5));
// 	printf("s4 in base_inv (3548795)= %d\n", ft_atoi_base(s4, base_inv));
// 	printf("s5 in base36 (1718703550) = %d\n", ft_atoi_base(s5, base36));
// 	printf("s6 in base10 = %d\n", ft_atoi_base(s6, base10));
// 	printf("s7 in base10 = %d\n", ft_atoi_base(s7, base10));

// }