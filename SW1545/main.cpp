#include <cstdio>
#include <vector>

using namespace std;
int n;
int main() {
	scanf("%d", &n);
	for (int i = n; i >= 0; --i) {
		printf("%d ", i);
	}
	return 0;
}