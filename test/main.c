#include "../get_next_line.h"
#include "main.h"

int main(void)
{

	int	fd = open("test/test.txt", O_RDWR);
	// printf("%s\n", get_next_line(fd));
	get_next_line(fd);
	return 0;
}
