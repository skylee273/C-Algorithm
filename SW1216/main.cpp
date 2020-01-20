#include <cstdio>
#include <vector>

using namespace std;
const int col = 100;
const int row = 100;
vector<vector<char>> v;
int answer;

bool palindrome(int len) {
	for (int s = 0; s < 100 - len +1; ++s) {
		for (int i = 0; i < col; ++i) {
			int flag = true;
			for (int j = 0; j < len / 2; ++j) {
				if (v[i][j + s] != v[i][s + len - 1 - j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				answer = len;
				return true;
			}
			flag = true;
			for (int j = 0; j < len / 2; ++j) {
				if (v[j + s][i] != v[s + len - 1 - j][i]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				answer = len;
				return true;
			}
		}
	}
	return false;

}

int main() {
	int num;
	for (int testCase = 1; testCase <= 10; ++testCase) {
		scanf("%d", &num);
		v.assign(col, vector<char>(row, 0));
		for (int i = 0; i < col; ++i)
			for (int j = 0; j < row; ++j)
				scanf(" %c", &v[i][j]);

		for (int i = col; i >= 0; --i)
			if (palindrome(i)) {
				printf("#%d %d\n", num, answer);
				answer = 0;
				break;
			}
		v.clear();

	}
	return 0;
}