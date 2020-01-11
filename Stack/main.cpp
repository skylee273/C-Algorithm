#include <cstdio>
#include <vector>

using namespace std;

int stack[10];
// 비어 있는 상태
int point = -1;
const int stackSize = 10;
bool isFull();
bool isEmpty();
void push(int value) {
	if (isFull())
		printf("스택이 가득 찼습니다\n");
	stack[++point] = value;
}

void pop() {
	if (isEmpty())
		printf("스택이 비어 있습니다.\n");
	point--;
}
int top() {
	if (isEmpty())
		printf("스택이 비어 있습니다.\n");
	return stack[point];
}
void printStack() {
	for (int i = 0; i <= point; ++i) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

bool isFull() {
	if (point == stackSize - 1)
		return true;
	return false;
}
bool isEmpty() {
	if (point == -1)
		return true;
	return false;
}
int main() {
	push(10);
	printStack();
	pop();
	printStack();
	push(3);
	printStack();
	push(10);
	printStack();
	push(7);
	push(6);
	push(8);
	printStack();
	pop();
	push(3);
	push(1);
	push(10);
	pop();
	pop();
	printStack();
	return 0;
}