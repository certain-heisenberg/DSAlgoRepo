/**
 * January 2013 Long Challenge at Codechef
 *
 * Problem:     LEALCO - Little Elephant and Alcohol
 * Author:      Anton Lunyov (Tester and Editorialist)
 * Complexity:  O(2^N * K) per test
 * Timing:      0.00 out of 1.00
 *
 * Description:
 * We recursively consider each element of the array
 * and at first not touch it and then increase by 1,
 * in both cases we check whether the sub-array of length K
 * ending on this element (if any) has >=M maximum elements
 * and if no then recursively pass to the next element.
 * We maintain the number of increased elements in recursion
 * and stop the branch of the recursion
 * if this number is not less than the current answer.
 * The terminal point of the recursion is reaching the end of the array
 * where we update the answer
 */
#include <iostream>
using namespace std;

int N, K, M;
int R[17];
int res;

// i is the position in the array that we consider now
// num is number of increased elements
void backtracking(int i, int num)
{
	// it means that we already use >=res operations,
	// so we can't improve the answer 
	if (res <= num) {
		return;
	}

	// we reach the end of the array successfully
	if (i == N) {

		// hence we update the answer and exit
		res = num;
		return;
	}

	// add = 0 means we not touch R[i]
	// add = 1 means we apply operation to R[i]
	for (int add = 0; add < 2; ++add) {

		// add 'add' to R[i]
		R[i] += add;

		// cnt is the number of maximum elements among
		// R[i-K+1], R[i-K+2], ..., R[i-1], R[i] if all of them exist
		int cnt = 0;

		// if i < K-1 then we have no sub-array of length K ending at R[i]
		if (i >= K - 1) {

			// we can find maximum and the number of its occurrences in one loop
			int maxR = 0;
			for (int j = i; j > i - K; --j) {
				if(maxR == R[j]) {
					++cnt;
				} else if (maxR < R[j]) {
					maxR = R[j];
					cnt = 1;
				}
			}
		}

		// if cnt >= M then elephants will be arrested and we can't continue;
		if (cnt < M) {
			backtracking(i + 1, num + add);
		}

		// subtract 'add' to R[i] to restore its initial state
		R[i] -= add;
	}
}

int main() {
	// input number of tests
	int T;
	cin >> T;

	// loop over tests
	for (int t = 0; t < T; ++t) {

		// input numbers N, K, M and array R[i]
		// they are all declared globally
		cin >> N >> K >> M;
		for (int i = 0; i < N; ++i) {
			cin >> R[i];
		}

		// we init res by N + 1 since it is strictly larger
		// than the size of any subset
		// res is declared globally
		res = N + 1;

		// recursive routine that find the answer
		backtracking(0, 0);

		// we adjust result to conform the output format
		// res equals N+1 if we did not find any proper subset
		// hence we should set the answer to -1 in this case
		if (res == N + 1) {
			res = -1;
		}

		// output the result
		cout << res << endl;
	}
}
