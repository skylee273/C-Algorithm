#include <cstdio>

using namespace std;


int main() {
	long long A, B, C;

	scanf("%lld %lld %lld", &A, &B, &C);
	if (B >= C) {
		printf("-1\n");
		return 0;
	}

	long long ans = ((A / (C - B)) + 1);

	printf("%lld\n", ans);
	
	return 0;
}