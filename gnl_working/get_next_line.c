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
	static char		*buf;
	char			*ret;
	static int		fd_table[1024];

	ret = 0;
	if (!buf)
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	fd_table[fd] = make_ret(fd, &ret, buf, fd_table[fd]);
	if (!ret)
		return (0);
	return (ret);
}
