/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:49:15 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/07 18:42:40 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ten(int n)
{
	ssize_t	digcount;

	digcount = 0;
	if (-10 < n && n < 0)
		digcount += write(1, "-", 1);
	if (n <= -10 || 10 <= n)
		digcount += ft_put_ten(n / 10);
	n = n % 10;
	if (n < 0)
		n *= -1;
	digcount += write(1, &TEN_BASE_STR[n], 1);
	return (digcount);
}

int	ft_put_hexa(unsigned int n, char *base)
{
	size_t	num;
	ssize_t	digcount;

	digcount = 0;
	num = n;
	if (n < 0)
		num = UINT_MAX + 1 + n;
	if (16 <= num)
		digcount += ft_put_hexa(num / 16, base);
	num = num % 16;
	digcount += write(1, &base[num], 1);
	return (digcount);
}

int	ft_put_pointer(void *n, ssize_t digcount)
{
	uintptr_t	num;

	num = (uintptr_t)n;
	if (digcount == 1)
		digcount += write (1, "0x", 2);
	if (n < 0)
		num = UINT_MAX + 1 + (uintptr_t)n;
	if (16 <= num)
	{
		digcount += 1;
		digcount = ft_put_pointer((void *)(num / 16), digcount);
	}
	num = num % 16;
	write(1, &S_HEX_BASE_STR[num], 1);
	return (digcount);
}

int	ft_put_uint(unsigned int n)
{
	ssize_t	digcount;

	digcount = 0;
	if (10 <= n)
		digcount += ft_put_uint(n / 10);
	n = n % 10;
	digcount += write(1, &TEN_BASE_STR[n], 1);
	return (digcount);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*int	main (void)
{
    printf("%s%s\n", "ft_put_ten","+++++++++++++++++++++++++++");

	printf("%i\n", 2147483647);
	printf(" origin %i\n", printf("%i", 2147483647));
	printf(" makeft %i\n", ft_put_ten(2147483647,"0123456789", 1));
	printf("\n");
	
	// printf(" origin %i\n", printf("%X", -2147483648));
	// printf(" makeft %i\n", ft_put_ten(-2147483648,"0123456789abcdef", 1));
	// printf("\n");
	
	printf("%i\n", -1);
	printf(" origin %i\n", printf("%i", -1));
	printf(" makeft %i\n", ft_put_ten(-1,"0123456789", 1));
	printf("\n");

	printf("%i\n", 0);
	printf(" origin %i\n", printf("%i", 0));
	printf(" makeft %i\n", ft_put_ten(0,"0123456789", 1));
	printf("\n");

	printf("%i\n", -2147483647);
	printf(" origin %i\n", printf("%i", -2147483647));
	printf(" makeft %i\n", ft_put_ten(-2147483647,"0123456789", 1));
	printf("\n");

	printf("%i\n",INT_MIN);
	printf(" origin %i\n", printf("%i", INT_MIN));
	printf(" makeft %i\n", ft_put_ten(INT_MIN,"0123456789", 1));
	printf("\n");

	// printf("%i\n", LONG_MAX);
	// printf(" origin %i\n", printf("%i", LONG_MAX));
	// printf(" makeft %i\n", ft_put_ten( LONG_MAX,"0123456789", 1));
	// printf("\n");

	// printf("%i\n", LONG_MIN);
	// printf(" origin %i\n", printf("%i", LONG_MIN));
	// printf(" makeft %i\n", ft_put_ten( LONG_MIN,"0123456789", 1));
	// printf("\n");

	// printf("%i\n", ULONG_MAX);
	// printf(" origin %i\n", printf("%i", ULONG_MAX));
	// printf(" makeft %i\n", ft_put_ten( ULONG_MAX,"0123456789", 1));
	// printf("\n");

	printf("%s%s\n", "ft_put_hexa","+++++++++++++++++++++++++++");

	printf("%i\n", 2147483647);
	printf(" origin %i\n", printf("%x", 2147483647));
	printf(" makeft %i\n", ft_put_hexa(2147483647,"0123456789abcdef", 1));
	printf("\n");
	
	// printf(" origin %i\n", printf("%X", -2147483648));
	// printf(" makeft %i\n", ft_put_hexa(-2147483648,"0123456789abcdef", 1));
	// printf("\n");
	
	printf("%i\n", -1);
	printf(" origin %i\n", printf("%x", -1));
	printf(" makeft %i\n", ft_put_hexa(-1,"0123456789abcdef", 1));
	printf("\n");

	printf("%i\n", 0);
	printf(" origin %i\n", printf("%X", 0));
	printf(" makeft %i\n", ft_put_hexa(0,"0123456789abcdef", 1));
	printf("\n");

	printf("%i\n", -2147483647);
	printf(" origin %i\n", printf("%x", -2147483647));
	printf(" makeft %i\n", ft_put_hexa(-2147483647,"0123456789abcdef", 1));
	printf("\n");


    printf("%s%s\n", "ft_put_pointer","+++++++++++++++++++++++++++");
	int		n = 100;
	void	*pointer = &n;
	printf(" origin %i\n", printf("%p", &n));
	printf(" makeft %i\n", ft_put_pointer(&n, "0123456789abcdef", 1));
	printf("\n");

	printf(" origin %i\n", printf("%p", pointer));
	printf(" makeft %i\n", ft_put_pointer(pointer, "0123456789abcdef", 1));
	printf("\n");
	
	printf(" origin %i\n", printf("%p", &pointer));
	printf(" makeft %i\n", ft_put_pointer(&pointer, "0123456789abcdef", 1));
	printf("\n");

	printf("%s%s\n", "ft_put_uint","+++++++++++++++++++++++++++");

	printf("%i\n", 2147483647);
	printf(" origin %i\n", printf("%u", 2147483647));
	printf(" makeft %i\n", ft_put_uint(2147483647, "0123456789", 1));
	printf("\n");
	
	printf("%i\n", -1);
	printf(" origin %i\n", printf("%u", -1));
	printf(" makeft %i\n", ft_put_uint(-1, "0123456789", 1));
	printf("\n");
	
	printf("%i\n", -2);
	printf(" origin %i\n", printf("%u", -2));
	printf(" makeft %i\n", ft_put_uint(-2, "0123456789", 1));
	printf("\n");
	
	printf("%i\n", 10);
	printf(" origin %i\n", printf("%u", 10));
	printf(" makeft %i\n", ft_put_uint(10, "0123456789", 1));
	printf("\n");
	
	printf("%i\n", 0);
	printf(" origin %i\n", printf("%u", 0));
	printf(" makeft %i\n", ft_put_uint(0, "0123456789", 1));
	printf("\n");
}*/