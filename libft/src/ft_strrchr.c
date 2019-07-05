/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:32:39 by amaurel           #+#    #+#             */
/*   Updated: 2017/11/09 16:16:06 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *s2;

	s2 = NULL;
	while (*s)
	{
		if (*s == (char)c)
			s2 = (char *)s;
		s++;
	}
	if (!c)
		return ((char *)s);
	return (s2);
}