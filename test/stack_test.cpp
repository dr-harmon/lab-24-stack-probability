#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "stack.h"

using namespace std;

TEST_CASE("Stack elements can be pushed and popped")
{
    Stack<int> s(10);
    REQUIRE(s.getSize() == 0);
    REQUIRE(s.isEmpty());
    s.push(1);
    REQUIRE(s.top() == 1);
    REQUIRE(s.getSize() == 1);
    REQUIRE_FALSE(s.isEmpty());
    s.push(2);
    REQUIRE(s.top() == 2);
    REQUIRE(s.getSize() == 2);
    REQUIRE_FALSE(s.isEmpty());
    s.push(3);
    REQUIRE(s.top() == 3);
    REQUIRE(s.getSize() == 3);
    REQUIRE_FALSE(s.isEmpty());
    REQUIRE(s.pop() == 3);
    REQUIRE(s.top() == 2);
    REQUIRE(s.getSize() == 2);
    REQUIRE_FALSE(s.isEmpty());
    REQUIRE(s.pop() == 2);
    REQUIRE(s.top() == 1);
    REQUIRE(s.getSize() == 1);
    REQUIRE_FALSE(s.isEmpty());
    REQUIRE(s.pop() == 1);
    REQUIRE(s.getSize() == 0);
    REQUIRE(s.isEmpty());
}

TEST_CASE("Accessing the top of an empty stack throws an exception")
{
    Stack<int> s(10);
    REQUIRE_THROWS(s.top());
    s.push(1);
    REQUIRE(s.top() == 1);
    s.pop();
    REQUIRE_THROWS(s.top());
}

TEST_CASE("Pushing onto a full stack throws an exception")
{
    Stack<int> s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    REQUIRE_THROWS(s.push(4));
    REQUIRE(s.getSize() == 3);
}

TEST_CASE("Popping from an empty stack throws an exception")
{
    Stack<int> s(3);
    REQUIRE_THROWS(s.pop());
    REQUIRE(s.getSize() == 0);
}
