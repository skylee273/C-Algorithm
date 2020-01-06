#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

const int one[] = { 1,2,3,4,5 };
const int two[] = { 2,1,2,3,2,4,2,5 };
const int three[] = { 3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int arr[3] = { 0, 0, 0 };
	for (int i = 0; i < answers.size(); i++) {
		if (one[i % 5] == answers[i])
			arr[0]++;
		if (two[i % 8] == answers[i])
			arr[1]++;
		if (three[i % 10] == answers[i])
			arr[2]++;
	}

	int max = *max_element(arr, arr + 3);
	for (int i = 0; i < 3; ++i) {
		if (max == arr[i])
			answer.push_back(i + 1);
	}
	return answer;
}
