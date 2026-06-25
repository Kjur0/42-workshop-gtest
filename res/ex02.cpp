#include <gtest/gtest.h>
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
int int_equal(int value) {
	return value;
}
char char_not_equal(char value) {
	return value + 1;
}
long long_greater(long value) {
	return value + 1;
}
int int_less_or_equal(int value) {
	return value - 1;
}
int int_greater_or_equal(int value) {
	return value + 1;
}
long long long_long_less(long value) {
	return value - 1;
}
int is_even(int value) {
	return value % 2 == 0;
}
int is_odd(int value) {
	return value % 2 != 0;
}
int* give_me_a_pointer() {
	int* ptr = new int(42);
	return ptr;
}
int* dont_give_me_a_pointer() {
	return nullptr;
}
char* ping() {
	return "pong";
}
char* pong() {
	return "PONG";
}
char* hello() {
	return "wOrLd";
}
char* world() {
	return "GreEtingS";
}
float float_equal(float value) {
	return value;
}
double double_not_equal(double value) {
	return value + 1.0;
}
float float_greater(float value) {
	return value + 1.0f;
}
double double_less_or_equal(double value) {
	return value - 1.0;
}
float float_greater_or_equal(float value) {
	return value + 1.0f;
}
double double_less(double value) {
	return value - 1.0;
}
