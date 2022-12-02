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

static char	*newline_in_buf(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (&buf[i + 1]);
		i++;
	}
	return (0);
}

static char	*ft_strdupncat(char *src, char *cat, int size)
{
	char	*str_ret;
	int		src_len;
	int		i;
	int		j;

	i = 0;
	src_len = 0;
	if (src)
	{
		while (src[src_len])
			src_len++;
	}
	str_ret = (char *)malloc((src_len + size + 1) * sizeof(char));
	if (!str_ret)
		return (0);
	if (src)
	{
		while (src[i])
		{
			str_ret[i] = src[i];
			i++;
		}
	}
	j = 0;
	while (j < size)
	{
		str_ret[i + j] = cat[j];
		if (cat[j] == '\n')
			break ;
		j++;
	}
	str_ret[i + j] = '\0';
	return (str_ret);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	make_ret(int fd, char **ret, char *buf, int offset)
{
	unsigned long	pos;
	char			*ret2;

	pos = 0;
	if (offset)
	{
		if (newline_in_buf(buf + offset))
			pos = (unsigned long) newline_in_buf(buf + offset) - (unsigned long) buf;
		else
		{
			ret2 = ft_strdupncat(*ret, buf + offset, ft_strlen(buf + offset));
			if (!read(fd, buf, BUFFER_SIZE))
				return (0);
			if (newline_in_buf(buf + offset))
				pos = (unsigned long) newline_in_buf(buf + offset) - (unsigned long) buf;
			free(*ret);
			*ret = ret2;
			offset = 0;
		}
	}
	while (!pos)
	{
		ret2 = ft_strdupncat(*ret, buf + offset, ft_strlen(buf + offset));
		if (!read(fd, buf, BUFFER_SIZE))
			return (0);
		if (newline_in_buf(buf + offset))
			pos = (unsigned long) newline_in_buf(buf + offset) - (unsigned long) buf;
		free(*ret);
		*ret = ret2;
	}
	if (pos)
		ret2 = ft_strdupncat(*ret, buf + offset, ft_strlen(buf + offset));
	free(*ret);
	*ret = ret2;
	return (pos);
}
