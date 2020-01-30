#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PLUS -1
#define MINUS -2
#define MULT -3
#define DIV -4

int nodeCnt;
double result = 0.0;
typedef struct {
	double data;
	int left;
	int right;
}TreeNode;

vector<TreeNode> v;
void initTree() {
	for (int i = 1; i <= nodeCnt; ++i) {
		v[i].data = 0.0;
		v[i].left = 0;
		v[i].right = 0;
	}
}
int preOrder(int root) {
	if (v[root].data == 0.0)
		return result;
	int curData = v[root].data;
	if (curData == PLUS || curData == MINUS || curData == MULT || curData == DIV) {
		int leftData = preOrder(v[root].left);
		int rightData = preOrder(v[root].right);
		if (curData == PLUS) {
			result = leftData + rightData;
		}else if (curData == MINUS) {
			result = leftData - rightData;
		}
		else if (curData == MULT) {
			result = leftData * rightData;
		}
		else {
			result = leftData / rightData;
		}
		v[root].data = result;
	}
	return v[root].data;
}
int main() {
	for (int t = 1; t <= 10; ++t) {
		scanf(" %d", &nodeCnt);
		v.resize(nodeCnt + 1);
		initTree();
		for (int i = 1; i <= nodeCnt; ++i) {
			int parent;
			string str;
			cin >> parent;
			cin >> str;
			// 연산자일 경우
			if (!str.compare("+") || !str.compare("-") || !str.compare("*") || !str.compare("/")) {
				int left, right;
				scanf(" %d %d", &left, &right);
				v[i].left = left;
				v[i].right = right;
				if (!str.compare("+")) v[i].data = PLUS;
				if (!str.compare("-")) v[i].data = MINUS;
				if (!str.compare("*")) v[i].data = MULT;
				if (!str.compare("/")) v[i].data = DIV;
			}
			else {
				v[i].data = stod(str);
			}
		}
		/*for (int i = 1; i <= nodeCnt; ++i) {
			printf("%lf ", v[i].data);
		}*/
		printf("#%d %d \n", t, preOrder(1));
		result = 0.0;
		v.clear();
	}
	return 0;
}