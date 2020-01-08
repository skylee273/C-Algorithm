#include <cstdio>

using namespace std;

int n;

int main() {

	scanf("%d", &n);

	// 수학 공식 이용 (합 공식) N * ( N + 1) / 2
	printf("%d", (n*(n + 1)) / 2);
	return 0;
}