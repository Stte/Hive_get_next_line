#include "../get_next_line.h"
#include "main.h"

int main(void)
{
	char	*str;
	// int	fd = open("text/empty", O_RDWR);
	int	fd = open("../gnlTester/files/41_with_nl", O_RDWR);
	int	fd1 = open("../gnlTester/files/41_with_nl", O_RDWR);
	int	fd2 = open("../gnlTester/files/41_with_nl", O_RDWR);
	int	fd3 = open("../gnlTester/files/multiple_nlx5", O_RDWR);

	str = get_next_line(1000); // NULL
	free(str);
	str = get_next_line(fd); // "0123456789012345678901234567890123456789\n"
	free(str);
	str = get_next_line(1001); // NULL
	free(str);
	str = get_next_line(fd1); // "0123456789012345678901234567890123456789\n"
	free(str);
	str = get_next_line(1002); // NULL
	free(str);
	str = get_next_line(fd2); // "0123456789012345678901234567890123456789\n"
	free(str);
	str = get_next_line(1003); // NULL
	free(str);
	str = get_next_line(fd); // "0"
	free(str);
	str = get_next_line(1004); // NULL
	free(str);
	str = get_next_line(fd1); // "0"
	free(str);
	str = get_next_line(1005); // NULL
	free(str);
	str = get_next_line(fd2); // "0"
	free(str);
	str = get_next_line(fd); // NULL
	free(str);
	str = get_next_line(fd1); // NULL
	free(str);
	str = get_next_line(fd2); // NULL
	free(str);
	str = get_next_line(1006); // NULL
	free(str);
	str = get_next_line(1007); // NULL
	free(str);
	str = get_next_line(fd3); // "\n"
	free(str);

	close(fd);
	close(fd1);
	return (0);
}
