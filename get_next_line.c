/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thomasgrangeon <thomasgrangeon@student.    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 13:58:01 by tgrangeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 21:01:14 by thomasgrang ###    #+. /#+    ###.fr     */
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
	//printf("=================FT SCAN =============\n\nn :%d\n\n\n\n", n);
	if (n > 0)
	{
		*line = ft_strndup(*mem, n);
		*mem = ft_substr(*mem, n + 1, size);
		//printf("line :%s\nmem :%s\n", *line, *mem);
		return (1);
	}
	else
		return (0);
}


int		get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int ret;
	static char *mem;

	*line = ft_strndup("", 0);
	if (!mem)
		mem = ft_strndup("", 0);
	if (ft_scan(&mem, line) > 0)
		return(1);
	else
		while ((ret = read(fd, buf, BUFFER_SIZE)))
		{
			buf[ret] = '\0';
			//printf("buf :%s\n", buf);
			mem = ft_strjoin(mem, buf);
			//printf("=================FT GNL =============\n\nmem :%s\n\n\n\n", mem);
			if (ft_scan(&mem, line) > 0)
				return (1);
		}
	return (0);
}

int	main(int argc, char **argv)
{
	int fd;
	int ret;
	char *str;
	int	i;
	
	i = 0;
	if (argc != 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (printf("%s\n", "fd crash"));
		while ((ret = get_next_line(fd, &str)))
		{
			printf("line %d:%s\n", i, str);
			i++;
		}
		close (fd);
		return (0);
	}
}