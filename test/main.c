#include "../get_next_line.h"
#include "main.h"

int main(void)
{
	char	*str;
	int	fd = open("text/threelines", O_RDWR);
	str = get_next_line(fd);
	free(str);
	str = get_next_line(fd);
	free(str);
	str = get_next_line(fd);
	free(str);
	str = get_next_line(fd);
	free(str);
	close(fd);
	return (0);
}
