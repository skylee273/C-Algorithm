#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int main() {

	vector<int> v;
	scanf("%d", &n);
	for (int i = 1; i * i <= n; ++i) {
		if (n  % i == 0) {
			v.push_back(i);
			v.push_back(n / i);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		printf("%d ", v[i]);
	}
	return 0;
}