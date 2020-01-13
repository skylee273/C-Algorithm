#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
bool bruteForce(string s, string match) {
	for (int i = 0; i < s.length(); ++i) {
		for (int j = 0; j < match.length(); ++j) {
			if (s[j+i] != match[j]) {
				i = i+j;
				break;
			}
			if (j == match.length() - 1)
				return true;
		}
	}
	return false;
}

vector<int> getPi(string p) {
	int m = p.size();
	vector<int> pi(m, 0);
	int j = 0;
	for (int i = 1; i < m; ++i) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}
bool kmp(string s, string p) {
	int n = s.size();
	int m = p.size();
	auto pi = getPi(p);
	int j = 0;
	for (int i = 0; i < n; ++i) {
		if (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1)
				return true;
			else
				++j;
		}
	}
	return false;
}

int main() {
	string s = "ABABABABBABABABABC";
	string match = "ABABABABC";
	bool check = bruteForce(s, match);
	if (check)
		printf("ok\n");
	bool check2 = kmp(s, match);
	if (check2) {
		printf("ok\n");
	}
}