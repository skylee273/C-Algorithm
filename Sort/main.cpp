#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int> &v) {
	for (int i = 0; i < v.size() - 1; ++i) {
		for(int j = 0; j < v.size()-1-i; ++j)
			if (v[j] > v[j +1])
				swap(v[j], v[j+1]);
	}
}
void countingSort(vector<int> &v) {
	// 1. 제일 큰값 찾기
	int max = *max_element(v.begin(), v.end());
	vector<int> count(max+1,0);
	vector<int> arr(v.size(), 0);
	// 2. 발생횟수 세기
	for (int i = 0; i < v.size(); ++i) {
		count[v[i]]++;
	}
	// 3. 원소 자릿수 맞추기
	for (int i = 1; i < count.size(); ++i)
		count[i] = count[i] + count[i - 1];

	while (!v.empty()) {
		int index = v.back();
		v.pop_back();
		arr[--count[index]] = index;
	}
	v = arr;
}

void quickSort(vector<int> &v, int low, int high) {
	int pivot = (low + high) / 2;
	int left = low;
	int right = high;
	if (left >= right)
		return;
	while (left <= right) {
		while (v[left] < v[pivot]) left++;
		while (v[right] > v[pivot]) right--;
		if (left <= right) {
			swap(v[left], v[right]);
			left++;
			right--;
		}
	}
	quickSort(v, low, right);
	quickSort(v, left, high);
}
void selectionSort(vector<int> &v) {
	// 주어진 자료들 중 가장 적은 값의 원소부터 차례대로 선택하여 위치를 교환
	for (int i = 0; i < v.size(); ++i) {
		int min = v[i];
		int index = i;
		for (int j = i+1; j < v.size(); ++j) {
			if (min > v[j]) {
				min = v[j];
				index = j;
			}
		}
		swap(v[i], v[index]);
	}
}
void printSort(const vector<int> v) {
	for (int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	printf("\n");
}
int main() {
	vector<int> v;
	
	v.push_back(0);
	v.push_back(9);
	v.push_back(2);
	v.push_back(3);

	v.push_back(8);
	v.push_back(5);
	v.push_back(1);
	v.push_back(8);
	
	//bubbleSort(v);
	//printSort(v);
	//countingSort(v);
	//printSort(v);
	//selectionSort(v);
	//printSort(v);
	quickSort(v,0, v.size()-1);
	printSort(v);
}