#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_NUM 6
vector<int> v;

bool isGin() {
	int result = 0;
	if (v[2] - 2 == v[1] - 1 && v[1] - 1 == v[0]) {
		result++;
	}
	if (v[0] == v[1] && v[0] == v[2]) {
		result++;
	}
	if (result != 1)
		return false;
	if (v[5] - 2 == v[4] - 1 && v[4]-1 == v[3]) {
		result++;
	}
	if (v[5] == v[4] && v[4] == v[3]) {
		result++;
	}
	if (result == 2)
		return true;
	else
		return false;
}
int main() {
	int n;
	string s;
	scanf(" %d", &n);
	for (int t = 1; t <= n; ++t) {
		v.assign(MAX_NUM, 0);
		for (int i = 0; i < MAX_NUM; ++i) {
			char c;
			scanf(" %c", &c);
			v[i] = c - '0';
		}
		sort(v.begin(), v.end());
		/*for (int i = 0; i < MAX_NUM; ++i) {
			printf("%d ", v[i]);
		}*/
		if (isGin()) {
			printf("#%d 1\n", t);
		}
		else {
			printf("#%d 0\n", t);
		}
		v.clear();
	}
	return 0;
}