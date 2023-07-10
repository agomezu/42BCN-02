/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:15:12 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/23 14:51:24 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	const char		*string;
	char			character;

	i = 0;
	string = s;
	character = (char)c;
	while (string[i])
	{
		if (string[i] == character)
			return ((char *)&string[i]);
		++i;
	}
	if (character == string[i])
		return ((char *)&string[i]);
	return (NULL);
}