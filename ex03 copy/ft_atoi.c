/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <aorynbay@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:27:40 by aorynbay          #+#    #+#             */
/*   Updated: 2024/05/07 12:27:41 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	all_numbers_until_not(char *str, int i)
{
	int	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	check_if_negative(char *str, int *i)
{
	int	count;

	count = 0;
	while (str[*i] == '-' || str[*i] == '+'
		|| str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
	{
		if (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		{
			if (str[*i - 1] == '-' || str[*i - 1] == '+')
				return (0);
		}
		if (str[*i] == '-')
			count++;
		(*i)++;
	}
	return (count % 2);
}

int	ft_atoi(char *str)
{
	int	i;
	int	is_negative;
	int	result;

	i = 0;
	is_negative = 0;
	result = 0;
	is_negative = check_if_negative(str, &i);
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = all_numbers_until_not(str, i);
		if (is_negative == 1)
		{
			result = -result;
		}
		return (result);
		i++;
	}
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	char str[] = " ---12a34562227";
// 	printf("%i", ft_atoi(str));
// 	printf("%s", "\n");
// 	printf("%i", atoi(str));
// }