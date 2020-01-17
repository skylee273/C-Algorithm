#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
vector<char> v;
vector<char> st;
string s;
bool dfs() {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<')
			v.push_back(s[i]);
		else {
			if (v.empty())
				return false;
			if (v.back() == '(' && s[i] == ')')
				v.pop_back();
			else if (v.back() == '{' && s[i] == '}')
				v.pop_back();
			else if (v.back() == '[' && s[i] == ']')
				v.pop_back();
			else if (v.back() == '<' && s[i] == '>')
				v.pop_back();
			else 
				return false;
		}
	}
	if (v.empty())
		return true;
	else
		return false;
}
int main() {
	int length;
	for (int testCase = 0; testCase < 10; testCase++) {
		scanf("%d ", &length);
		getline(cin, s);
		if (dfs()) {
			printf("#%d 1\n", testCase+1);
		}
		else {
			printf("#%d 0\n", testCase + 1);
		}
		v.clear();
	}
	return 0;
}