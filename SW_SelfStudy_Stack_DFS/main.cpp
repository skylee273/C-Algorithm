#include <cstdio>
#include <vector>

using namespace std;
vector<int> st;
vector <vector<int>> arr;

vector <bool> visit(8, false);
void dfs(int v) {
	st.push_back(v);
	printf("%d ", v);
	visit[v] = true;
	while (!st.empty()) {
		for (int i = 1; i <= 7; ++i) {
			if (visit[i] == false && arr[st.back()][i] == 1) {
				st.push_back(i);
				printf("%d ", i);
				visit[i] = true;
				i = 1;
			}
		}
		st.pop_back();
	}
}
void backTrackingDfs(int v) {
	printf("%d ", v);
	visit[v] = true;
	for (int i = 1; i <= 7; ++i) {
		if (visit[i] == false && arr[v][i] == 1) {
			backTrackingDfs(i);
		}
	}
}
int main() {
	arr.assign(8, vector<int>(8, 0));
	int v1, v2;
	for (int i = 0; i < 7; ++i) {
		scanf("%d %d", &v1, &v2);
		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}
	dfs(1);
	printf("\n");
	visit.assign(8, false);
	backTrackingDfs(1);
	arr.clear();
	return 0;
}