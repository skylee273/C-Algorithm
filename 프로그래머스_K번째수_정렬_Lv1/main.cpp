#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	//for (auto &v : commands) {
	//  for (int i = 0; i < v.size(); i++) {
	//      printf("%d ", v[i]);
	//  }
	//  printf("\n");
	//}
	for (int i = 0; i < commands.size(); ++i) {
		int start = commands[i][0];
		int end = commands[i][1];
		int k = commands[i][2];
		vector<int> v;
		for (int j = start; j <= end; ++j)
			v.push_back(array[j - 1]);
		sort(v.begin(), v.end());
		answer.push_back(v[k - 1]);
	}
	return answer;
}