#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> v(10000001, 0);

void quickSort(int low, int high) {
	if (low >= high)
		return;
	int left = low;
	int right = high;
	int pivot = v[(low + high) / 2];

	while (left <= right) {
		while (v[left] < pivot) left++;
		while (v[right] > pivot) right--;
		if (left <= right) {
			swap(v[left], v[right]);
			left++;
			right--;
		}
	}
	quickSort(low, right);
	quickSort(left, high);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	quickSort(0, n-1);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", v[i]);
	}
	return 0;
}