#include <cstdio>
#include <vector>

using namespace std;
#define MAX_NODE_NUM 10000
#define MAX_CHILD_NUM 2
int nodeNum, edgeNum;
int root;
typedef struct
{
	int parent;
	int child[MAX_CHILD_NUM];
}TreeNode;

vector<TreeNode> tree(MAX_NODE_NUM);

void initTree(void)
{
	printf("init tree\n");
	for (int i = 1; i <= nodeNum; ++i) {
		tree[i].parent = -1;
		for (int j = 0; j < MAX_CHILD_NUM; ++j) {
			tree[i].child[j] = -1;
		}
	}
}
// 1 2 1 3 2 4 3 5 3 6 4 7 7 12 5 9 5 8 6 11 6 10 11 13
void addChild(int parent, int child)
{
	int i;
	for (i = 0; i < MAX_CHILD_NUM; i++)
	{
		if (tree[parent].child[i] == -1)
		{
			break;
		}
	}
	tree[parent].child[i] = child;
	tree[child].parent = parent;
}

int getRoot(void)
{
	int i;
	for (i = 1; i <= nodeNum; i++)
	{
		if (tree[i].parent == -1)
		{
			return i;
		}
	}
	return -1;
}

void preOrder(int root)
{
	printf("%d ", root);
	for (int i = 0; i < MAX_CHILD_NUM; ++i) {
		int child = tree[root].child[i];
		if (child != -1)
			preOrder(child);
	}
}
void inOrder(int root) {
	// LVR
	int leftNode = tree[root].child[0];
	int rightNode = tree[root].child[1];
	if (leftNode != -1)
		inOrder(leftNode);
	printf("%d ", root);
	if (rightNode != -1)
		inOrder(rightNode);
}
void postOrder(int root) {
	// LRV
	int leftNode = tree[root].child[0];
	int rightNode = tree[root].child[1];
	if (leftNode != -1)
		inOrder(leftNode);
	if (rightNode != -1)
		inOrder(rightNode);
	printf("%d ", root);
}
int main(void)
{
	int testCase;
	int parent, child;
	scanf(" %d", &testCase);

	for (int t = 0; t < 1; ++t) {
		scanf(" %d %d", &nodeNum, &edgeNum);
		initTree();
		for (int i = 0; i < edgeNum; ++i) {
			scanf(" %d %d", &parent, &child);
			addChild(parent, child);
		}

		root = getRoot();
		printf("#%d ", t+1);
		preOrder(root);
		printf("\n");
		printf("#%d ", t + 1);
		inOrder(root);
		printf("\n");
		printf("#%d ", t + 1);
		postOrder(root);
		printf("\n");
	}
	return 0;
}