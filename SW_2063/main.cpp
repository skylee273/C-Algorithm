#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	vector <int> v;

	scanf("%d", &N);
	if (N < 9 || N > 199)
		return 0;
	if (N % 2 == 0)
		return 0;
	for (int i = 0; i < N; ++i) {
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	printf("%d", v[(N / 2)]);
	return 0;
}