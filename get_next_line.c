/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tgrangeo <tgrangeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 13:58:01 by tgrangeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 14:33:10 by tgrangeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int ret;
	static char *stock;
	int i;
	int j;
	
	i = 0;
	j = 0;
	stock = ft_strdup_char("", '\0');
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		printf("ret : %d\nbuf : %s\n", ret, buf);
		stock = ft_strjoin(stock, ft_strdup_char((const char *)buf, '\0'));
		printf("stock : %s\n", stock);
		if (ft_strchr(stock, '\n'))
		{
			*line = ft_strdup_char(stock, '\n');
			stock = ft_strchr(stock, '\n');
		}
		else
		{
			stock = ft_strchr(stock, '\n');
		}
		
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int fd;
	int ret;
	char *str;
	int i;
	
	i = 0;
	if (argc != 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (printf("%s\n", "fd crash"));
		while ((ret = get_next_line(fd, &str)))
		{
			printf("						MAIN = line %d : %s\n", i, str);
			i++;
		}
		close (fd);
		return (0);
	}
}