#include <gtest/gtest.h>

// Death tests are tests that check for program termination (DEATH) under certain conditions.
// They are useful for testing error handling and ensuring that your code behaves as expected in exceptional situations.

// They are usually run before other tests, and they can be run in a separate process to avoid affecting the main test suite.

// Traditionally expected behaviour in Death tests is PROGRAM DEATH
// BUT we can also use them to check for specific error messages OR for testing programs/functions that are prone to SEGFAULTs/CRASHes safely


// Normally function crashing causes the whole test suite to crash
// But with Death tests, we can isolate the crash and check for it without affecting the rest of the tests

// All death tests must end with `DeathTest` in their name

TEST(Ex03DeathTest, death) {
	// The simplest death test is to check for any type of crash/death (segfault)

	ASSERT_DEATH(exit(1), "");
	// This test will pass if the program exits with a non-zero status (indicating a crash or error)
	// You can pass it a simple function

	ASSERT_DEATH({
		const char *ptr = nullptr;

		const int i = strlen(ptr);

		exit(i);
	}, "");
	// Or you can pass it a block of code (like above) that will cause a crash

	// When creating blocks of code you can use `exit` function to exit the block early, or force return of a given value
	ASSERT_DEATH({
		const char *ptr = nullptr;

		if (ptr == nullptr) {
			exit(1); // exit the block early if ptr is null
		}

		const int i = strlen(ptr);

		exit(i);
	}, "");
}

TEST(Ex03DeathTest, exit) {
	// But what if we want more specific control?

	// Maybe we want to check if the program doesn't crash
	// Or maybe we want to check if the program exits with a specific exit code

	// We can use `ASSERT_EXIT` to check the exit agains a set of predicates

	// The simplest predicate is `ExitedWithCode` which checks if the program exited with a specific exit code
	ASSERT_EXIT(exit(1), ::testing::ExitedWithCode(1), "");

	// We can also check for specific signals (like SIGSEGV for segfaults)
	ASSERT_EXIT({
		const char *ptr = nullptr;

		const int i = strlen(ptr);

		exit(i);
	}, ::testing::KilledBySignal(SIGSEGV), "");
}

TEST(Ex03DeathTest, matcher) {
	// We can also check for specific output to stderr (or stdout)
	// This is useful for checking error messages or logging output

	// You can use matchers/RegEx to check for specific error messages

	// Complete the following test

	ASSERT_EXIT({
		fprintf(stderr, "Error: Something went wrong\n");

		exit(1);
	}, ::testing::ExitedWithCode(1), "Error: Something went wrong\n");
}

TEST(Ex03DeathTest, shenanigans) {
	// You can use `ASSERT_EXIT` as a safer `ASSERT_EQ`

	ASSERT_EXIT({
		const char *ptr = "String";

		const int res = strlen(ptr);

		exit(res);
	}, ::testing::ExitedWithCode(6), "");
}
