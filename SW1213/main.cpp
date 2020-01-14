#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>


using namespace std;

int brueForce(string s, string p) {
	int cnt = 0;
	int m = p.size()-1;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p.size(); ++j) {
			if (s[i + j] != p[j]) {
				break;
			}
			if (j == m)
				cnt++;
		}
	}
	return cnt;
}
int main() {
	string s, p;
	int num;
	for (int testCase = 0; testCase < 10; testCase++) {
		scanf("%d ", &num);
		getline(cin, p);
		//printf("%d\n", p.size());
		getline(cin, s);
		printf("#%d %d\n", num, brueForce(s, p));
	}
}