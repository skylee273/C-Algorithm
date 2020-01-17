#include <cstdio>
#include <vector>

using namespace std;
int answer = 1;

void powerSet(int n, int m) {
	if (m == 0)
		return;
	answer *= n;
	powerSet(n, m - 1);
}
int main() {

	int num;
	int n, m;
	for (int testCase = 0; testCase < 10; testCase++) {
		scanf("%d", &num);
		scanf("%d %d", &n, &m);
		powerSet(n, m);
		printf("#%d %d\n", num, answer);
		answer = 1;
	}
	return 0;
}