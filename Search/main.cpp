#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(int key, const vector<int> v) {
	int high = v.size() - 1;
	int low = 0;
	while (low <= high) {
		int middle = low + (high - low) / 2;
		if (v[middle] == key)
			return true;
		else if (v[middle] > key)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return false;
}
bool binarySearch(int key, int low, int high, vector<int> v) {
	int middle = (high+low) / 2;
	if (low > high) false;
	if (v[middle] == key)
		return true;
	else if (v[middle] > key)
		binarySearch(key, low, middle - 1, v);
	else if (v[middle] < key)
		binarySearch(key, middle + 1, high, v);
	else
		return false;
}
int main() {
	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(8);
	v.push_back(0);

	sort(v.begin(), v.end());
	if (binarySearch(6, 0, v.size()-1, v))
		printf("ok\n");
	return 0;
}