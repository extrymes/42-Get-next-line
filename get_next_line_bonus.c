/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:19:31 by sabras            #+#    #+#             */
/*   Updated: 2024/05/27 10:41:30 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		*tab[1025];
	char			*buffer;
	int				bytes_read;
	int				len;

	if (BUFFER_SIZE < 1)
		return (NULL);
	len = ft_find_new_line(tab[fd], BUFFER_SIZE);
	while (len == -1)
	{
		buffer = malloc((BUFFER_SIZE) * sizeof(char));
		if (!buffer)
			return (ft_tab_free(&tab[fd]), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || !ft_tab_add(&tab[fd], buffer, bytes_read))
			return (ft_tab_free(&tab[fd]), free(buffer), NULL);
		len = ft_find_new_line(tab[fd], bytes_read);
		if (len == 0)
			return (ft_tab_free(&tab[fd]), NULL);
	}
	return (ft_create_line(&tab[fd], len));
}
