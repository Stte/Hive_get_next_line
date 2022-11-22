#include "../get_next_line.h"
#include "main.h"

int main(void)
{
	char	*str;
	// int	fd = open("text/empty", O_RDWR);
	int	fd = open("../gnlTester/files/41_with_nl", O_RDWR);
	int	fd1 = open("../gnlTester/files/multiple_nlx5", O_RDWR);
	str = get_next_line(fd);
	free(str);
	// str = get_next_line(fd);
	// free(str);
	// str = get_next_line(fd);
	// free(str);
	// str = get_next_line(fd);
	// free(str);
	// str = get_next_line(fd);
	// free(str);
	str = get_next_line(fd1);
	free(str);
	str = get_next_line(fd1);
	free(str);
	str = get_next_line(fd1);
	free(str);
	str = get_next_line(fd1);
	free(str);
	str = get_next_line(fd1);
	free(str);
	str = get_next_line(fd1);
	free(str);
	str = get_next_line(fd1);
	free(str);

	close(fd);
	close(fd1);
	return (0);
}
