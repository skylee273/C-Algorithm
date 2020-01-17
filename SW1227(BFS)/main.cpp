#include <cstdio>
#include <queue>

using namespace std;

const int col = 100;
const int row = 100;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
int arr[100][100] = { 0, };
struct point
{
	int x;
	int y;
};

bool checkNeighbor(int x, int y) {
	if (x < 0 || x >= row || y < 0 || y >= col)
		return false;
	return true;
}
bool bfs(int x, int y) {
	queue<point> q;
	q.push({ x,y });
	while (!q.empty()) {
		int _x = q.front().x;
		int _y = q.front().y;
		q.pop();
		arr[_y][_x] = 1;
		for (int i = 0; i < 4; ++i) {
			int newX = _x + dx[i];
			int newY = _y + dy[i];
			if (checkNeighbor(newX, newY)) {
				if (arr[newY][newX] == 3)
					return true;
				if (arr[newY][newX] == 0)
					q.push({ newX, newY });
			}
		}
	}
	return false;
}
int main() {
	int num;
	for (int testCase = 0; testCase < 10; testCase++) {
		scanf("%d", &num);
		for (int i = 0; i < col; ++i) {
			for (int j = 0; j < row; ++j)
				scanf("%1d", &arr[i][j]);
		}

		if (bfs(1, 1))
			printf("#%d 1\n", num);
		else
			printf("#%d 0\n", num);
	}
	return 0;
}