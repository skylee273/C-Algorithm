#include <cstdio>
#include <vector>

using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1,  0, -1 };
int arr[5][5] = { 0, };
int sortArr[5][5] = { 0, };
int n, m;

int sel_min() {
	int min = arr[0][0];
	int minX = 0;
	int minY = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (min > arr[i][j]) {
				min = arr[i][j];
				minX = j;
				minY = i;
			}
		}
	}
	arr[minY][minX] = 26;
	return min;
}
void matrixSort() {

	int X, Y;
	int newX  = 0, newY = 0;
	int dir_stat = 0;
	for (int i = 0; i < 25; ++i) {
		int cur_min = sel_min();
		X = newX;
		Y = newY;
		sortArr[Y][X] = cur_min;
		newX = X + dx[dir_stat];
		newY = Y + dy[dir_stat];

		if (sortArr[newY][newX] != 0 || newX > 4 || newY > 4) {
			dir_stat = (dir_stat + 1) % 4;
			newX = X + dx[dir_stat];
			newY = Y + dy[dir_stat];
		}
	}
}
int main() {

	scanf(" %d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf(" %d", &arr[i][j]);
		}
	}
	matrixSort();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", sortArr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
