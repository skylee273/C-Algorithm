#include <cstdio>

int minSugar(int n) {
	int N = n / 5;
	int min = 9999;
	for (int i = N; i >= 0; --i) {
		int val = n - (5 * i);
		if (val % 3 == 0 && min > (i + val / 3)) {
			min = (i + val / 3);
		}
	}
	if (min == 9999)
		return -1;
	return min;
}

int main() {

	int N;

	scanf("%d", &N);
	printf("%d", minSugar(N));

	return 0;
}