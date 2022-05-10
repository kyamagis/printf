/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:14:06 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/10 12:42:49 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_put_p(size_t num, char *base, int digcount)
{
	if (16 <= num)
		digcount += ft_put_x(num / 16, base, digcount);
	num = num % 16;
	ft_putchar_fd(base[num], 1);
	return (digcount);
}

int	ft_put_pointer(void *n)
{
	size_t	num;
	int		digcount;

	digcount = 1;
	num = (size_t)n;
	write (1, "0x", 2);
	if (n < 0)
		num = UINT_MAX + 1 + (long)n;
	return (ft_put_p(num, "0123456789abcdef", digcount) + 2);
}

/*int	main (void)
{
	int		n = 100;
	void	*pointer = &n;

    printf("%s%s\n", "ft_put_pointer","+++++++++++++++++++++++++++");
	printf(" origin %i\n", printf("%p", &n));
	printf(" makeft %i\n", ft_put_pointer(&n));
	printf("\n");

	printf(" origin %i\n", printf("%p", pointer));
	printf(" makeft %i\n", ft_put_pointer(pointer));
	printf("\n");
	
	printf(" origin %i\n", printf("%p", &pointer));
	printf(" makeft %i\n", ft_put_pointer(&pointer));
	printf("\n");

}*/