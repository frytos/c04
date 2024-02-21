/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrouss <argrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:40:17 by argrouss          #+#    #+#             */
/*   Updated: 2024/02/16 03:40:46 by argrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	*recursive_print(int nb, char *nb_char, int index);
void	reverse_print(char *nb_char);
void	ft_putchar(char digit);

void	ft_putnbr(int nb)
{
	char	nb_char[12];
	int		index;

	index = 0;
	while (index < 12)
	{
		nb_char[index] = 0;
		index++;
	}
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	index = 0;
	recursive_print(nb, nb_char, index);
	reverse_print(nb_char);
}

void	*recursive_print(int nb, char *nb_char, int index)
{
	if (nb > 9)
		recursive_print(nb / 10, nb_char, index + 1);
	nb_char[index] = (nb % 10 + '0');
}

void	reverse_print(char *nb_char)
{
	int	index;

	index = 11;
	while (index >= 0)
	{
		ft_putchar(nb_char[index]);
		index--;
	}
}

void	ft_putchar(char digit)
{
	write(1, &digit, 1);
}

// int	main(void)
// {
// 	ft_putnbr(0); ft_putchar(10);
// 	ft_putnbr(5); ft_putchar(10);
// 	ft_putnbr(42); ft_putchar(10);
// 	ft_putnbr(-42); ft_putchar(10);
// 	ft_putnbr(-3); ft_putchar(10);
// 	ft_putnbr(1234567890); ft_putchar(10);
// 	ft_putnbr(-1994); ft_putchar(10);
// 	ft_putnbr(2147483647); ft_putchar(10);
// 	ft_putnbr(-2147483648); ft_putchar(10);
// 	ft_putnbr('a'); ft_putchar(10);
// 	return (0);
// }
