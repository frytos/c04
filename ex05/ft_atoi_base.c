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
int		check_base_and_size(char *base);
int		if_char_in_base_which(char *str, char *base, int base_number);
long	ft_add_significant(char *str, char *base, int base_number, long *ptr_unsigned_long);



int	ft_atoi_base(char *str, char *base)
{
	int		index;
	int		sign;
	int		base_number;
	long	unsigned_long;
	long	*ptr_unsigned_long;

	if (check_base_and_size(base) > 1)
	{
		base_number = check_base_and_size(base);
	}
	else
		return (0);
	index = 0;
	sign = 1;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
	{
		printf("skip WSP : %d\n", index);
		index++;
	}
	while (str[index] == 45 || str[index] == 43)
	{
		printf("skip signs : %d\n", index);
		if (str[index] == 45)
			sign *= -1;
			printf("change sign (%d) : %d\n", sign, index);
		index++;
	}
	unsigned_long = 0;
	ptr_unsigned_long = &unsigned_long;
	if (if_char_in_base_which(&str[index], base, base_number) >= 0)
		ft_add_significant(str, base, base_number, ptr_unsigned_long);
	else
		return (0);
	if (sign * unsigned_long < INT_MIN || INT_MAX < sign * unsigned_long)
		return (0);
	else
		return ((int)(sign * unsigned_long));
}

long ft_add_significant(char *str, char *base, int base_number, long *ptr_unsigned_long)
{
	int	rank;
	int index_rank;
	long to_add;

	if (if_char_in_base_which(&str[1], base, base_number) >= 0)
	{
		rank = ft_add_significant(&str[1], base, base_number, ptr_unsigned_long);
		index_rank = rank;
		to_add = if_char_in_base_which(&str[0], base, base_number);
		while (index_rank > 0)
		{
			to_add *= base_number;
			index_rank--;
		}
		*ptr_unsigned_long += to_add;
		return (rank + 1);
	}
	else
	{
		*ptr_unsigned_long += if_char_in_base_which(&str[1], base, base_number);
		return (0);
	}
}

int	if_char_in_base_which(char *str, char *base, int base_number)
{
	int base_index;

	base_index = 0;
	while (base_index < base_number)
	{
		printf("if_char_in_base_which : base_index = %d\n", base_index);
		if (str[0] == base[base_index])
		{
			printf("if_char_in_base_which : found %c (%d)\n", str[0], base_index);
			return (base_index);
			
		}
		else
		{

			base_index++;
		}
			
	}
	printf("if_char_in_base_which : not found %c (%d)\n", str[0], base_index);
	return (-1);
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

int	main(void)
{
	// // Test bases
	// char empty[] = "";
	// char single[] = "a";
	// char duplicate[] = "abcda";
	// char symbols[] = "ab+c";
	// char base2ab[] = "ab";

	// char b[] = "b"; 

	// printf("b in empty = %d\n", ft_atoi_base(b, empty));
	// printf("b in single = %d\n", ft_atoi_base(b, single));
	// printf("b in duplicate = %d\n", ft_atoi_base(b, duplicate));
	// printf("b in symbols = %d\n", ft_atoi_base(b, symbols));
	// printf("b in base2ab = %d\n", ft_atoi_base(b, base2ab));

	//Test whitespaces and +-
	char base5[] = "abcde";
	char school1[] = "bdc";
	char school2[] = "  --++--+-ddd";

	printf("school1 = %d\n", ft_atoi_base(school1, base5));
	printf("school2 = %d\n", ft_atoi_base(school2, base5));


	// char s1[] = "0"; 
	// char s2[] = "5"; 
	// char s3[] = "-21";
	// char s4[] = "123";
	// char s5[] = "-98765";

	// printf("s1 in base10 = %d\n", ft_atoi_base(s1, base10));
	// printf("s2 in base10 = %d\n", ft_atoi_base(s2, base10));
	// printf("s3 in base10 = %d\n", ft_atoi_base(s3, base10));
	// printf("s4 in base10 = %d\n", ft_atoi_base(s4, base10));
	// printf("s5 in base10 = %d\n", ft_atoi_base(s5, base10));

	// char s6[] = "X"; 
	// char s7[] = "Y"; 
	// char s8[] = "YY";
	// char s9[] = "-YXX";
	// char s10[] = "YXYX";

	// printf("s6 in base2 = %d\n", ft_atoi_base(s6, base2));
	// printf("s7 in base2 = %d\n", ft_atoi_base(s7, base2));
	// printf("s8 in base2 = %d\n", ft_atoi_base(s8, base2));
	// printf("s9 in base2 = %d\n", ft_atoi_base(s9, base2));
	// printf("s10 in base2 = %d\n", ft_atoi_base(s10, base2));

	

	// char s1[] = "arnaud"; 
	// char s2[] = "XYXYXXYYXYYXYYXYXYXYXY"; 
	// char s3[] = "    \n \f \r \t \v   ---++-+-abracadabra"; // -21
	// char s4[] = "--+-+--+--00075"; // -75
	// char s5[] = "    \n \f \r \t \v   --+-+--+-00092as5465as"; // 92
	// char s6[] = "    \n \f \r \t \v   --+- +--+-00092as5465as"; // 0
	// char s7[] = "    \n \f \r \t \v   --+--2147483647"; // INT_MAX 2147483647
	// char s8[] = "    \n \f \r \t \v   --+-2147483648"; // INT_MIN -2147483648
	// char s9[] = "    \n \f \r \t \v   --+--2147483648"; // INT_MAX+1 0
	// char s10[] = "    \n \f \r \t \v   --+-2147483649"; // INT_MIN-1 0

	// printf("s1 in base26 (7997603) = %d\n", ft_atoi_base(s1, base26));
	// printf("s2 in base2 (1366869) = %d\n", ft_atoi_base(s2, base2));
	// printf("s3 in base5 (3548795)= %d\n", ft_atoi_base(s3, base5));
	// printf("s4 in base10 = %d\n", ft_atoi_base(s4, base10));
	// printf("s8 in base10 = %d\n", ft_atoi_base(s8, base10));


// 	printf("s2 = %d\n", ft_atoi(s2));
// 	printf("s3 = %d\n", ft_atoi(s3));
// 	printf("s4 = %d\n", ft_atoi(s4));
// 	printf("s5 = %d\n", ft_atoi(s5));
// 	printf("s6 = %d\n", ft_atoi(s6));
// 	printf("s7 = %d\n", ft_atoi(s7));
// 	printf("s8 = %d\n", ft_atoi(s8));
// 	printf("s9 = %d\n", ft_atoi(s9));
// 	printf("s10 = %d\n", ft_atoi(s10));
	                
}
