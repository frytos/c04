/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:38:35 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/16 03:39:44 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		write(1, &str[index], 1);
		index++;
	}
}

// int	main(void)
// {
// 	char myString[] = "Hello Pisciners !";
// 	printf("myString = %s\n", myString);
// 	ft_putstr(myString);
// 	return (0);
// }
