#include <cstdio>
#include <queue>

using namespace std;

int num;

void printfQueue(queue<int> q) {
	printf("#%d ", num);
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
	printf("\n");
}
void createPassword(queue<int>& q) {

	int index = 1;
	while (q.front() > 0) {
		int data = q.front();
		q.pop();
		data -= index;
		if (data <= 0) {
			data = 0;
			q.push(data);
			break;
		}
		else {
			q.push(data);
		}
		index++;
		if (index == 6)
			index = 1;
	}
	printfQueue(q);
}
int main() {
	
	for (int testCase = 0; testCase < 10; ++testCase) {
		queue<int> q;
		scanf("%d", &num);
		for (int i = 0; i < 8; ++i) {
			int data;
			scanf("%d", &data);
			q.push(data);
		}
		createPassword(q);
	}
	return 0;
}