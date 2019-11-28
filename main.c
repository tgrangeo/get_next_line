#include "get_next_line.h"

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
			printf("%d- %s\n", i, str);
			i++;
			free(str);
		}
		//printf("%d- %s\n", i, str);
		free(str);
		close (fd);
		return (0);
	}
}