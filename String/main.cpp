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

int main() {
	string s = "a pattern matching algorithm";
	string match = "rithm";
	bool check = bruteForce(s, match);
	if (check)
		printf("ok\n");
}