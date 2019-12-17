#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

// code 4.9
const int MIN = numeric_limits<int>::min();

int inefficientMaxSum(const vector<int>& A) {
	int N = A.size(), ret = MIN;
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			// A[i..j] 합을 구한다
			int sum = 0;
			for (int k = i; k <= j; ++k)
				sum += A[k];
			ret = __max(ret, sum);
		}
	}
	return ret;
}
int betterMaxSum(const vector<int>& A) {
	int N = A.size(), ret = MIN;
	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int j = i; j < N; ++j) {
			sum += A[j];
			ret = __max(ret, sum);
		}
	}
	return ret;
}
int fastMaxSum(const vector<int>& A, int lo, int hi) {
	if (lo == hi) return A[lo];

	int mid = (lo + hi) / 2;
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >= lo; --i) {
		sum += A[i];
		left = __max(left, sum);
	}
	sum = 0;
	for (int j = mid + 1; j <= hi; ++j) {
		sum += A[j];
		right = __max(right, sum);
	}
	int single = __max(fastMaxSum(A, lo, mid), fastMaxSum(A, mid + 1, hi));

	return __max(left + right, single);
}
int fastestMaxSum(const vector<int> &A) {
	int N = A.size(), ret = MIN, psum = 0;
	for (int i = 0; i < N; ++i) {
		psum = __max(psum, 0) + A[i];
		ret = __max(psum, ret);
	}
	return ret;
}
int main() {
	return 0;
}