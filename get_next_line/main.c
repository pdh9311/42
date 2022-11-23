#include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <stdio.h>

int	g_cnt;

int main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open("gnltest.txt", O_RDWR);
	while ((ret = get_next_line(fd, &line)) > 0)
	{	g_cnt++;
		printf("(%d) %s\n", g_cnt, line);
		free(line);
//		if (g_cnt == 5)		// Read error 유도할 코드
//			close(fd);
	}
	g_cnt++;
	if (ret < 0)
	{
		printf("Read error\n");
	}
	else if (ret == 0)
	{
		printf("(%d) %s\n", g_cnt, line);
		free(line);
	}
	close(fd);
	return (0);
}
