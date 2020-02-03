#include <cstdio>
#include <vector>

using namespace std;

int player[10000] = { 0, };
int main() {

	int n, k;
	scanf(" %d %d", &n, &k);

	for (int i = 0; i < n; ++i) {
		player[i] = i + 1;
	}
	for (int i = 0; i < n-1; ++i) {
		int death = ((i + k - 1) % (n));
		player[death] = 0;
	}
	for (int i = 0; i < n; ++i) {
		if (player[i] != 0)
			printf("%d ", player[i]);
	}
	return 0;
}