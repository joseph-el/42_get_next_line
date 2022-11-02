/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:40:02 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/02 22:26:31 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*get_line(t_list *stow);
int					get_lenght(t_list *stow);
/**
** reading from fd and store nbytes (BUFFER SIZE) into the list
**/
void	reading_file(int fd, t_list **stow)
{
	char	*buffer;
	int		s_readed;

	s_readed = 1;
	while (!found_new_line(*stow) && s_readed != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		s_readed = read(fd, buffer, BUFFER_SIZE);
		if (s_readed == -1)
		{
			free(buffer);
			free(stow);
			return ;
		}
		buffer[s_readed] = 0;
		building_list(stow, buffer, s_readed);
		free(buffer);
	}
}
/**
* This function takes nbytes from buffer and stores it in an node at the end of list
* If the list does not exist, she will create it
**/
void	building_list(t_list **stow, char *buffer, int s_readed)
{
	t_list	*new;
	t_list	*last;
	int		i;

	new = NULL;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->stash = malloc(sizeof(char) * (s_readed + 1));
	if (!new->stash)
		return ;
	i = -1;
	while (buffer[++i] && i < s_readed)
		new->stash[i] = buffer[i];
	new->stash[i] = 0;
	ft_lstadd_back(stow, new);
}
/**
** Extract a line with '\n' from start of the list and return it 
**/
char	*get_line(t_list *stow)
{
	char	*line;
	int		j;
	int		i;

	if (!stow)
		return (NULL);
	line = malloc(sizeof(char) * (get_lenght(stow) + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (stow)
	{
		i = 0;
		while (stow->stash[i])
		{
			if (stow->stash[i] == '\n')
			{
				line[j++] = stow->stash[i];
				break ;
			}
			line[j++] = stow->stash[i++];
		}
		stow = stow->next;
	}
	line[j] = 0;
	if (*line == 0)
		return (NULL);
	return (line);
}
/**
* After extracting the correct line, this function takes the Remainder 
* after "\n" for save it as a node,otherwise she cleans all nodes and set NULL 
* in list for make the save at beginning of the list.
**/
t_list	*cleaning_list(t_list *stow)
{
	t_list	*cleaned;
	t_list	*last;
	int		i;
	int		j;

	cleaned = NULL;
	cleaned = malloc(sizeof(t_list));
	if (!stow || !cleaned)
		return (NULL);
	cleaned->next = NULL;
	last = ft_lstlast(stow);
	i = 0;
	while (last->stash[i] && last->stash[i] != '\n')
		i++;
	cleaned->stash = malloc(strlen(last->stash) - i + 1);
	if (!cleaned->stash)
		return (NULL);
	if (last->stash[i] && last->stash[i] == '\n')
		i++;
	j = 0;
	while (last->stash[i])
		cleaned->stash[j++] = last->stash[i++];
	cleaned->stash[j] = 0;
	ft_lstclear(stow);
	stow = NULL;
	ft_lstadd_back(&stow, cleaned);
	return (stow);
}

char	*get_next_line(int fd)
{
	static t_list *stow;
	char *l_read;

	stow = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reading_file(fd, &stow);
	l_read = get_line(stow);
	stow = cleaning_list(stow);
	return (l_read);
}