#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("luogu1505.in","w",stdout);
	srand(time(NULL));
	int n = 20000,q = 20000;
	printf("%d\n",n);
	for (int i = 2;i <= n;i++) {
		int u = i,v = rand()%(i-1)+1;
		printf("%d %d %d\n",u-1,v-1,rand()%10-4);
	}
	printf("%d\n",q);
	for (int r;q--;) {
		r = rand()%5;
		if (r == 0) printf("C %d %d\n",rand()%n,rand()%10-4);
		if (r == 1) printf("N %d %d\n",rand()%n,rand()%n);
		if (r == 2) {
			int x = rand()%n,y = rand()%n;
			for (;x == y;x = rand()%n,y = rand()%n);
			printf("SUM %d %d\n",x,y);
		}
		if (r == 3) {
			int x = rand()%n,y = rand()%n;
			for (;x == y;x = rand()%n,y = rand()%n);
			printf("MAX %d %d\n",x,y);
		}
		if (r == 4) {
			int x = rand()%n,y = rand()%n;
			for (;x == y;x = rand()%n,y = rand()%n);
			printf("MIN %d %d\n",x,y);
		}
	}
	return 0;
}
