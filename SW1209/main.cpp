#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector <vector<int>> v;
	vector<int> answer;

	for (int testCase = 1; testCase <= 10; testCase++) {
		int num;
		scanf("%d", &num);
		int sum = 0;
		v.assign(100, vector<int>(100, 0));
		for (int i = 0; i < 100; ++i) {
			for (int j = 0; j < 100; ++j)
				scanf("%d ", &v[i][j]);
		}

		// 행의 합
		for (int i = 0; i < 100; ++i) {
			sum = 0;
			for (int j = 0; j < 100; ++j)
				sum += v[i][j];
			answer.push_back(sum);
			
		}
		// 열의 합

		for (int j = 0; j < 100; ++j) {
			sum = 0;
			for (int i = 0; i < 100; ++i)
				sum += v[i][j];
			answer.push_back(sum);
		}
		// 오른쪽 대각선
		sum = 0;
		for (int i = 0; i < 100; ++i)
			sum += v[i][i];
		answer.push_back(sum);

		// 왼쪽 대각선
		sum = 0;
		for (int i = 0; i < 100; ++i)
			sum += v[i][99 - i];
		answer.push_back(sum);

		int max = *max_element(answer.begin(), answer.end());
		printf("#%d %d\n", num, max);
		answer.clear();
		v.clear();
	}
	return 0;
}