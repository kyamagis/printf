/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:58:44 by kyamagis          #+#    #+#             */
/*   Updated: 2022/05/09 18:54:53 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

/*int	main(void)
{
	char s[] = "abc";

	ft_putstr_fd(s, 1);
	return (0);
}*/
