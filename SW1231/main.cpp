#include <cstdio>
#include <vector>

using namespace std;
int nodeNum;
vector<int> node;

void inOrder(int root) {
	if (node[root] == 0)
		return;
	inOrder(root * 2);
	printf("%c", node[root]);
	inOrder(root * 2 + 1);
}
int main() {
	char data;
	setbuf(stdout, NULL);
	for (int t = 1; t <= 10; ++t) {
		scanf(" %d", &nodeNum);
		node.assign(101, 0);
		for (int i = 1; i <= nodeNum; ++i) {
			char op;
			scanf(" %*d %c", &op);
			if ((nodeNum % 2 == 0 && (i < nodeNum / 2)) || (nodeNum % 2 == 1 && i <= (nodeNum - 1) / 2))
				scanf(" %*d %*d");
			else if (nodeNum % 2 == 0 && i == nodeNum / 2) {
				scanf(" %*d");
			}
			node[i] = op;
		}
		printf("#%d ", t);
		inOrder(1);
		printf("\n");
		node.clear();
	}
	return 0;
}