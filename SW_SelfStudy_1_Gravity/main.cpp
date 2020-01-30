#include <cstdio>
#include <vector>

using namespace std;

int testCase;
int max = 0;
vector <vector<int>> v;
vector<int> h;
int maxHeight() {
	while (!h.empty()) {
		int height = h.back();
		h.pop_back();
		int cnt = 0;
		for (int i = height; i > 0; --i) {
			if (v[i][height] == 0)
				cnt++;
		}
		if (max <= cnt)
			max = cnt;
	}
	return max;
}
int main() {
	scanf(" %d", &testCase);

	for (int t = 1; t <= testCase; ++t) {
		int N, M;
		scanf(" %d %d", &N, &M);
		// 배열 초기화
		v.assign(100, vector<int>(100, 0));
		// box 채우기
		for (int i = 0; i < N; ++i) {
			int height;
			scanf(" %d", &height);
			if (height != 0) {
				h.push_back(height);
				for (int j = 0; j < height; ++j) {
					v[i][j] = 1;
				}
			}
		}
		printf("#%d %d\n", t, maxHeight());
		v.clear();
		h.clear();
	}
	return 0;
}