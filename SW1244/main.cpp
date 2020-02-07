#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool visited[1000000][11];
string s;
int price = 0;
void maxPrice(string s, int cnt) {
	int num = stoi(s);
	if (visited[num][cnt]) return;
	visited[num][cnt] = true;
	if (cnt == 0) {
		if (price < num) {
			price = num;
		}
		return;
	}
	for (int i = 0; i < s.size() - 1; ++i) {
		for (int j = i + 1; j < s.size(); ++j) {
			swap(s[i], s[j]);
			maxPrice(s, cnt-1);
			swap(s[j], s[i]);
		}
	}
}
int main() {
	int testCase;
	int cnt;
	scanf(" %d", &testCase);
	for (int tc = 1; tc <= testCase; ++tc) {
		cin >> s;
		cin >> cnt;
		maxPrice(s, cnt);
		printf("#%d %d \n",tc, price);
		price = 0;
	}
	
	return 0;
}