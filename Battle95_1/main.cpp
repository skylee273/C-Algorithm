#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;


int main() {
	int testCase;
	int length;
	string answer, str;
	scanf("%d", &testCase);

	for (int s = 0; s < testCase; ++s) {
		scanf("%d ", &length);
		getline(cin, answer);
		getline(cin, str);
		for (int i = 0; i < answer.size(); ++i) {
			if (answer[i] != str[i])
				length--;
		}
		printf("#%d %d\n", s + 1, length);
	}

	return 0;

}