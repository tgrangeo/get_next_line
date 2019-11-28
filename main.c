#include "get_next_line.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;
	char *str;
	int	i;
	
	i = 0;
	if (argc != 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (printf("-1"));
		while (get_next_line(fd, &str) > 0)
		{
			printf("%d- %s\n", i, str);
			i++;
			free(str);
		}
		printf("%d- %s\n", i, str);
		free(str);
		close (fd);
		return (0);
	}
}