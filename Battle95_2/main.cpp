#include <cstdio>
#include <vector>
using namespace std;

int v[100000] = { 0, };
const int up = 1;
const int down = 2;
const int none = 0;

int n;

int main() {

	int testCase;
	scanf("%d", &testCase);

	for (int t = 1; t <= testCase; ++t) {
		int answer = 0;
		scanf("%d ", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d ", &v[i]);
		}
		int state = none;
		for (int i = 0; i < n - 1; ++i) {
			if (v[i + 1] == v[i])
				continue;
			else if (v[i + 1] > v[i] && state == none)
				state = up;
			else if (v[i + 1] > v[i] && state == down) {
				answer++;
				state = none;
			}
			else if (v[i + 1] < v[i] && state == none)
				state = down;
			else if (v[i + 1] < v[i] && state == up) {
				state = none;
				answer++;
			}
		}
		printf("#%d %d\n", t, answer + 1);
	}
	return 0;
}