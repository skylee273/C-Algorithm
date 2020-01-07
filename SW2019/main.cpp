#include <cstdio>
#include <vector>

using namespace std;
int n;

int main() {

	scanf("%d", &n);
	
	for (int i = 0; i <= n; ++i) {
		printf("%d ", (1 << i));
	}
}																												 