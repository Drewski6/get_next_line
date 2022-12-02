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
	t_list	*first
	char	*buffer;
	char	*return_string;

	first = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = 0;
	while (!new_line_in_buffer(buffer))
	{
		add_chunk(&first, fd, buffer);
	}
	return_string = fill_return(first);
	if (!return_string)
		return (0);
	free(buffer);
	return (buffer);
}
