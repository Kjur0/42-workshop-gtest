#include <gtest/gtest.h>
#include "ex02.hpp"

// There are several types of assertions that can be used in unit tests.

// Let's create some tests for a few functions

TEST(ex02, integers) {
	// Integers are the basic types in C++ (`int`, `char`, etc.)
	// They can be asserted by using simple comparisons (`==`, `!=`, `<`, `>`, `<=`, `>=`)


	// Complete the TEST with appropriate `ASSERT_*`

	// function `int_equal` should always return a value that is equal to the input value
	ASSERT_(int_equal(42), 42);

	// function `char_not_equal` should always return a value that is not equal to the input value
	ASSERT_(char_not_equal('a'), 'a');

	// function `long_greater` should always return a value that is greater than the input value
	ASSERT_(long_greater(42), 42L);

	// function `float_less_or_equal` should always return a value that is less than or equal to the input value
	ASSERT_(int_less_or_equal(42), 42.);

	// function `double_greater_or_equal` should always return a value that is greater than or equal to the input value
	ASSERT_(int_greater_or_equal(42), 42);

	// function `long_long_less` should always return a value that is less than the input value
	ASSERT_(long_long_less(42), 42ll);
}

TEST(ex02, booleans) {
	// Booleans are a type that can only have two values: `true` or `false`.
	// They can be assert by using `ASSERT_TRUE` and `ASSERT_FALSE`

	// Complete the TEST with appropriate `ASSERT_*`

	// function is_even should return `true` if the input value is even, and `false` otherwise
	ASSERT_(is_even(42));

	// function is_odd should return `true` if the input value is odd, and `false` otherwise
	ASSERT_(is_odd(42));
}

TEST(ex02, pointers) {
	// Pointers are variables that store the memory address of another variable.
	// They can be assert by using simple comparisons (`==`, `!=`, `<`, `>`, `<=`, `>=`)

	// remember pointer values are random, so you need to check if they exist (are not `nullptr`/`0`)
	// you can use boolean assertions to check if a pointer is `nullptr` or not. Or you can play with `==`/`!=`

	// ALWAYS when writing tests on pointers be thinking: "should this pointer exist or not?" and "should this pointer be equal to another pointer or not?"
	// when dealing with pointers, you should also check if the pointer is pointing to the right value (dereference it and check the value)
	// BUT REMEMBER to always check if the pointer is not `nullptr` before dereferencing it, otherwise you will get a segmentation fault and your test will crash.

	// Complete the TEST with appropriate `ASSERT_*` (whatever you prefer)

	// function `give_me_a_pointer` should always return a pointer to an integer with a value of `42`
	int *ptr = give_me_a_pointer();
	ASSERT_//???
	ASSERT_EQ(*ptr, 42);

	// ALWAYS remember to FREE any memory allocated either before or during the test
	free(ptr);
	// if you like you can use C++ `delete` keyword, but as 42 teaches C I'm gonna use `free` here
	// remember any C code is able to be used in C++ code, all C code is automatically C++ code

	// function `dont_give_me_a_pointer` should always return a `nullptr`
	ASSERT_//???
}

TEST(ex02, strings) {
	// Strings are a type that can store a sequence of characters.
	// `gtest` has a special assertion for strings (`ASSERT_STR*`)

	// Complete the TEST with appropriate `ASSERT_STR*`

	// function `ping` should always return a string that is equal to "pong"
	ASSERT_STR(ping(), "pong");

	// function `pong` should never return a string that is equal to "ping"
	ASSERT_STR(pong(), "ping");

	// function `hello` should always return a string that is equal to "world" (but it may have a different case)
	ASSERT_STR(hello(), "world");

	// function `world` should never return a string that is equal to "hello" (but it may have a different case)
	ASSERT_STR(world(), "hello");
}


TEST(ex02, floats) {
	// Floats are a type that can store decimal numbers.
	// They can be assert by using simple comparisons (`==`, `!=`, `<`, `>`, `<=`, `>=`)
	// BUT REMEMBER that floats are not always exact, so you should use a tolerance when comparing them. (`ASSERT_FLOAT_*)

	// Complete the TEST with appropriate `ASSERT_*`

	// function `float_equal` should always return a value that is equal to the input value
	ASSERT_(float_equal(42.0f), 42.0f);

	// function `double_not_equal` should always return a value that is not equal to the input value
	ASSERT_(double_not_equal(42.0), 42.0);

	// function `float_greater` should always return a value that is greater than the input value
	ASSERT_(float_greater(42.0f), 42.0f);

	// function `double_less_or_equal` should always return a value that is less than or equal to the input value
	ASSERT_(double_less_or_equal(42.0), 42.0);

	// function `float_greater_or_equal` should always return a value that is greater than or equal to the input value
	ASSERT_(float_greater_or_equal(42.0f), 42.0f);

	// function `double_less` should always return a value that is less than the input value
	ASSERT_(double_less(42.0), 42.0);
}


// There are also assertions for exceptions (C++ feature), HRESULT (Windows), predicates, matchers, custom assertions, or even deaths/exits
// More on these will be covered in the next exercises (except for exceptions and HRESULT, which are not covered in this course)
