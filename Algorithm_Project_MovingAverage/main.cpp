#include <cstdio>
#include <vector>
#include <ctime>

using namespace std;

// N개의 측정치가 주어질 때 매M달 간의 이동 평균을 계산하는 프로그램을 계산하는 프로그램을 작성
vector<double> movingAverage1(const vector<double>& A, int M) {
	int N = A.size();
	vector<double> ret;

	for (int i = M - 1; i < N; ++i) {
		// A[i]까지의 이동평균을 구한다.
		double partialSum = 0.0;
		for (int j = 0; j < M; ++j) {
			partialSum += A[i - j];
		}
		ret.push_back(partialSum / M);
	}
	return ret;
}
vector<double> movingAverage2(const vector<double>& A, int M) {
	int N = A.size();
	double partialSum = 0.0;
	vector <double> ret;
	for (int i = 0; i < M - 1; ++i) {
		partialSum += A[i];
	}
	for (int i = M - 1; i < N; ++i) {
		partialSum += A[i];
		ret.push_back(partialSum / M);
		partialSum -= A[i - M + 1];
	}
	return ret;
}
int main() {
	vector<double> sample;
	vector<double> answer;
	vector<double> answer2;
	clock_t start, end;
	double result;
	int startTime = 0;
	sample.push_back(50.3);
	sample.push_back(50.7);
	sample.push_back(50.1);
	sample.push_back(54.3);
	sample.push_back(57.3);
	sample.push_back(45.3);
	sample.push_back(47.4);

	answer = movingAverage1(sample, 2);
	answer2 = movingAverage2(sample, 2);

	int size = answer.size();
	start = clock();
	for (int i = 0; i < size; ++i) {
		printf("%3.5lf\n", answer[i]);
	}
	end = clock();
	printf("측정 시간 = %f\n", (double)(end - start));
	start = clock();
	for (int i = 0; i < size; ++i) {
		printf("%3.5lf\n", answer[i]);
	}
	end = clock();
	printf("측정 시간 = %f\n", (double)(end - start));

	return 0;
}