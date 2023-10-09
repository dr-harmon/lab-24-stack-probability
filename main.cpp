#include "stack.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

random_device rd;
mt19937 mt(rd());
const int SIZE = 3;
const int RAND_RANGE = 100;

// Fills the array with SIZE unique random numbers from 1 to RAND_RANGE.
void getUniqueRandomNumbers(array<int, SIZE>& a)
{
	uniform_int_distribution<int> dist(1, RAND_RANGE);
	for (int i = 0; i < SIZE; i++) {
		int randomNumber;
		do {
			randomNumber = dist(mt);
		} while (find(a.begin(), a.end(), randomNumber) != a.end());
		a[i] = randomNumber;
	}
}

// Returns the largest number in the given 3-element stack with 2/3
// probability using only one local variable, one comparison, and no
// loops or recursion.
int getLargestNumber(Stack<int>& stack)
{
	int x = stack.pop();
	if (x < stack.top()) {
		x = stack.pop();
	}
	return x;
}

// Generates 3 unique random numbers, places them in a stack, then calls
// getLargestNumber to find the largest number. Returns true if the
// largest number was found successfully, otherwise false.
bool runExperiment()
{
	array<int, SIZE> randomNumbers;
	getUniqueRandomNumbers(randomNumbers);
	int actualLargest = *max_element(randomNumbers.begin(), randomNumbers.end());
	Stack<int> stack(SIZE);
	for_each(randomNumbers.begin(), randomNumbers.end(), [&](int n){ stack.push(n); });
	int experimentalLargest = getLargestNumber(stack);
	return experimentalLargest == actualLargest;
}

// Runs runExperiment the given number of times and returns the fraction
// that passed.
float runExperiments(int numExperiments)
{
	int passed = 0;
	for (int i = 0; i < numExperiments; i++) {
		if (runExperiment()) {
			passed++;
		}
	}
	return (float)passed/numExperiments;
}

int main()
{
	float successRate = runExperiments(1000);
	cout << "Experiments ran with " << round(successRate*100) << "% success rate" << endl;

	return EXIT_SUCCESS;
}
