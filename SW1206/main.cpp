#include <cstdio>
#include <vector>

using namespace std;

int main() {

	int width;
	int height;
	vector<int> v;
	vector<vector<int>> arr; // arr 이중 벡터 선언
	for (int num = 1; num <= 10; ++num) {
		int cnt = 0;
		scanf("%d", &width);
		arr.assign(width, vector<int>(255, 0));
		// 1로 채워주는 부분
		for (int i = 0; i < (width); ++i) {
			scanf("%d ", &height);
			v.push_back(height);
			v.push_back(i);
			for (int j = 0; j < height; ++j) {
				arr[i][j] = 1;
			}
		}
		while (!v.empty()) {
			int i = v.back();
			v.pop_back();
			int j = v.back();
			v.pop_back();
			for (int k = j-1; k >= 0; --k) {
				if (arr[i - 1][k] == 1) continue;
				if (arr[i + 1][k] == 1) continue;
				if (arr[i - 2][k] == 1) continue;
				if (arr[i + 2][k] == 1) continue;
				cnt++;
			}
		}
		printf("#%d %d\n", num, cnt);
		arr.clear();
		v.clear();
	}
	
	return 0;
}