#include "catch.hpp"
#include "ExpConverter.hpp"

TEST_CASE( "Test operator", "[InfixConverter]" )
{
    INFO("Hint: parse the validity of arithmatic operator string");
    ExpConverter ec;
    REQUIRE(ec.isOperator("+"));
    REQUIRE(ec.isOperator('+'));
    REQUIRE(ec.isOperator("-"));
    REQUIRE(ec.isOperator('-'));
    REQUIRE(ec.isOperator("*"));
    REQUIRE(ec.isOperator('*'));
    REQUIRE(ec.isOperator("/"));
    REQUIRE(ec.isOperator('/'));
    REQUIRE(ec.isOperator("^"));
    REQUIRE(ec.isOperator('^'));

    REQUIRE_FALSE(ec.isOperator("W"));
    REQUIRE_FALSE(ec.isOperator("WY"));
    REQUIRE_FALSE(ec.isOperator('W'));
}

TEST_CASE("test operand", "[InfixConverter]") {
    ExpConverter ec;
    REQUIRE(ec.isOperand("1"));
    REQUIRE(ec.isOperand("123"));
    REQUIRE_FALSE(ec.isOperand("1se"));

    REQUIRE_FALSE(ec.isNotNumericalOperand("@"));
    REQUIRE(ec.isNotNumericalOperand("4a"));
    REQUIRE_FALSE(ec.isNotNumericalOperand("78"));
}

TEST_CASE("test calculate", "[InfixConverter]") {
    ExpConverter ec;
    REQUIRE(ec.calculate("12", "12", "+") == "24");
    REQUIRE(ec.calculate("12", "12", "-") == "0");
    REQUIRE(ec.calculate("12", "12", "*") == "144");
    REQUIRE(ec.calculate("12", "12", "/") == "1");
    REQUIRE(ec.calculate("12", "2", "^") == "144");

    REQUIRE(ec.calculate("12", "0", "/") == "Undefined");
}

TEST_CASE("test evaluatePostfix", "[InfixConverter]") {
    ExpConverter ec;
    REQUIRE(ec.evaluatePostfix("3 4 * 3 / 7 - 56 30 - +") == "23");
    REQUIRE(ec.evaluatePostfix("7 9 * 5 5 / / 55 98 * + 10 /") == "545.3");
    REQUIRE(ec.evaluatePostfix("5 6 + 14 7 - * 5 /") == "15.4");
}

TEST_CASE("test convertInfix", "[InfixConverter]") {
    ExpConverter ec;
    REQUIRE(ec.convertInfix("(3.5 * 4) / 3 - 7 + (56 - 30)") == "3.5 4 * 3 / 7 - 56 30 - +");
    REQUIRE(ec.convertInfix("((7*9)/(5/5)+55*98)/10") == "7 9 * 5 5 / / 55 98 * + 10 /");
    REQUIRE(ec.convertInfix("(5 + 6) * (14 - 7) / 5") == "5 6 + 14 7 - * 5 /");
    REQUIRE(ec.convertInfix("(a + b) - 5") == "a b + 5 -");
    REQUIRE(ec.convertInfix("a + b * (c ^ d - e) ^ (f + g * h) - i") == "a b c d ^ e - f g h * + ^ * + i -");

    REQUIRE(ec.convertInfix("(12 + 6 * 4 / 5 ").empty());
    REQUIRE(ec.convertInfix("a + b) * c").empty());
    REQUIRE(ec.convertInfix("45 @ 8 + 2").empty());
    REQUIRE(ec.convertInfix("56 / 0 ").empty());
    REQUIRE(ec.convertInfix("(5 * 10) / (6 + 3 - 9)").empty());
    REQUIRE(ec.convertInfix("+ +").empty());
    REQUIRE(ec.convertInfix("/ *").empty());
    REQUIRE(ec.convertInfix("(4 + 6) 7").empty());
}

TEST_CASE("test precedence", "[InfixConverter]") {
    ExpConverter ec;
    REQUIRE_FALSE(ec.precedence('*', '*'));
    REQUIRE_FALSE(ec.precedence('+', '*'));
    REQUIRE_FALSE(ec.precedence('-', '*'));
    REQUIRE_FALSE(ec.precedence('*', '/'));
    REQUIRE_FALSE(ec.precedence('/', '*'));
    REQUIRE_FALSE(ec.precedence('/', '^'));
    REQUIRE(ec.precedence('/', '+'));
    REQUIRE(ec.precedence('^', '*'));
}