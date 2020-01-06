#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

const int MONTH[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {

	int year, month, date;
	int testCase;

	scanf("%d", &testCase);
	for (int i = 1; i <= testCase; ++i) {
		scanf("%04d%02d%02d", &year, &month, &date);
		if (month < 1 || 12 < month) {
			printf("#%d -1\n",i);
			continue;
		}else if (date < 1 || date > MONTH[month-1]) {
			printf("#%d -1\n", i);
			continue;
		}
			
		printf("#%d %04d/%02d/%02d\n",i, year, month, date);
	}
}