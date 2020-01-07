#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 효율성 테스트 실패
string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	vector <string>::iterator iter;
	while (completion.size() > 0) {
		string name = completion.back();
		completion.pop_back();
		iter = find(participant.begin(), participant.end(), name);
		if(iter != participant.end())
			participant.erase(iter);
	}
	answer = participant.front();
	return answer;
}

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); ++i) {
		if (completion[i] != participant[i]) {
			answer = participant[i];
			break;
		}
	}
	if (answer == "")
		answer = participant.back();
	return answer;
}