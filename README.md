# Lab 24: Stack Probability

In this lab, we will solve problem C-5.4 in the textbook, which is restated here:

> Suppose Alice has picked three distinct integers and placed them into a stack S in random order. Write a short, straight-line piece of pseudo-code (with no loops or recursion) that uses only one comparison and only one variable x, yet guarantees with probability 2/3 that at the end of this code the variable x will store the largest of Alice's three integers. Argue why your method is correct.

## Part 1: Stack Implementation

Instead of using the STL `std::stack`, let's write our own. It should be identical to the `ArrayStack` in Example 5.4 in the textbook with the following exceptions:

* Change the name from `ArrayStack` to `Stack`
* Change `size` to `getSize`
* Change `empty` to `isEmpty`
* `pop` returns a copy of the element that was removed
* No `throw` clauses, as this grammar was removed from the C++ standard after the book was written

The underlying implementation can be anything you like. Choose your own data structure (e.g., array, vector, linked list) and private variables as you see fit.

Some unit tests have been provided for you in `stack_test.cpp`. Make sure all of them pass before continuing.

## Part 2: Finding the Largest of Three

Now let's use our stack to solve and verify problem C-5.4.

1. In `main.cpp`, implement `getLargestNumber` to return the largest number of a 3-element stack with 2/3 probability. You may use only one comparison, one local variable, and no loops or recursion.
2. Also in `main.cpp`, there is a framework to determine the success probability of `getLargestNumber` experimentally. Most of the framework is already written, but the `runExperiments` function is empty. Implement `runExperiments` so that it calls `runExperiment` the given number of times, then returns the fraction of those experiments that were successful. For example, if 100 experiments ran, and 50 of them were successful, it should return 0.5.
3. Run `main` and verify that your `getLargestNumber` implementation returns the largest number about 2/3 of the time.
