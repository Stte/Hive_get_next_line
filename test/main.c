#include "../get_next_line.h"
#include "main.h"

int main(void)
{
	char	*str;
	// int	fd = open("text/empty", O_RDWR);
	int	fd = open("../gnlTester/files/41_no_nl", O_RDWR);
	str = get_next_line(fd);
	free(str);
	str = get_next_line(fd);
	if(str)
		free(str);
	// str = get_next_line(fd);
	// free(str);
	// str = get_next_line(fd);
	// free(str);
	close(fd);
	return (0);
}
