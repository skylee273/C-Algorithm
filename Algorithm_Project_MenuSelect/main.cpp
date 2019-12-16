#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;
const int INF = 987654321;
int testCase, N, M, num;
vector<int> menu[50];
bool canEverybodyEat(const vector<int>& menu);
int selectMenu(vector<int>& menu, int food) {
	// 기저사례 : 모든 음식에 대해 만들지 여부를 결정했을떄
	if (food == M) {
		if (canEverybodyEat(menu)) return menu.size();
		return INF;
	}
	// 이 음식을 만들지 않는 경우의 답을 계산한다.
	int ret = selectMenu(menu, food + 1);
	menu.push_back(food);
	ret = __min(ret, selectMenu(menu, food + 1));
	menu.pop_back();
	return ret;
}
int main() {

	scanf("%d", &testCase);
	if (testCase < 1 || testCase > 50) {
		exit(-1);
	}

	while (testCase--) {
		scanf("%d %d", &N, &M);
		if (N < 1 || N > 50 || M < 1 || M > 50)
			exit(-1);
		map<string, int> sample;
		for (int i = 0; i < N; ++i) {
			string name;
			scanf("%s", name);
			sample[name] = i;
		}
		for (int i = 0; i < M; ++i) {
			int count;
			scanf("%d", &count);
			for (int j = 0; j < count; ++j) {
				string name;
				scanf("%s", name);
				menu[i].push_back(sample[name]);
			}
		}
		vector<int> menu(M, 0);
		int answer = selectMenu(menu, 0);
		printf("%d", answer);
	}


}
