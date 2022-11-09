#include "unity/unity.h"
#include "../get_next_line.h"

void setUp(void) {
}

void tearDown(void) {
}

// //#region ft_split
// void test_tf_split_should_be_equal(void)
// {
// 	char	*string = "  	Is th|is a| real 	...| nah";
// 	char	**expected = ((char*[5]){"  	Is th", "is a", " real 	...", " nah", NULL});
// 	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, ft_split(string, '|'), 5);
// }
// //#endregion


int main(void)
{
	UNITY_BEGIN();
	//#region ft_split
	// RUN_TEST(test_tf_split_should_be_equal);
	//#endregion
	return UNITY_END();
}
