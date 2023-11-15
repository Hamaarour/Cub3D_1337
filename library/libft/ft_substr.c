/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:17:17 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/15 04:05:05 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*test(unsigned int res, unsigned int len)
{
	char	*p;

	if (len > res)
		p = malloc(res + 1);
	else
		p = malloc(len + 1);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*p;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	p = test(ft_strlen(s) - start, len);
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (i == start)
		{
			while (s[i] && j < len)
				p[j++] = s[i++];
			break ;
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}