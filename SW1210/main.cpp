#include <cstdio>
#include <vector>

using namespace std;
#define ROW 100
#define COL 100
const int dx[] = { 1,-1, 0 };
const int dy[] = { 0, 0, -1 };
vector<vector<int>> arr;
int answer = 0;

int getStartX() {
	int startX = -1;
	for (int j = 0; j < ROW; ++j) {
		if (arr[ROW - 1][j] == 2)
			return j;
	}
	return startX;
}
bool checkNeighbor(int x, int y) {
	if (x < 0 || x >= ROW || y < 0 || y >= COL)
		return false;
	return true;
}
void getX(int x, int y) {
	if (y == 0)
		answer = x;
	for (int k = 0; k < 3; ++k) {
		if (checkNeighbor(x + dx[k], y + dy[k])) {
			if (arr[y + dy[k]][x + dx[k]] == 1) {
				arr[y][x] = 3;
				getX(x + dx[k], y + dy[k]);
				break;
			}
		}
	}
}
int main() {
	int num;

	for (int testCase = 0; testCase < 10; ++testCase) {
		arr.assign(COL, vector<int>(ROW, 0));
		scanf("%d", &num);
		for (int i = 0; i < COL; ++i) {
			for (int j = 0; j < ROW; ++j)
				scanf("%d ", &arr[i][j]);
		}
		getX(getStartX(), 99);
		printf("#%d %d\n", num, answer);
		answer = 0;
		arr.clear();
	}
}