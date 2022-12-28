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

/*  ft_bzero
 *
 *  Sets memory values to 0 for initilization purposes.
 *  Returns nothing.
 */

void	ft_bzero(void *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(char *)str = 0;
		str++;
		i++;
	}
}

/*  ft_memcpy
 *
 *  Copies len number of bytes starting from src to dest
 *  Returns pointer to destination string.
 */

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < len)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

/*  ft_strlen
 *
 *  Returns number of bytes from str address to next null terminator.
 */

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

/*  ft_strjoin
 *
 *  Joins 2 string together to make a new string.
 *  Returns new malloced string 'ptr' that contains s1 followed by s2.
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len + s2_len == 0)
		return (0);
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, (s1_len + s2_len + 1));
	ft_memcpy(ptr, (char *)s1, s1_len);
	ft_memcpy((ptr + s1_len), (char *)s2, s2_len);
	free((char *)s1);
	return (ptr);
}

/*  ft_strdup
 *
 *  Creates a new string that is an exact copy of 'str'.
 *  Returns new malloced string that is an exact copy of 'str'.
 */

char	*ft_strdup(const char *src)
{
	char	*str_ret;
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	str_ret = (char *)malloc((src_len + 1) * sizeof(char));
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
