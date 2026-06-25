#include <gtest/gtest.h>

// You might want to include header file from C...
// But it might not compile unless you tell the compiler to treat it as C code

extern "C" {
	// if you use C++ keywords in your header (like `new`, `delete`, `class`, etc.) you will get a compilation error, because C does not know about these keywords
	// you can fix it by using the preprocessor directive `#define`
	#define new n
	#include <libft.h>

	// remember `#undef`
	#undef new
}

// Write you own test for the function `ft_isalpha` here
TEST(ft_isalpha, BasicTests) {
	EXPECT_TRUE(ft_isalpha('a'));
}
