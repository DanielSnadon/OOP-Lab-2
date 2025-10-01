#include <gtest/gtest.h>
#include "../include/three.h"

TEST(Task2Tests, InitializerListAndStringConstructor) {
    Three num{'1', '2', '0'};
    Three expected("120");
    EXPECT_TRUE(num.equals(expected));
}

TEST(Task2Tests, StringAndFillingConstructor) {
    Three num(2, 2);
    Three expected("22");
    EXPECT_TRUE(num.equals(expected));
}

TEST(Task2Tests, StringConstructorInvalid) {
    EXPECT_THROW(Three num("312"), std::invalid_argument);
}

TEST(Task2Tests, Equals) {
    Three num1("12");
    Three num2("12");
    Three num3("21");
    
    EXPECT_TRUE(num1.equals(num2));
    EXPECT_FALSE(num1.equals(num3));
}

TEST(Task2Tests, GreaterThan) {
    Three num1("21");
    Three num2("12");
    
    EXPECT_TRUE(num1.greaterThan(num2));
    EXPECT_FALSE(num2.greaterThan(num1));
}

TEST(Task2Tests, LessThan) {
    Three num1("12");
    Three num2("21");
    
    EXPECT_TRUE(num1.lessThan(num2));
    EXPECT_FALSE(num2.lessThan(num1));
}


TEST(Task2Tests, Add) {
    Three num1("12");
    Three num2("21");
    Three result = num1.add(num2);
    
    Three expected("110");
    EXPECT_TRUE(result.equals(expected));
}

TEST(Task2Tests, Subtract) {
    Three num1("21");
    Three num2("12");
    Three result = num1.subtract(num2);
    
    Three expected("2");
    EXPECT_TRUE(result.equals(expected));
}

TEST(Task2Tests, SubtractNegativeResult) {
    Three num1("12");
    Three num2("21");
    
    EXPECT_THROW(num1.subtract(num2), std::invalid_argument);
}