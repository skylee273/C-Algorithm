#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
	
	string str;
	int answer;
	cin >> str;


	for (int i = 0; i < str.length(); ++i) {
		answer = str.at(i) - 64;
		printf("%d ", answer);
	}
}