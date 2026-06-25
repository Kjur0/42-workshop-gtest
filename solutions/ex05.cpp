#include <gtest/gtest.h>

TEST(whatever, tests) {
	// There are two types of assertions: `EXPECT` and `ASSERT`

	// `EXPECT` will continue the test even if the assertion fails
	EXPECT_EQ(1, 1); // This will pass
	EXPECT_NE(1, 2); // This will fail, but the test will continue
	EXPECT_EQ(2, 2); // This will pass

	// `ASSERT` will stop the test if the assertion fails
	ASSERT_EQ(1, 1); // This will pass
	ASSERT_NE(1, 2); // This will fail, and the test will stop here
	ASSERT_EQ(2, 2); // This will not be executed because the previous assertion failed
}

TEST(whatever, more_tests) {
	// You can also use `EXPECT_TRUE` and `ASSERT_TRUE` for boolean expressions (or any other type of assertion)
	EXPECT_TRUE(1 == 1); // This will pass
	EXPECT_FALSE(1 == 2); // This will fail, but the test will continue
	ASSERT_TRUE(1 == 1); // This will pass
}

TEST(whatever, when_to_use) {
	// Use `EXPECT` when you want to continue the test even if the assertion fails
	// So when you want to test few cases in one test
	// And when if one case fails, you still want to see the results of the other cases

	const int a = 1;
	const int b = atoi("2");

	EXPECT_NE(a, b);

	const int c = 2;

	EXPECT_EQ(b, c);

	// Use `ASSERT` when you want to stop the test if the assertion fails
	// So when you want to test a precondition for the rest of the test
	// Like checking if a pointer is not null before dereferencing it

	int *ptr = (int *)calloc(1, sizeof(int));
	ASSERT_TRUE(ptr); // if this fails, the test will stop here and the next line will not be executed
	EXPECT_EQ(*ptr, 0);

	free(ptr);
}

// fix above test to PASS
