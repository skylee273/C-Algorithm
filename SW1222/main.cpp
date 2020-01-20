#include <cstdio>
#include <vector>

using namespace std;
vector<char> v;
vector<int> answer;
vector<char> st;
void clear() {
	answer.clear();
	st.clear();
	v.clear();
}
void infixToPostFix(char c) {
	if (c == '+') {
		if (v.empty()) {
			v.push_back(c);
		}
		else {
			st.push_back(v.back());
			v.pop_back();
			v.push_back(c);
		}
	}
	else
		st.push_back(c);
}
void calculator(char c) {
	if (c != '+') {
		answer.push_back(c - '0');
	}
	else {
		int val1 = answer.back();
		answer.pop_back();
		int val2 = answer.back();
		answer.pop_back();
		answer.push_back(val2 + val1);
	}
}
int main() {

	int num;
	for (int testCase = 1; testCase <= 10; ++testCase) {
		scanf("%d", &num);
		for (int i = 0; i < num; ++i) {
			char c;
			scanf(" %c", &c);
			infixToPostFix(c);
		}
		while (!v.empty()) {
			st.push_back(v.back());
			v.pop_back();
		}
	    for (int i = 0; i < num; ++i) {
			calculator(st[i]);
		}
		
		printf("#%d %d\n", testCase, answer.back());
		clear();
	}
	return 0;
}