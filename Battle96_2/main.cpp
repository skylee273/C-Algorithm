#include <cstdio>
#include <vector>
using namespace std;

int v[100000] = { 0, };
const int up = 0;
const int down = 1;
int answer = 99999;
int n;
void dfs(int index, int ans, int state) {
	if (index == n) {
		if (ans < answer) {
			answer = ans;
		}
		return;
	}
	if (v[index] == v[index - 1]) {
		dfs(index + 1, ans, state);
	}
	else if (v[index] > v[index - 1]) {
		if (state == up) {
			dfs(index + 1, ans, state);
		}
		else {
			dfs(index + 1, ans + 1, up);
			dfs(index + 1, ans + 1, down);
		}
	}
	else {
		if (state == down) {
			dfs(index + 1, ans, state);
		}
		else {
			dfs(index + 1, ans + 1, down);
			dfs(index + 1, ans + 1, up);
		}
	}
}
int main() {
	
	int testCase;
	scanf("%d", &testCase);

	for (int t = 1; t <= testCase; ++t) {
		scanf("%d ", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d ", &v[i]);
		}
		dfs(1, 1, up);
		dfs(1, 1, down);
		printf("#%d %d\n", t, answer);
		answer = 99999;
	}
	return 0;
}