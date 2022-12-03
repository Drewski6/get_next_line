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

void	*ft_calloc_gnl(size_t num_elem, size_t elem_size)
{
	void	*ptr;
	size_t	i;

	if (num_elem == 0 || elem_size == 0)
	{
		num_elem = 1;
		elem_size = 1;
	}
	if (num_elem >= SIZE_MAX || elem_size >= SIZE_MAX)
		return (0);
	ptr = malloc(num_elem * elem_size);
	if (ptr)
	{
		i = 0;
		while (i < (num_elem * elem_size))
		{
			*(char *)(ptr + i) = 0;
			i++;
		}
	}
	return (ptr);
}

static size_t	ft_strlcat_gnl(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0U;
	src_len = 0U;
	i = 0U;
	if (src == 0 || dest == 0)
		return (0);
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (dest_len > size)
		return (src_len + size);
	return (dest_len + src_len);
}

static char	*ft_strdup_gnl(const char *src, ssize_t r_size)
{
	char		*str_ret;
	size_t		src_len;
	size_t		i;
	size_t		read_size;

	read_size = (size_t)r_size;
	i = 0;
	src_len = 0;
	if (!src)
	{
		str_ret = (char *)ft_calloc_gnl(read_size + 1, sizeof(char));
		if (!str_ret)
			return (0);
		return (str_ret);
	}
	while (src[src_len])
		src_len++;
	str_ret = (char *)ft_calloc_gnl((src_len + read_size + 1), sizeof(char));
	if (!str_ret)
		return (0);
	i = 0;
	while (src[i])
	{
		str_ret[i] = src[i];
		i++;
	}
	str_ret[i] = 0;
	return (str_ret);
}

static size_t	fill_buffer_gnl(int fd, char *buf, size_t buf_size)
{
	size_t	i;
	ssize_t	r_size;

	i = 0;
	while (i < buf_size)
	{
		r_size = read(fd, &buf[i], 1);
		if (r_size == -1)
			return (-1);
		if (r_size == 0)
			return (i);
		if (buf[i] == '\n')
		{
			buf[i + 1] = 0;
			return (i + 1);
		}
		i++;
	}
	return (i);
}

int	make_ret_gnl(int fd, char **ret, char *buf, size_t buf_size)
{
	size_t	r_size;
	char	*ret_2;

	r_size = buf_size;
	while (r_size == buf_size)
	{
		r_size = fill_buffer_gnl(fd, buf, buf_size);
		if (r_size == -1)
			return (-1);
		if (r_size > 0)
		{
			ret_2 = ft_strdup_gnl(*ret, r_size);
			if (!ret_2)
			{
				free(*ret);
				*ret = 0;
				return (-1);
			}
			free(*ret);
			*ret = ret_2;
			if (!ft_strlcat_gnl(*ret, buf, (size_t)r_size + 1))
				return (-1);
		}
	}
	return (0);
}
