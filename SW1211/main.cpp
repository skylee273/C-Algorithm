#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define ROW 100
#define COL 100
const int dx[] = { 1,-1, 0 };
const int dy[] = { 0, 0, 1 };
vector<vector<int>> arr;
int minStep = 9999;
int step = 0;
bool checkNeighbor(int x, int y) {
	if (x < 0 || x >= ROW || y < 0 || y >= COL)
		return false;
	return true;
}
void getX(int x, int y) {
	step++;
	if (y == 99)
		return;
	for (int k = 0; k < 3; ++k) {
		if (checkNeighbor(x + dx[k], y + dy[k])) {
			if (arr[y + dy[k]][x + dx[k]] == 1) {
				arr[y][x] = 0;
				getX(x + dx[k], y + dy[k]);
				break;
			}
		}
	}
	arr[y][x] = 1;
}

int main() {
	int num;

	for (int testCase = 0; testCase < 10; ++testCase) {
		vector<int> answer;
		minStep = 2e9;
		arr.assign(COL, vector<int>(ROW, 0));
		scanf("%d", &num);
		for (int i = 0; i < COL; ++i) {
			for (int j = 0; j < ROW; ++j)
				scanf("%d ", &arr[i][j]);
		}
		for (int j = 0; j < ROW; ++j) {
			if (arr[0][j] == 1) {
				step = 0;
				getX(j, 0);
				if (step > minStep) continue;
				else if( step < minStep){
					answer.clear();
					minStep = step;
					answer.push_back(j);
				}
				else {
					answer.push_back(j);
				}
			}
		}
		
		printf("#%d %d\n", num, answer.back());
		//answer.clear();
		arr.clear();
	}
}