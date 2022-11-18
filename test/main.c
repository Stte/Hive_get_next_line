#include "../get_next_line.h"
#include "main.h"

int main(void)
{

	int	fd = open("text/nonewline_long", O_RDWR);
	get_next_line(fd);

	close(fd);
	return (0);
}
