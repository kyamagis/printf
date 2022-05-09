/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:09:32 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/09 20:11:47 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_uint(unsigned int n, int	digcount)
{
	if (10 <= n)
		digcount += ft_uint(n / 10, digcount);
	n = n % 10;
	ft_putchar_fd('0' + n, 1);
	return (digcount);
}

int	ft_put_uint(unsigned int n)
{
	int	digcount;

	digcount = 1;
	return (ft_uint(n, digcount));
}

/*int	main (void)
{
    printf("%s%s\n", "ft_put_uint","+++++++++++++++++++++++++++");

	printf("%i\n", 2147483647);
	printf(" origin %i\n", printf("%u", 2147483647));
	printf(" makeft %i\n", ft_put_uint(2147483647));
	printf("\n");
	
	printf("%i\n", -1);
	printf(" origin %i\n", printf("%u", -1));
	printf(" makeft %i\n", ft_put_uint(-1));
	printf("\n");
	
	printf("%i\n", -2);
	printf(" origin %i\n", printf("%u", -2));
	printf(" makeft %i\n", ft_put_uint(-2));
	printf("\n");
	
	printf("%i\n", 10);
	printf(" origin %i\n", printf("%u", 10));
	printf(" makeft %i\n", ft_put_uint(10));
	printf("\n");
	
	printf("%i\n", 0);
	printf(" origin %i\n", printf("%u", 0));
	printf(" makeft %i\n", ft_put_uint(0));
	printf("\n");
}*/