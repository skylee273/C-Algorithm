#include <cstdio>
#include <vector>

using namespace std;

int N;

int main() {
	vector<long> v;
	scanf("%d", &N);
	v.push_back(1);
	while (true) {
		if (N <= v.back())
			break;
		v.push_back(v.back() + (6 * v.size()));
	}
	printf("%ld", v.size());
	return 0;
}