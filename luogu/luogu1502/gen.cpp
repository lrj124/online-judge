#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("luogu1502.in","w",stdout);
	srand(time(NULL));
	int n = 10,w = 10,h = 10;
	printf("3\n%d %d %d\n",n,w,h);
	for (int i = 1;i <= n;i++) {
		printf("%d %d %d\n",rand()%(10)+1,rand()%(10)+1,rand()%20+1);
	}
	printf("%d %d %d\n",n,w,h);
	for (int i = 1;i <= n;i++) {
		printf("%d %d %d\n",rand()%(10)+1,rand()%(10)+1,rand()%20+1);
	}
	printf("%d %d %d\n",n,w,h);
	for (int i = 1;i <= n;i++) {
		printf("%d %d %d\n",rand()%(10)+1,rand()%(10)+1,rand()%20+1);
	}
	return 0;
}
