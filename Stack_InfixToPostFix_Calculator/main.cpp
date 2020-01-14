#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int priority(char c) {
	if (c == '(')
		return 0;
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
}
int main() {

	vector<char> postFixStack;
	vector<int> v;
	string s;
	string p;

	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			p += s[i];
			printf("%c", s[i]);
			continue;
		}
		// 문자가 들어온 경우
		if (s[i] == '(') {
			postFixStack.push_back(s[i]);
			continue;
		}else if (s[i] == ')') {
			while (!postFixStack.empty()) {
				char val = postFixStack.back();
				postFixStack.pop_back();
				if (val == '(')
					break;
				p += val;
				printf("%c", val);
			}
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			if (postFixStack.empty())
				postFixStack.push_back(s[i]);
			else {
				while (!postFixStack.empty()) {
					char val = postFixStack.back();
					if (priority(s[i]) > priority(val)) {
						postFixStack.push_back(s[i]);
						break;
					}
					else {
						p += val;
						printf("%c", val);
						postFixStack.pop_back();
					}
				}
			}

		}
	}
	while (!postFixStack.empty()) {
		char val = postFixStack.back();
		postFixStack.pop_back();
		p += val;
		printf("%c", val);
	}
	printf("\n\n");
	for (int i = 0; i < p.size(); ++i) {
		printf("%c", p[i]);
	}
	for (int i = 0; i < p.size(); ++i) {
		if (p[i] >= '0' && p[i] <= '9') {
			v.push_back(p[i] - '0');
			continue;
		}
		switch (p[i]) {
		int val1, val2, result;
		case '+':
			val1 = v.back();
			v.pop_back();
			val2 = v.back();
			v.pop_back();
			result = val2 + val1;
			v.push_back(result);
			break;
		case '-':
			val1 = v.back();
			v.pop_back();
			val2 = v.back();
			v.pop_back();
			result = val2 - val1;
			v.push_back(result);
			break;
		case '*':
			val1 = v.back();
			v.pop_back();
			val2 = v.back();
			v.pop_back();
			result = val2 * val1;
			v.push_back(result);
			break;
		case '/':
			val1 = v.back();
			v.pop_back();
			val2 = v.back();
			v.pop_back();
			result = val2 / val1;
			v.push_back(result);
			break;
		}
	}
	int answer = v.back();
	v.pop_back();
	printf("\n%d\n", answer);

	return 0;
}
