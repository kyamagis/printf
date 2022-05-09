/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:49:15 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/09 20:15:44 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_put_ten(size_t num, char *base, int digcount)
{
	if (10 <= num)
		digcount += ft_put_ten(num / 10, base, digcount);
	num = num % 10;
	ft_putchar_fd(base[num], 1);
	return (digcount);
}

int	ft_put_x(size_t num, char *base, int digcount)
{
	if (16 <= num)
		digcount += ft_put_x(num / 16, base, digcount);
	num = num % 16;
	ft_putchar_fd(base[num], 1);
	return (digcount);
}

int	ft_put_base(int n, int radix)
{
	size_t	num;
	int		digcount;

	digcount = 1;
	num = n;
	if (radix == 10)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			num = -1 * n;
			return (ft_put_ten(num, "0123456789", digcount) + 1);
		}
		return (ft_put_ten(num, "0123456789", digcount));
	}
	if (n < 0)
		num = UINT_MAX + 1 + n;
	if (radix == 'x')
		return (ft_put_x(num, "0123456789abcdef", digcount));
	return (ft_put_x(num, "0123456789ABCDEF", digcount));
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
	
    printf("%s%s\n", "ft_put_base","+++++++++++++++++++++++++++");

	printf("%i\n", 2147483647);
	printf(" origin %i\n", printf("%x", 2147483647));
	printf(" makeft %i\n", ft_put_base(2147483647, 'x'));
	printf("\n");
	
	// printf(" origin %i\n", printf("%X", -2147483648));
	// printf(" makeft %i\n", ft_put_base(-2147483648, 'X'));
	// printf("\n");
	
	printf("%i\n", -1);
	printf(" origin %i\n", printf("%x", -1));
	printf(" makeft %i\n", ft_put_base(-1, 'x'));
	printf("\n");

	printf("%i\n", 0);
	printf(" origin %i\n", printf("%X", 0));
	printf(" makeft %i\n", ft_put_base(0, 'X'));
	printf("\n");

	printf("%i\n", -2147483647);
	printf(" origin %i\n", printf("%i", -2147483647));
	printf(" makeft %i\n", ft_put_base(-2147483647, 10));
	printf("\n");

}*/