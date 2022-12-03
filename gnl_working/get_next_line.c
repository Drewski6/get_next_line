/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:53:18 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/01 13:53:23 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buf;
	char			*ret;
	static int		fd_table[1024];
	size_t			buf_size;

	buf_size = 1024;
	if (buf_size > BUFFER_SIZE)
		buf_size = BUFFER_SIZE;
	ret = 0;
	buf = (char *)ft_calloc_gnl((buf_size + 1), sizeof(char));
	if (!buf)
		return (0);
	fd_table[fd] = make_ret_gnl(fd, &ret, buf, buf_size);
	free(buf);
	if (fd_table[fd] == -1)
		return (0);
	if (!ret)
		return (0);
	return (ret);
}
