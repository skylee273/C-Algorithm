#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 10 개의 수를 입력 받아, 그 중에서 가장 큰 수를 출력하는 프로그램을 작성하라.

// 함수를 이용한 vector 정렬
int maxNumber(const vector<int>& A) {
	int max = 0;
	for (int i = 0; i < A.size(); ++i) {
		if (max < A[i]) {
			max = A[i];
		}
	}
	return max;
}
int main() {
	int testCase;
	vector<int> v(10);
	scanf("%d", &testCase);
	for (int j = 1; j <= testCase; ++j) {
		for (int i = 0; i < 10; ++i) {
			int val;
			scanf("%d", &val);
			v.push_back(val);
		}
		//sort(v.begin(), v.end());
		//printf("#%d %d \n", j, v.back());
		
		printf("#%d %d \n",j, maxNumber(v));
		v.clear();
	}
	return 0;
}