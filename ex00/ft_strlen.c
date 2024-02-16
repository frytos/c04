/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:37:16 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/16 03:38:12 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		len++;
	}
	return (len);
}

// int	main(void)
// {
// 	char	myString[] = "Fryt";
// 	printf("Length of %s = %d", myString, ft_strlen(myString));
// 	return (0);
// }
