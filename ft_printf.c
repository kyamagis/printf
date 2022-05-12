/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:01:46 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/12 11:43:11 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_condition(int c, va_list pmts, long long	len)
{
	long long	size;

	size = 0;
	if (c == 'c')
		size = ft_put_unchar(va_arg(pmts, int));
	if (c == 's')
		size = ft_putstr(va_arg(pmts, char *), len);
	if (c == 'p')
		size = ft_put_pointer(va_arg(pmts, void *), "0123456789abcdef", 1);
	if (c == 'd' || c == 'i')
		size = ft_put_ten(va_arg(pmts, int), "0123456789", 1);
	if (c == 'u')
		size = ft_put_uint(va_arg(pmts, int), "0123456789", 1);
	if (c == 'x')
		size = ft_put_hexa(va_arg(pmts, int), "0123456789abcdef", 1);
	if (c == 'X')
		size = ft_put_hexa(va_arg(pmts, int), "0123456789ABCDEF", 1);
	if (c == '%')
	{
		write(1, "%", 1);
		size = 1;
	}
	if (INT_MAX <= len + size || size == -1)
		return (-1);
	return (len + size);
}

static int	ft_writestr(const char *str, va_list pmts)
{
	size_t		i;
	long long	len;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len = ft_write_condition(str[i + 1], pmts, len);
			if (len == -1)
				return (-1);
			i++;
		}
		else
		{
			len++;
			if (INT_MAX <= len)
				return (-1);
			write(1, &str[i], 1);
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	pmts;
	int		len;

	if (format == NULL)
		return (0);
	va_start(pmts, format);
	len = ft_writestr(format, pmts);
	va_end(pmts);
	if (len == -1)
		return (-1);
	return (len);
}

/*int main(void)
{
	printf("%s%s\n", "i_decimal","+++++++++++++++++++++++++++");

	printf("%d\n", +INT_MAX);
	printf(" origin %i\n", printf("%d", +INT_MAX));
	printf(" makeft %i\n", ft_printf("%d", +INT_MAX));
	printf("\n");

	printf("%i\n", 2147483647);
	printf(" origin %i\n", printf("%i", 2147483647));
	printf(" makeft %i\n", ft_printf("%i", 2147483647));
	printf("\n");
	
	// printf(" origin %i\n", printf("%X", -2147483648));
	// printf(" makeft %i\n", ft_put_ten(-2147483648,"0123456789abcdef", 1));
	// printf("\n");
	
	printf("%i\n", -1);
	printf(" origin %i\n", printf("%i", -1));
	printf(" makeft %i\n", ft_printf("%i", -1));
	printf("\n");

	printf("%i\n", 0);
	printf(" origin %i\n", printf("%i", 0));
	printf(" makeft %i\n", ft_printf("%i", 0));
	printf("\n");

	printf("%i\n", -2147483647);
	printf(" origin %i\n", printf("%i", -2147483647));
	printf(" makeft %i\n", ft_printf("%i", -2147483647));
	printf("\n");

	printf("%s%s\n", "hexadeciaml_X","+++++++++++++++++++++++++++");

	printf("%i\n", 2147483647);
	printf(" origin %i\n", printf("%x", 2147483647));
	printf(" makeft %i\n", ft_printf("%x", 2147483647));
	printf("\n");
	
	// printf(" origin %i\n", printf("%X", -2147483648));
	// printf(" makeft %i\n", ft_put_hexa(-2147483648,"0123456789abcdef", 1));
	// printf("\n");
	
	printf("%i\n", -1);
	printf(" origin %i\n", printf("%x", -1));
	printf(" makeft %i\n", ft_printf("%x", -1));
	printf("\n");

	printf("%i\n", 0);
	printf(" origin %i\n", printf("%X", 0));
	printf(" makeft %i\n", ft_printf("%X", 0));
	printf("\n");

	printf("%i\n", -2147483647);
	printf(" origin %i\n", printf("%x", -2147483647));
	printf(" makeft %i\n", ft_printf("%x", -2147483647));
	printf("\n");


    printf("%s%s\n", "pointer","+++++++++++++++++++++++++++");
	int		n = 100;
	void	*pointer = &n;
	printf(" origin %i\n", printf("%p", &n));
	printf(" makeft %i\n", ft_printf("%p", &n));
	printf("\n");

	printf(" origin %i\n", printf("%p", pointer));
	printf(" makeft %i\n", ft_printf("%p", pointer));
	printf("\n");
	
	printf(" origin %i\n", printf("%p", &pointer));
	printf(" makeft %i\n", ft_printf("%p", &pointer));
	printf("\n");

	printf("%s%s\n", "unsigend_int","+++++++++++++++++++++++++++");

	printf("%i\n", 2147483647);
	printf(" origin %i\n", printf("%u", 2147483647));
	printf(" makeft %i\n", ft_printf("%u", 2147483647));
	printf("\n");
	
	printf("%i\n", -1);
	printf(" origin %i\n", printf("%u", -1));
	printf(" makeft %i\n", ft_printf("%u", -1));
	printf("\n");
	
	printf("%i\n", -2);
	printf(" origin %i\n", printf("%u", -2));
	printf(" makeft %i\n", ft_printf("%u", -2));
	printf("\n");
	
	printf("%i\n", 10);
	printf(" origin %i\n", printf("%u", 10));
	printf(" makeft %i\n", ft_printf("%u", 10));
	printf("\n");
	
	printf("%i\n", 0);
	printf(" origin %i\n", printf("%u", 0));
	printf(" makeft %i\n", ft_printf("%u", 0));
	printf("\n");

	printf("%s%s\n", "all_speci","+++++++++++++++++++++++++++");
	char	str[] = "wakatakakage";
	void	*p = &n;

	printf("   printf(return): %d\n", printf("   printf(output): hello, %c%s, %s, %p, %d, %i, %u, %x, %X, %%%%\n", 'a', str, str, p, -2147483647, 2147483647, 2147483647, 2147483647, 2147483647));
	printf("ft_printf(return): %d\n", ft_printf("ft_printf(output): hello, %c%s, %s, %p, %d, %i, %u, %x, %X, %%%%\n", 'a', str, str, p, -2147483647, 2147483647, 2147483647, 2147483647, 2147483647));
	printf("\n");

	printf("%s%s\n", "INT_MAX","+++++++++++++++++++++++++++");
	char *s1 = (char *)malloc(sizeof(char) * (2147483648));
	printf(" origin %i\n", printf("%s",memset(s1, '1', INT_MAX)));
	printf(" makeft %i\n", ft_printf("%s",memset(s1, '1', INT_MAX)));
	printf("\n");

	char *s2 = (char *)malloc(sizeof(char) * (2147483647));
	printf(" origin %i\n", printf("a%d%sa%d", n, memset(s2, '1', 2147483646), n));
	printf(" makeft %i\n", ft_printf("a%d%sa%d", n, memset(s2, '1', 2147483646), n));
	printf("\n");

	// char *s3 = (char *)malloc(sizeof(char) * (2147483648));
	// printf(" origin %i\n", printf("%s%d", memset(s3, '1', 2147483646), n));
	// printf(" makeft %i\n", ft_printf("%s%d", memset(s3, '1', 2147483646), n));
	// printf("\n");

	char *s4 = (char *)malloc(sizeof(char) * (2147483647));
	printf(" origin %i\n", printf("a%s", memset(s4, '1', 2147483646)));
	printf(" makeft %i\n", ft_printf("a%s", memset(s4, '1', 2147483646)));
	printf("\n");
}*/