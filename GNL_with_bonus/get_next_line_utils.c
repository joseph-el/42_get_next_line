/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:41:15 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/01 08:41:09 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strchr(char *str)
{
	if (!str)
		return (0);
	while (*str && *(str) != '\n')
		str++;
	if (*str == '\0' && *(str) != '\n')
		return (NULL);
	return (str);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*str;
	char	*ptr;
	int		len;

	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer)) + 1);
	if (!str)
		return (NULL);
	ptr = str;
	len = 0;
	while (stash[len])
		*str++ = stash[len++];
	while (*buffer)
		*str++ = *buffer++;
	*str = 0;
	free(stash);
	return (ptr);
}

char	*ft_subline(char *stash)
{
	char	*line;
	int		len;
	int		i;

	if (!*stash)
		return (NULL);
	len = (ft_strlen(stash) - ft_strlen(ft_strchr(stash)) + 1);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (stash[++i] && i < len)
		line[i] = stash[i];
	line[i] = 0;
	return (line);
}

char	*cleaning_stash(char *stash)
{
	char	*str;
	char	*ptr;
	int		i;

	if (!ft_strchr(stash))
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	ptr = str;
	if (stash[i] && stash[i] == '\n')
		i++;
	while (stash[i])
		*str++ = stash[i++];
	*str = 0;
	free(stash);
	return (ptr);
}
