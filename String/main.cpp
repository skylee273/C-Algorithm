#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
bool bruteForce(string s, string match) {
	for (int i = 0; i < s.length(); ++i) {
		for (int j = 0; j < match.length(); ++j) {
			if (s[j+i] != match[j]) {
				//i = i+j;
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
		while (j > 0 && s[i] != p[j]) {
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
int skip(char c, string p) {
	for (int i = 0; i < p.size(); ++i) {
		if (c == p[i])
			return (i + p.size() - 1);
	}
	return p.size();
}
bool BoyerMoore(string s, string p) {
	int n = s.size();
	int j = p.size()-1;
	// 패턴의 오른쪽 끝에 있는 문자가 불일치 하고, 이 문자가 패턴 내에 존재 하지않는 경우
	int i = j;
	while (i < n) {
		if (s[i] != p[j]) {
			i += skip(s[i], p);
			j = p.size() - 1;
		}
		else {
			if (j == 0)
				return true;
			j--;
			i--;
		}
	}
	return false;
}

int main() {
	string s = "ABABABABBABABABABC";
	string match = "ABC";
	bool check = bruteForce(s, match);
	if (check)
		printf("ok1\n");
	bool check2 = kmp(s, match);
	if (check2) {
		printf("ok2\n");
	}
	bool check3 = BoyerMoore(s, match);
	if (check3) {
		printf("ok3\n");
	}
}