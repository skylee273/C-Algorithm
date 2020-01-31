#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int v[10];
int key;
bool answer = false;
void binarySearch(int left, int right) {
	if (left > right)
		return;
	int mid = (left + right) / 2;
	if (v[mid] == key) {
		answer = true;
		return;
	}
	if (v[mid] < key) {
		binarySearch(mid + 1, right);
	}
	if (v[mid] > key) {
		binarySearch(left, mid - 1);
	}
}
int main() {
	int n;

	scanf(" %d %d", &n, &key);
	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; ++i) {
		scanf(" %d", &v[i]);
	}
	sort(v, v + n);
	binarySearch(0, n - 1);
	if (answer)
		printf("true");
	else
		printf("false");
	return 0;
}