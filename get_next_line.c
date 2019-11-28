/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tgrangeo <tgrangeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 13:58:01 by tgrangeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 19:31:11 by tgrangeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int		ft_scan(char **mem, char **line)
{
	int n;
	int size;

	n = ft_strchr(*mem, '\n');
	size = ft_strlen(*mem) - n - 1;
	if (n == 0)
	{
		if ((*line = ft_strndup("", 0)) == NULL)
			return (-1);
		if ((*mem = ft_substr(*mem, 1, size)) == NULL)
			return (-1);
		return (1);
	}
	else if (n > 0)
	{
		if ((*line = ft_strndup(*mem, n)) == NULL)
			return (-1);
		if ((*mem = ft_substr(*mem, n + 1, size)) == NULL)
			return (-1);
		return (1);
	}
	return (-1);
}


int		get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int ret;
	static char *mem;

	if (fd < 0)
		return (-1);
	if (!mem)
		mem = ft_strndup("", 0);
	if (ft_scan(&mem, line) > 0)
		return(1);
	else
		while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[ret] = '\0';
			mem = ft_strjoin(mem, buf);
			if (ft_scan(&mem, line) > 0)
				return (1);
			else
				return (-1);
		}
	if (ret == 0)
	{
		if ((*line = ft_strdup(mem)) == NULL)
			return (-1);
		free(mem);
	}
	return(0);
}
