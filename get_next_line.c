/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tgrangeo <tgrangeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 13:58:01 by tgrangeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 14:59:51 by tgrangeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

/*char	*ft_separation(char *buf, char **line, int n)
{
	char *str;

	str = ft_strndup("", 0);
	if ( n != 0)
	{
		*line = ft_strndup(buf, n);
		str = ft_substr(buf, n + 1, ft_strlen(buf));
	}
	else
		str = ft_strndup(buf, ft_strlen(buf));
	return(str);
}*/


int		get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int ret;
	static char *mem;
	int n;

	if (!mem)
	{
		mem = ft_strndup("", 0);
		*line = ft_strndup("", 0);
	}
	n = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		n = ft_strchr(buf, '\n');
		if(mem == NULL)
			mem = ft_strndup("", 0);
		if ( n != 0)
		{
			*line = ft_strjoin(mem, ft_strndup(buf, n));
			printf("line :%s\n", *line);
			mem = ft_substr(buf, n + 1, ft_strlen(buf));
		}
		else
			mem = ft_strndup(buf, ft_strlen(buf));
		printf("n:%d\nbuf:%s\nmem:%s\n", n, buf, mem);
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
			printf("						MAIN = line %d:%s\n", i, str);
			i++;
		}
		close (fd);
		return (0);
	}
}