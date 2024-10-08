/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:55:47 by sabras            #+#    #+#             */
/*   Updated: 2024/10/09 01:48:43 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef MEM_SIZE
#  define MEM_SIZE 21
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_find_new_line(char *tab, int bytes_read);
char	*ft_create_line(char **tab, int len);
int		ft_tab_add(char **tab, char *buffer, int bytes_read);
int		ft_tab_realloc(char **tab, int size, int start);
void	ft_tab_free(char **tab);

#endif
