#include <cstdio>
#include <vector>

using namespace std;

int A, B;
int main() {

	scanf("%d %d", &A, &B);
	
	switch (A)
	{
	case 1 :
		if (B == 2)
			printf("B");
		else
			printf("A");
		break;
	case 2 :
		if (B == 3)
			printf("B");
		else
			printf("A");
		break;
	case 3 :
		if (B == 1)
			printf("B");
		else
			printf("A");
		break;
	default:
		break;
	}
	
	return 0;
}