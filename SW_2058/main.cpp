#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int sum = 0;

void digitSum(int n) {
	
	if (n > 10) {
		sum += (n % 10);
		digitSum(n / 10);
	}
	if (n < 10)
		sum += n;
}

int main() {

	/*
	int val;
	scanf("%d", &val);
	if (val < 1 || val > 9999)
		return 0;
	digitSum(val);
	printf("%d",sum);
	*/
	string str;
	cin >> str;
	
	int result = 0;
	for (int i = 0; i < str.length(); ++i) {
		result += str.at(i) - '0';
	}
	printf("%d", result);

	return 0;
}