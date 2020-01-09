#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	int temp;
	temp = arr[0];
	answer.push_back(temp);
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] != temp) {
			answer.push_back(arr[i]);
			temp = arr[i];
		}
	}
	reverse(answer.begin(), answer.end());
	return answer;
}