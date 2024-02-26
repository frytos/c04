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
#include <stdlib.h>

int		strpos(char *base, char c);
int		check_base_get_size(char *base);
int		ft_add_significand(char *str, int n, int len_base, char *base);
int		ft_atoi_base(char *str, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	index;
	int	sign;
	int	n;
	int	len_base;

	index = 0;
	sign = 1;
	n = 0;
	len_base = check_base_get_size(base);
	if (len_base < 2)
		return (0);
	while ((9 <= str[index] && str[index] <= 13) || str[index] == 32)
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	n = ft_add_significand(&str[index], n, len_base, base);
	return (sign * n);
}

int	strpos(char *base, char c)
{
	int	pos;

	pos = 0;
	while (base[pos])
	{
		if (base[pos] == c)
			return (pos);
		pos++;
	}
	return (-1);
}

int	ft_add_significand(char *str, int n, int len_base, char *base)
{
	int	base_value;

	base_value = strpos(base, str[0]);
	if ((0 <= base_value && base_value <= len_base - 1) && str[0])
	{
		n = n * len_base + base_value;
		n = ft_add_significand(&str[1], n, len_base, base);
		return (n);
	}
	else
		return (n);
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
		if ((9 <= base[len_base] && base[len_base] <= 13)
			|| base[len_base] == 32)
			return (0);
		search_index = 1;
		while (base[len_base + search_index])
		{
			if (base[len_base] == base[len_base + search_index])
				return (0);
			search_index++;
		}
		len_base++;
	}
	return (len_base);
}

// int	main(void)
// {

// //	Test bases
// 	char empty[] = "";
// 	char single[] = "b";
// 	char duplicate[] = "abcda";
// 	char symbols[] = "ab+c";
// 	char base2ab[] = "abc";
// 	char base10[] = "0123456789";
// 	char base2[] = "XY";

// 	char b[] = "bc"; 

// 	printf("b in empty = %d\n", ft_atoi_base(b, empty));
// 	printf("b in single = %d\n", ft_atoi_base(b, single));
// 	printf("b in duplicate = %d\n", ft_atoi_base(b, duplicate));
// 	printf("b in symbols = %d\n", ft_atoi_base(b, symbols));
// 	printf("b in base2ab = %d\n", ft_atoi_base(b, base2ab));

// // 	Test whitespaces and +-
// 	char base5[] = "abcde";
// 	char school1[] = "bdc";
// 	char school2[] = "  --++--+-ddd";

// 	printf("school1 = %d\n", ft_atoi_base(school1, base5));
// 	printf("school2 = %d\n", ft_atoi_base(school2, base5));

// 	char s1[] = "0"; 
// 	char s2[] = "5"; 
// 	char s3[] = "-21";
// 	char s4[] = "123";
// 	char s5[] = "-98765";

// 	printf("s1 in base10 = %d\n", ft_atoi_base(s1, base10));
// 	printf("s1 = %d\n", atoi(s1));
// 	printf("s2 in base10 = %d\n", ft_atoi_base(s2, base10));
// 	printf("s2 = %d\n", atoi(s2));
// 	printf("s3 in base10 = %d\n", ft_atoi_base(s3, base10));
// 	printf("s3 = %d\n", atoi(s3));
// 	printf("s4 in base10 = %d\n", ft_atoi_base(s4, base10));
// 	printf("s4 = %d\n", atoi(s4));
// 	printf("s5 in base10 = %d\n", ft_atoi_base(s5, base10));
// 	printf("s5 = %d\n", atoi(s5));

// 	char s6[] = "X"; 
// 	char s7[] = "Y"; 
// 	char s8[] = "YY";
// 	char s9[] = "-YXX";
// 	char s10[] = "YXYX";

// 	printf("s6 in base2 (0)= %d\n", ft_atoi_base(s6, base2));
// 	printf("s7 in base2 (1)= %d\n", ft_atoi_base(s7, base2));
// 	printf("s8 in base2 (3)= %d\n", ft_atoi_base(s8, base2));
// 	printf("s9 in base2 (4)= %d\n", ft_atoi_base(s9, base2));
// 	printf("s10 in base2 (10)= %d\n", ft_atoi_base(s10, base2));

// 	char base26[] = "abcdefghijklmnopqrstuvwxyz";
// 	char str1[] = "arnaud"; 
// 	char str2[] = "XYXYXXYYXYYXYYXYXYXYXY"; 
// 	char str3[] = "    \n \f \r \t \v   ---++-+-abaabaracadabra"; // -630
// 	char str4[] = "--+-+--+--00075"; // -75
// 	char str5[] = "    \n \f \r \t \v   --+-+--+-00092as5465as"; // 92
// 	char str6[] = "    \n \f \r \t \v   --+- +--+-00092as5465as"; // 0
// 	char str7[] = "    \n \f \r \t \v   --+--2147483647"; // INT_MAX 2147483647
// 	char str8[] = "    \n \f \r \t \v   --+-2147483648"; // INT_MIN -2147483648
// 	char str9[] = "    \n \f \r \t \v   --+--2147483648"; // INT_MAX+1 0
// 	char str10[] = "    \n \f \r \t \v   --+-2147483649"; // INT_MIN-1 0

// 	printf("str1 in base26 (7997603) = %d\n", ft_atoi_base(str1, base26));
// 	printf("str2 in base2 (1366869) = %d\n", ft_atoi_base(str2, base2));
// 	printf("str3 in base5 (-630)= %d\n", ft_atoi_base(str3, base5));
// 	printf("str4 in base10 = %d\n", ft_atoi_base(str4, base10));
// 	printf("str5 in base10 = %d\n", ft_atoi_base(str5, base10));
// 	printf("str6 in base10 = %d\n", ft_atoi_base(str6, base10));
// 	printf("str7 in base10 = %d\n", ft_atoi_base(str7, base10));
// 	printf("str8 in base10 = %d\n", ft_atoi_base(str8, base10));
// 	printf("str9 in base10 = %d\n", ft_atoi_base(str9, base10));
// 	printf("str10 in base10 = %d\n", ft_atoi_base(str10, base10));  

// 	char base2ab[] = "abc";
// 	char base10[] = "0123456789";
// 	char base2[] = "XY";
// 	char base5[] = "abcde";
// 	char base26[] = "abcdefghijklmnopqrstuvwxyz";
// 	printf("a in base2ab = %d\n", ft_atoi_base("aaaa", base2ab));
// 	printf("0 in base10 = %d\n", ft_atoi_base("000", base10));
// 	printf("X in base2 = %d\n", ft_atoi_base("XXX", base2));
// 	printf("a in base5 = %d\n", ft_atoi_base("aaa", base5));
// 	printf("a in base26 = %d\n", ft_atoi_base("aaa", base26));
// }