#include <cstdio>
#include <vector>

using namespace std;
int nodeNum;
vector<int> node;

int main() {
	char data;
	setbuf(stdout, NULL);
	for (int t = 1; t <= 10; ++t) {
		scanf(" %d", &nodeNum);
		node.assign(nodeNum+1, '0');
		for (int i = 1; i <= nodeNum; ++i) {
			char op;
			scanf(" %*d %c", &op);
			if ((nodeNum % 2 == 0 && (i < nodeNum / 2)) || (nodeNum % 2 == 1 && i <= (nodeNum - 1) / 2))
				scanf(" %*d %*d");
			else if (nodeNum % 2 == 0 && i == nodeNum / 2)
				scanf(" %*d\n");
			node[i] = op;
		}
		int result = 1;
		for (int i = 1; i <= nodeNum / 2; ++i) {
			if (node[i] >= '1' && node[i] <= '9')
				result = 0;
		}
		for (int i = (nodeNum / 2 + 1); i <= nodeNum; ++i) {
			if (node[i] < '0' || node[i] > '9')
				result = 0;
		}
		printf("#%d ", t);
		printf("%d", result);
		printf("\n");
		node.clear();
		
	}
	return 0;
}