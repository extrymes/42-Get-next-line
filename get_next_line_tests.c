/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:27:21 by sabras            #+#    #+#             */
/*   Updated: 2024/05/21 22:02:42 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char		*line;
	int			fd;
	int			i;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	line = "";
	i = 1;
	while (line)
	{
		line = get_next_line(fd);
		printf("Line %d: %s", i++, line);
		free(line);
	}
	return (0);
}
