#include <cstdio>
#include <vector>

using namespace std;

vector<char> postfix;
vector<char> buffer;
vector<int> cal;

int priority(char c) {
	if (c == '+') return 1;
	else if (c == '(') return 0;
	else return 2;
}

void infixToPostfix(char c) {
	if (c >= '0' && c <= '9') {
		buffer.push_back(c);
	}
	else if (c == ')') {
		while (!postfix.empty()) {
			if (postfix.back() == '(') {
				postfix.pop_back();
				break;
			}
			else {
				buffer.push_back(postfix.back());
				postfix.pop_back();
			}
		}
	}
	else if (c == '(') {
		postfix.push_back(c);
	}
	else if (c == '+' || c == '*') {
		if (postfix.empty())
			postfix.push_back(c);
		else {
			while (priority(c) < priority(postfix.back())) {
				buffer.push_back(postfix.back());
				postfix.pop_back();
				if (postfix.empty())
					break;
			}
			postfix.push_back(c);
		}
	}
}
void calculator(char c) {
	if (c >= '0' && c <= '9')
		cal.push_back(c - '0');
	else {
		int val1 = cal.back();
		cal.pop_back();
		int val2 = cal.back();
		cal.pop_back();
		if (c == '*') {
			cal.push_back(val2 * val1);
		}
		if (c == '+') {
			cal.push_back(val2 + val1);
		}
	}
}
void clear() {
	cal.clear();
	buffer.clear();
	postfix.clear();
}
int main() {
	int length;
	for (int testCase = 1; testCase <= 10; testCase++) {
		scanf("%d ", &length);

		for (int i = 0; i < length; ++i) {
			char c;
			scanf(" %c", &c);
			infixToPostfix(c);
		}
		while (!postfix.empty()) {
			buffer.push_back(postfix.back());
			postfix.pop_back();
		}
		for (int i = 0; i < buffer.size(); ++i) {
			/*printf("%c", buffer[i]);*/
			calculator(buffer[i]);
		}
		printf("#%d %d\n", testCase, cal.back());
		clear();
	}
	return 0;
}
