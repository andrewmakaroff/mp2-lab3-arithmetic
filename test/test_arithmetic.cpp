// тесты для вычисления арифметических выражений



#include <gtest.h>
#include "arithmetic.h"

TEST(arithmetic, check_operators_priority1) {
	EXPECT_EQ(2, arithmetic::operators_priority('+'));
}

TEST(arithmetic, check_operators_priority2) {
	EXPECT_EQ(2, arithmetic::operators_priority('-'));
}

TEST(arithmetic, check_operators_priority3) {
	EXPECT_EQ(1, arithmetic::operators_priority('*'));
}

TEST(arithmetic, check_operators_priority4) {
	EXPECT_EQ(1, arithmetic::operators_priority('/'));
}

TEST(arithmetic, check_delete_spaces) {

	arithmetic test("    1          +         3");
	EXPECT_EQ("1+3", test.delete_spaces());
}

TEST(arithmetic, check_constructor) {
	ASSERT_NO_THROW(arithmetic test("    1          +         3"));
}

TEST(arithmetic, check_is_dot1) {
	ASSERT_TRUE(arithmetic::is_dot('.'));
}

TEST(arithmetic, check_is_dot2) {
	ASSERT_FALSE(arithmetic::is_dot('+'));
}

TEST(arithmetic, check_is_dot3) {
	ASSERT_FALSE(arithmetic::is_dot('/'));
}

TEST(arithmetic, check_is_dot4) {
	ASSERT_FALSE(arithmetic::is_dot('-'));
}

TEST(arithmetic, check_is_dot5) {
	ASSERT_FALSE(arithmetic::is_dot('*'));
}

TEST(arithmetic, check_is_digit1) {
	ASSERT_TRUE(arithmetic::is_digit('4'));
}

TEST(arithmetic, check_is_digit2) {
	ASSERT_FALSE(arithmetic::is_digit('a'));
}

TEST(arithmetic, check_is_digit3) {
	ASSERT_FALSE(arithmetic::is_digit('+'));
}

TEST(arithmetic, check_is_digit4) {
	ASSERT_FALSE(arithmetic::is_digit('A'));
}

TEST(arithmetic, check_is_digit5) {
	ASSERT_FALSE(arithmetic::is_digit('!'));
}
TEST(arithmetic, check_convert1) {
	arithmetic test("    1          +         3");
	EXPECT_EQ("1 3 + ", test.convert());
}

TEST(arithmetic, check_convert2) {
	arithmetic test("(1 + 2) /  3");
	EXPECT_EQ("1 2 + 3 / ", test.convert());
}

TEST(arithmetic, check_convert3) {
	arithmetic test("(2+6)");
	EXPECT_NE("+ 2 6", test.convert());
}

TEST(arithmetic, test_compute1) {
	arithmetic test("    1          +         3");
	std::string expr_after_transforming = test.convert();
	EXPECT_EQ(4, test.compute(expr_after_transforming));
}

TEST(arithmetic, test_compute2) {
	arithmetic test("-11.3");
	std::string expr_after_transforming_1 = test.convert();
	EXPECT_EQ(-11.3, test.compute(expr_after_transforming_1));
}

TEST(arithmetic, test_compute3) {
	arithmetic test("(((1 + 1) * 1 + 1) * 1 + 1) + 1");
	std::string expr_after_transforming_2 = test.convert();
	ASSERT_NEAR(test.compute(expr_after_transforming_2), 5.0, 1e-15);
}

TEST(arithmetic, test_compute4)
{
	arithmetic test("  5   * (6 + 25)");
	test.delete_spaces();
	std::string expr_after_transforming = test.convert();
	EXPECT_EQ(155, test.compute(expr_after_transforming));
}

TEST(arithmetic, test_compute5)
{
	arithmetic test = "5.6* 5.7/8";
	test.delete_spaces();
	std::string expr_after_transforming = test.convert();
	ASSERT_NEAR(test.compute(expr_after_transforming),4.0,0.1);
}

TEST(arithmetic, is_correct1) {
	arithmetic test("2+2");
	ASSERT_TRUE(test.is_expression_is_correct("2+2").empty());
}

TEST(arithmetic, is_correct2) {
	arithmetic test("2+(*2)");
	ASSERT_FALSE(test.is_expression_is_correct("2+(*2)").empty());
}

TEST(arithmetic, is_correct3) {
	arithmetic test("2+(2.3.4*2)");
	ASSERT_FALSE(test.is_expression_is_correct("2+(2.3.4*2)").empty());
}

TEST(arithmetic, is_correct4) {
	arithmetic test("2 3");
	ASSERT_FALSE(test.is_expression_is_correct("2 3").empty());
}

