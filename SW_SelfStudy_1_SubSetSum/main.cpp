#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int v[10];
bool visited[10];
int n;
int result = 0;

void powerSet(int n, int depth) {
	if (n == depth) {
		int sum = 0;
		int i;
		printf("{");
		for (i = 0; i<n; i++) {
			if (visited[i] == 1) {
				sum += v[i];
				printf("%d ", v[i]);
			}
		}
		if (sum == 0)
			result++;
		printf(" sum = %d}\n",sum);
		return;
	}
	visited[depth] = 1;
	powerSet(n, depth + 1);
	visited[depth] = 0;
	powerSet(n, depth + 1);
}
void powerset(int n)
{
	int i, j;
	int max = 1 << n;
	for (i = 0; i<max; i++) {
		printf("{");
		for (j = 0; j<n; j++) {
			if (i & (1 << j)) printf("%d ", v[j]);
		}
		printf("}\n");
	}
}
int main() {
	scanf("%d", &n);
	memset(v, 0, sizeof(n));
	for (int i = 0; i < n; ++i) {
		scanf(" %d", &v[i]);
	}
	powerSet(n, 0);
	powerset(n);
	if (result > 1)
		printf("1");
	return 0;
}