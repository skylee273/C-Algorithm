#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int dump;
	int height;
	vector<int> box;
	for (int num = 1; num <= 10; ++num) {
		scanf("%d", &dump);
		for (int i = 0; i < 100; ++i) {
			scanf("%d ", &height);
			box.push_back(height);
		}
		while (dump--) {
			sort(box.begin(), box.end());
			box[0]++;
			box[box.size()-1]--;
			sort(box.begin(), box.end());
			if ((box.back() - box.front()) <= 1) {
				break;
			}
		}
		printf("#%d %d\n", num, box.back()-box.front());
		box.clear();
	}

	return 0;
}