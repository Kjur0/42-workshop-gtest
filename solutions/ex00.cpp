// Hi, first thing you need is to learning how to use gtest

// To do that you just need to include the headers

#include <gtest/gtest.h>

// You'll always need a main function to run your tests
int main(int argc, char **argv) {
	// Here you need to initialize the gtest framework (remember to pass the arguments to it)

	// Complete the following line to initialize the gtest framework
	::testing::InitGoogleTest(&argc, argv);

	// Finally, you need to run all the tests that you have defined
	return RUN_ALL_TESTS();
}

// Later in this course the main function will be provided for you, so you won't have to write it yourself.
