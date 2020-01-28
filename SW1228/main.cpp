#include <cstdio>
#include <vector>
#include <list>

using namespace std;

vector<int> it;
void changePassword(char cmd, int x, vector<int> it2) {
	if (cmd == 'I') {
		for (int i = 0; i < it2.size(); ++i) {
			it.insert(it.begin() + x + i, it2[i]);
		}
	}
}
int main() {
	int t;
	int n;
	int originPassword;
	int cmdCnt;
	for (int t = 1; t <= 10; ++t) {
		scanf(" %d", &n);
		for (int i = 0; i < n; ++i) {
			scanf(" %d", &originPassword);
			it.push_back(originPassword);
		}
		scanf(" %d", &cmdCnt);
		for (int i = 0; i < cmdCnt; ++i) {
			int x, y, s;
			char cmd;
			vector <int> it2;
			scanf(" %c %d %d ", &cmd, &x, &y);
			for (int j = 0; j < y; ++j) {
				scanf(" %d", &s);
				it2.push_back(s);
			}
			changePassword(cmd, x, it2);
			it2.clear();
		}
		printf("#%d ", t);
		for (int i = 0; i < 10; ++i) {
			printf("%d ", it[i]);
		}
		printf("\n");
		it.clear();
	}
	return 0;
}