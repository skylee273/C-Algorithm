#include <cstdio>
#include <vector>
#include <list>

using namespace std;

vector<int> it;
void insertPassword(int x, vector<int> it2) {
	for (int i = 0; i < it2.size(); ++i) {
		it.insert(it.begin() + x + i, it2[i]);
	}
}
void deletePassword(int x, int y) {
	it.erase(it.begin() + x, it.begin() + x + y );
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
			if (cmd == 'I') {
				for (int j = 0; j < y; ++j) {
					scanf(" %d", &s);
					it2.push_back(s);
				}
				insertPassword(x, it2);
			}
			if (cmd == 'D') {
				deletePassword(x, y);
			}
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