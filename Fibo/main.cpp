#include <cstdio>
#include <vector>

using namespace std;

long m[1000] = { 0, };
long recursiveFibo(int n) {
	if (n <= 2) return n-1;
	return recursiveFibo(n - 1) + recursiveFibo(n - 2);
}
long memoizationFibo(int n) {
	m[1] = 0;
	m[2] = 1;
	if ( n > 2 && m[n] == 0) 
		m[n] = memoizationFibo(n - 1) + memoizationFibo(n - 2);
	return m[n];
}
long dpFibo(int n) {
	long dp[1000];
	dp[1] = 0;
	dp[2] = 1;
	
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
int main() {
	//printf("피보나치 10번째 수  = %ld\n", recursiveFibo(40));
	printf("피보나치 10번째 수  = %ld\n", memoizationFibo(60));
	printf("피보나치 10번째 수  = %ld\n", dpFibo(60));

	return 0;
}