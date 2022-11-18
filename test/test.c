#include "unity/unity.h"
#include "../get_next_line.h"
#include "main.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_test_txt_should_be_equal(void)
{
	int		fd = open("test.txt", O_RDWR);
	char	*expected;

	expected = "Process 34258 launched:\n";
	TEST_ASSERT_EQUAL_STRING(expected, get_next_line(fd));

	expected = "\n";
	TEST_ASSERT_EQUAL_STRING(expected, get_next_line(fd));

	expected = "Process 34258 stopped\n";
	TEST_ASSERT_EQUAL_STRING(expected, get_next_line(fd));

	expected = NULL;
	TEST_ASSERT_EQUAL_STRING(expected, get_next_line(fd));
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_test_txt_should_be_equal);
	return UNITY_END();
}
