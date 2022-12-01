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

int	new_line_in_buffer(char *buffer)
{
	return (0);
}

t_list	*add_chunk(int fd, char *buf)
{
	t_list	*new;
	char	*chunk;
	int		i;

	i = 0;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	while (buf[i])
		i++;
	chunk = (char *)malloc(i + 1 * sizeof(char));
	if (!content)
		return (0);
	new->content = chunk;
	new->next = NULL;
	return (new);
}
