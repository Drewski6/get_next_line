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

static int	new_line_in_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
	}
	return (0);
}

static char	*fill_return(t_list *lst)
{
	t_list	*current;
	char	*ret;
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	current = lst;
	while (current->next)
	{
		current = current->next;
		i++;
	}
	j = 0;
	while (current->content[j] != '\n')
		j++;
	size = (BUFFER_SIZE * i) + j + 1;
	ret = (char *)malloc(size * sizeof(char));
	if (!ret)
		return (0);
	while (size)	
	{
		ft_substr_mod()
		size--;
	}
	return (ret);
}

static size_t	ft_strlcat(char *dest, const char *src, size_t size)
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
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (dest_len > size)
		return (src_len + size);
	return (dest_len + src_len);
}

static t_list	*add_chunk(t_list **lst, int fd, char *buf)
{
	t_list	*new;
	t_list	*current;
	int		i;

	i = 0;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new->content)
		return (0);
	new->next = NULL;
	if (!ft_strlcat(new->content, buf, BUFFER_SIZE + 1))
		return (0)
	if (!*lst)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (new);
}
