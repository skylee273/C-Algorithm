#include <cstdio>
#include <vector>

using namespace std;
const int row = 8;
const int col = 8;
vector<vector<char>> v;
int answer = 0;

int palindrome(int len) {
	
	for (int s = 0; s < 8 - len + 1; ++s) {
		for (int i = 0; i < col; ++i) {
			bool flag = true;
			// 행으로 검사할때
			for (int j = 0; j < len / 2; ++j) {
				if (v[i][s + j] != v[i][s + len - 1 - j]) {
					flag = false;
					break;
				}	
			}
			if (flag)
				answer++;
			flag = true;
			for (int j = 0; j < len / 2; ++j) {
				if (v[s + j][i] != v[s + len - 1 - j][i]) {
					flag = false;
					break;
				}
			}
			if (flag)
				answer++;
		}
	}
	return answer;
}
int main() {
	int length;
	for (int testCase = 1; testCase <= 10; ++testCase) {
		scanf("%d", &length);
		v.assign(col, vector<char>(row, 0));
		for (int i = 0; i < col; ++i)
			for (int j = 0; j < row; ++j)
				scanf(" %c", &v[i][j]);
		/*for (int i = 0; i < col; ++i) {
			for (int j = 0; j < row; ++j)
				printf("%c", v[i][j]);
			printf("\n");
		}*/
			
		
		printf("#%d %d\n",testCase, palindrome(length));
		v.clear();
		answer = 0;
	}
	return 0;
}