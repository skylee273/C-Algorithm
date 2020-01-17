#include <cstdio>
#include <vector>

using namespace std;

vector<int> v1;
vector<int> v2;


bool isRoad = false;
void backTracking(int v) {
	if (v == 99) {
		isRoad = true;
		return;
	}
	if (v1[v] != 0)
		backTracking(v1[v]);
	if (v2[v] != 0)
		backTracking(v2[v]);
}
int main() {
	int num;
	int cnt;
	int index;
	for (int testCase = 1; testCase <= 10; ++testCase) {
		v2.assign(100, 0);
		v1.assign(100, 0);
		scanf("%d %d", &num, &cnt);
		for (int i = 0; i < cnt; ++i) {
			if (i % 2 == 0) {
				scanf("%d", &index);
				scanf("%d", &v2[index]);
			}
			else {
				scanf("%d", &index);
				scanf("%d", &v1[index]);
			}
		}
		backTracking(0);
		if (isRoad)
			printf("#%d 1\n",num);
		else
			printf("#%d 0\n", num);
		isRoad = false;
		v2.clear();
		v1.clear();
	}
	return 0;
}