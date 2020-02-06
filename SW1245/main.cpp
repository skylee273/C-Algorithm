#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

double x[10];
double m[10];
int n;
const double Eps = 0.000000000001;

vector<double> answer;
void findX() {
	for (int i = 0; i < n-1; ++i) {
		double left = x[i];
		double right = x[i+1];
		double mid;
		double sum;
		double ans;
		for (int k = 0; k < 100; ++k) {
			// 왼쪽 합
			mid = (left + right) / 2.0;
			sum = 0, ans = 0;
			for (int j = 0; j <= i; ++j) {
				sum += (m[j]) / ((mid - x[j]) * (mid - x[j]));
			}
			// 오른쪽 합
			for (int j = i + 1; j < n; ++j) {
				sum -= (m[j]) / ((x[j] - mid) * (x[j] - mid));
			}
			
			//// 만약 0 이 되었을떄
			//if (abs(sum) < Eps) {
			//	
			//	break;
			//}
			//
			if (sum > 0) {
				left = mid;
			}
			else {
				ans = mid;
				right = mid;
			}
		}
		answer.push_back(mid);
	}
}
int main() {
	int testcase;
	scanf(" %d", &testcase);
	for (int tc = 1; tc <= testcase; ++tc) {
		
		scanf(" %d", &n);
		memset(x, 0, sizeof(x));
		memset(m, 0, sizeof(m));
		for (int i = 0; i < n; ++i) {
			scanf(" %lf", &x[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf(" %lf", &m[i]);
		}
		findX();
		printf("#%d ", tc);
		reverse(answer.begin(), answer.end());
		while (!answer.empty()) {
			printf("%0.10lf ", answer.back());
			answer.pop_back();
		}
		printf("\n");
		answer.clear();
	}
	return 0;
}