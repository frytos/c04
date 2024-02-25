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
void	recursive_print(int nb);
void	ft_putchar(char digit);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	recursive_print(nb);
}

void	recursive_print(int nb)
{
	if (nb > 9)
		recursive_print(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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