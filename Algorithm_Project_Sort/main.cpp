#include <cstdio>
#include <vector>

using namespace std;

void selectionSort(vector<int>& A) {
	for (int i = 0; i < A.size(); ++i) {
		int minIndex = i;
		for (int j = i + 1; j < A.size(); ++j)
			if (A[minIndex] > A[j])
				minIndex = j;
		swap(A[i], A[minIndex]);
	}
}
void insertionSort(vector<int> & A) {
	for (int i = 0; i < A.size(); ++i) {
		int j = i;
		while( j  > 0 && A[j-1] > A[j]){
			swap(A[i], A[j]);
			j--;
		}
	}
}
int main() {
	vector<int> A;

	A.push_back(4);
	A.push_back(2);
	A.push_back(1);
	A.push_back(3);
	selectionSort(A);
	
	for (int i = 0; i < A.size(); ++i) {
		printf("%d ", A[i]);
	}
	printf("\n");
	insertionSort(A);
	for (int i = 0; i < A.size(); ++i) {
		printf("%d ", A[i]);
	}
}