/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:58:44 by kyamagis          #+#    #+#             */
/*   Updated: 2022/06/01 17:40:50 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr(char *s, ssize_t size)
{
	size_t	len;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (INT_MAX <= len + size)
		return (-1);
	write(1, s, len);
	return (ft_strlen(s));
}

/*int	main(void)
{
	char	str[] = "wakatakakage";

	printf("%d\n", INT_MAX);
	printf("%d\n", printf("%s", str));
	printf("%zu\n", ft_putstr(str, 1));

	printf("%d\n", printf("%s", NULL));
	printf("%zu\n", ft_putstr(NULL, 1));
}*/
