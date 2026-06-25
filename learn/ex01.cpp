#include <gtest/gtest.h>

// Let's create a simple test to check if the gtest framework is working correctly

// The TEST macro takes two arguments: the test suite name (e.g. function) and the test name (e.g. test_case)
TEST(ex01, test) {
	// Unit tests are basically comparisons between two values/behaviours:
	//  1. EXPECTED VALUE - what should happen, what is correct
	//  2. ACTUAL VALUE - what actually happened, what is returned by the function

	// Unit tests are made of 3 parts: (using the `AAA` pattern)


	// 1. Arrange: set up the conditions for the test
	const int a = 1;
	const int b = 1;

	// 2. Act: perform the action that you want to test
	const int result = a + b;

	// 3. Assert: check if the result is what you expect
	// The `EXPECT_*` macros are used to check if the result is what you expect
	// Complete the following line to check if the result is equal to 2
	EXPECT_EQ();
}
