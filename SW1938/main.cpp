#include <cstdio>
#include <vector>

using namespace std;

int main() {

	int val, val1;

	scanf("%d %d", &val, &val1);

	if (val < 1 || val1 > 9)
		exit(-1);
	printf("%d\n", val + val1);
	printf("%d\n", val - val1);
	printf("%d\n", val * val1);
	printf("%d\n", val / val1);
	return 0;
}