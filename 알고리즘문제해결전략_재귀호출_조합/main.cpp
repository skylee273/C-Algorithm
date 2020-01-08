#include <cstdio>
#include <vector>

using namespace std;

int n, m;

void printPick(vector<int> picked) {
	for (int i = 0; i < picked.size(); ++i) {
		printf("%d ", picked[i]);
	}
	printf("\n");
}
void pick(int n, vector<int> picked, int toPIck) {
	// 기저 작성
	if (toPIck == 0) {
		// 출력 
		printPick(picked);
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int i = smallest; i < n; ++i) {
		picked.push_back(i);
		pick(n, picked, toPIck - 1);
		picked.pop_back();
	}
	return;
}


int main() {
	vector<int> v;
	scanf("%d %d", &n, &m);
	pick(n, v, m);
}