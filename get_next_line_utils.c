/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thomasgrangeon <thomasgrangeon@student.    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 12:07:37 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 19:56:04 by thomasgrang ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strndup(const char *s, int len)
{
	int i;
	char *dup;

	i = 0;
	if (!(dup = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] && i <= len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*char		*ft_strjoin(char const *s1, char const *s2)
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
		while (s1[i + 1])
		{
			str[j] = s1[i];
			j++;
			i++;
		}
		i = 0;
		free((void *)s1);
		while (s2[i])
		{
			str[j++] = s2[i++];
		}
		str[j] = '\0';
		return (str);
	}
	return (0);
}*/

static int		ft_lent(char *s1, char *s2)
{
	int len;

	len = (ft_strlen(s1)) + (ft_strlen(s2));
	return (len);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			i;
	int			j;
	int			len;

	if (s1 && s2)
	{
		len = ft_lent(((char *)s1), ((char *)s2));
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
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

int			ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (i);
}


char	*ft_substr(char const *s, int start, int len)
{
	int	i;
	char	*dest;

	if (!(s))
		return (NULL);
	if (!(dest = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
	{
		dest[i] = '\0';
		return (dest);
	}
	while (i < len && s[start])
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
