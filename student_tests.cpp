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

    REQUIRE(ec.isNotNumericalOperand("a"));
    REQUIRE(ec.isNotNumericalOperand("4a"));
    REQUIRE_FALSE(ec.isNotNumericalOperand("78"));
}

TEST_CASE("test calculate", "[InfixConverter]") {
    ExpConverter ec;
    REQUIRE(std::stod(ec.calculate("12", "12", "+")) == (double)24);
    REQUIRE(std::stod(ec.calculate("12", "12", "-")) == (double)0);
    REQUIRE(std::stod(ec.calculate("12", "12", "*")) == (double)144);
    REQUIRE(std::stod(ec.calculate("12", "12", "/")) == (double)1);
    REQUIRE(std::stod(ec.calculate("12", "2", "^")) == (double)144);

    REQUIRE(ec.calculate("12", "0", "/") == "Undefined");
}