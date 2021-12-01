/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:05:01 by mannahri          #+#    #+#             */
/*   Updated: 2021/12/01 01:35:23 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_before_line(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	return (ft_substr(str, 0, i + 1));
}

char	*ft_after_line(char *str)
{
	char	*m;
	int		i;
	int		j;

	j = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			m = ft_substr(str, i + 1, j);
			free(str);
			return (m);
		}
		i++;
	}
	free(str);
	return (NULL);
}

char	*ft_read_line(int fd, char *str)
{
	char	*buff;
	int		i;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(str);
		return (NULL);
	}
	i = 1;
	while (!ft_check(str) && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	s = ft_before_line(str[fd]);
	str[fd] = ft_after_line(str[fd]);
	return (s);
}
