/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 21:04:56 by fmoreira          #+#    #+#             */
/*   Updated: 2021/07/26 16:13:37 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ns;

	if (!s1 || !s2)
		return (0);
	ns = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	if (ns)
	{
		while (s1[i])
		{
			ns[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			ns[i + j] = s2[j];
			j++;
		}
	}
	ns[i + j] = 0;
	return (ns);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*i;

	i = (char *)malloc(ft_strlen(s) + 1);
	if (!i)
		return (0);
	ft_memcpy(i, s, ft_strlen(s) + 1);
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*src;

	i = -1;
	j = ft_strlen(s + start);
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (malloc(1));
	if (j < len)
		len = j;
	src = malloc(len + 1);
	if (src)
	{
		while (++i < len)
		{
			src[i] = s[start + i];
		}
		return (src);
	}
	else
		return (0);
}
