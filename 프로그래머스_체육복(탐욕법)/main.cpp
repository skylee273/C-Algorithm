#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 틀린 풀이 정답률 50% 밖에 안나옴
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	for (int i = 0; i < lost.size(); ++i) {
		int left = lost[i] - 1;
		int right = lost[i] + 1;
		if (left == 0)
			left = right;
		if (right == n)
			right = left;
		if (find(reserve.begin(), reserve.end(), left) != reserve.end()) {
			reserve.erase(find(reserve.begin(), reserve.end(), left));
			continue;
		}
		if (find(reserve.begin(), reserve.end(), right) != reserve.end()) {
			reserve.erase(find(reserve.begin(), reserve.end(), right));
			continue;
		}
		--n;
		if (reserve.size() == 0)
			break;
	}
	answer = n;
	return answer;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector <int> student(n, 0);
	for (int i = 0; i < lost.size(); ++i) {
		student[lost[i] - 1] += -1;
	}
	for (int i = 0; i < reserve.size(); ++i) {
		student[reserve[i] - 1] += 1;
	}
	for (int i = 0; i < student.size(); ++i) {
		if (i != 0 && student[i - 1] == -1) {
			if (student[i] == 1)
				student[i - 1] = 1;
		}
		if (i != (student.size() - 1) && student[i + 1] == -1) {
			if (student[i] == 1)
				student[i + 1] = 1;
		}
	}

	for (int i = 0; i < student.size(); ++i) {
		answer += student[i];
	}
	return answer;

}