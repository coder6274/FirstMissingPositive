/*
 * main.cpp
 *
 *  Created on: 17 Apr 2018
 *      Author: johnbrady
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

/*
 *expected worst-case time complexity is O(N);
 expected worst-case space complexity is O(N),
 beyond input storage (not counting the storage required for input arguments).
 */

int firstMissingPositive(std::vector<int> &A) {

	int valMin = INT_MAX, valMax = 0;

	/* Locate min and max of the input
	 * Mark the negative values with a special positive value (INT_MAX).
	 */
	for (auto &num : A) {

		if (num > 0) {
			valMin = std::min(valMin, num);
			valMax = std::max(valMax, num);

		} else {
			num = INT_MAX;
		}
	}

	/*Check that the min value is 1 otherwise 1 is the missing value*/
	if (valMin != 1)
		return 1;

	/*loop through the vector. For each VALUE (i.e 4) mark the value at the corresponding index -1
	 * (i.e. value at index 3) to be negative.
	 *
	 * We code information about presence of number as a sign of a number in position A[n-valMin]
	 *
	*/

	for (int &num : A) {

		if (num != 0 and abs(num) != INT_MAX and (unsigned int)num < A.size()) {

			int &val = A[abs(num) - valMin];
			if (val > 0)
				val = -val;
		}
	}

	/*Look for the first positive int in the vector and the corresponding index is the missing value*/

	int index;
	for (unsigned int i = 0; i < A.size(); i++) {
		if (A[i] > 0) {
			index = i;
		}
	}
	return index;

}

int main() {
	std::vector<int> v = { 1, -3, -2, -8, 4, 93 };

	int answer = firstMissingPositive(v);
	std::cout << "The answer is " << answer;
	return 0;
}

