#include <cstdio>
#include <vector>
#include <list>

using namespace std;

vector<int> v;
int main() {
	int t;
	int n;
	int originPassword;
	int cmdCnt;
	for (int t = 1; t <= 10; ++t) {
		scanf(" %d", &n);
		v.resize(n);
		for (int i = 0; i < n; ++i) {
			scanf(" %d", &originPassword);
			v[i] = originPassword;
		}
		scanf(" %d", &cmdCnt);
		for (int i = 0; i < cmdCnt; ++i) {
			
			char cmd;
			scanf(" %c", &cmd);
			if (cmd == 'I') {
				int x, y, s;
				scanf(" %d %d", &x, &y);
				for (int j = 0; j < y; ++j) {
					scanf(" %d", &s);
					v.insert(v.begin() + x + j, s);
				}
			}
			else if (cmd == 'D') {
				int x, y;
				scanf(" %d %d", &x, &y);
				v.erase(v.begin() + x, v.begin() + x + y);
			}
			else {
				int y, s;
				scanf(" %d", &y);
				for (int j = 0; j < y; ++j) {
					scanf(" %d", &s);
					v.push_back(s);
				}
			}
		}

		printf("#%d ", t);
		for (int i = 0; i < 10; ++i) {
			printf("%d ", v[i]);
		}
		printf("\n");
		v.clear();
	}
	return 0;
}