/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <aorynbay@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:26:00 by aorynbay          #+#    #+#             */
/*   Updated: 2024/05/07 10:26:01 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_nbr(unsigned int n)
{
	char	ch;

	ch = '\0';
	if (n > 0)
	{
		ch = n % 10 + '0';
		put_nbr(n / 10);
		write (1, &ch, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write (1, "0", 1);
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		put_nbr(-nb);
	}
	else
	{
		put_nbr(nb);
	}
}

// int	main(void)
// {
// 	ft_putnbr(42);
// }