/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:53:38 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/01 13:53:41 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, (s1_len + s2_len + 1));
	ft_memcpy(ptr, (char *)s1, s1_len);
	ft_memcpy((ptr + s1_len), (char *)s2, s2_len);
	return (ptr);
}

char	*ft_strdup(const char *src)
{
	char	*str_ret;
	int		src_len;
	int		i;

	i = 0;
	src_len = ft_strlen(src);
	str_ret = (char *)malloc(src_len * sizeof(char) + 1);
	if (!str_ret)
		return (0);
	while (src[i])
	{
		str_ret[i] = src[i];
		i++;
	}
	str_ret[i] = '\0';
	return (str_ret);
}
