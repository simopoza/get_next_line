/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:12:01 by mannahri          #+#    #+#             */
/*   Updated: 2021/12/01 01:22:44 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		l;
	int		k;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	l = 0;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	while (l < i)
		str[l++] = s1[k++];
	k = 0;
	while (k < j)
		str[l++] = s2[k++];
	str[l] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	char	*ali;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	ali = s;
	i = 0;
	j = 0;
	while (i < len && s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = ali[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
