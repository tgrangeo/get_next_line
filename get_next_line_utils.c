/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tgrangeo <tgrangeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 12:07:37 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 14:29:22 by tgrangeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strdup_char(const char *s, char c)
{
	int i;
	char *dup;

	i = 0;
	while (s[i] != c)
		i++;
	if (!(dup = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	int i;
	int j;

	if (s1 && s2)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2)))))
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i])
		{
			str[j++] = s1[i++];
		}
		i = 0;
		while (s2[i])
		{
			str[j++] = s2[i++];
		}
		str[j] = '\0';
		return (str);
	}
	return (0);
}

char			*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (!(str[i] == c) && str[i])
	{
		if (i == 0)
			return (0);
		i++;
	}
	return (&str[i]);
}
