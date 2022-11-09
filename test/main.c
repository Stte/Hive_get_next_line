#include "../get_next_line.h"
#include "main.h"

int main(void)
{
	int	fd = open("./test", O_RDONLY);
	get_next_line(fd);
	return 0;
}
