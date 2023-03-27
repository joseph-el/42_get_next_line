/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:51:50 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/02 20:25:02 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	char			*stash;
	struct s_list	*next;
}					t_list;

int					get_lenght(t_list *stow);
int					found_new_line(t_list *stow);

void				ft_lstadd_back(t_list **stash, t_list *new);
void				building_list(t_list **stow, char *buffer, int s_readed);
void				reading_file(int fd, t_list **stow);
void				ft_lstclear(t_list *stow);

t_list				*cleaning_list(t_list *stow);
t_list				*ft_lstlast(t_list *lst);

char				*get_next_line(int fd);
char				*get_line(t_list *stow);

#endif