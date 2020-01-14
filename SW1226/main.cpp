#include <cstdio>
#include <vector>

using namespace std;
const int row = 16;
const int col = 16;
vector <vector<int>>arr;
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };
bool checkNeighbor(int x, int y) {
	if (x < 0 || x >= row || y < 0 || y >= col)
		return false;
	return true;
}
int dfs(int x, int y) {
	// 벽이거나 이미 와본길
	int exit = 0;
	if (arr[y][x] == 1)
		return 0;
	arr[y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		if (checkNeighbor(x + dx[i], y + dy[i])) {
			if (arr[y + dy[i]][x + dx[i]] == 3)
				return 1;
			exit += dfs(x + dx[i], y + dy[i]);
		}
	}
	arr[y][x] = 0;
	return exit;
}
int main() {
	int num;
	for (int testCase = 0; testCase < 10; ++testCase) {
		arr.assign(col, vector<int>(row, 0));
		scanf("%d ", &num);
		for (int i = 0; i < col; ++i) {
			for (int j = 0; j < row; ++j)
				scanf("%1d", &arr[i][j]);
		}
		if (dfs(1, 1) == 1)
			printf("#%d 1\n", num);
		else
			printf("#%d 0\n", num);

		arr.clear();
	}

	return 0;
}