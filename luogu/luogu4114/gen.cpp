#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("luogu4114.in","w",stdout);
	srand(time(NULL));
	int n = 5,q = 5;
	printf("%d\n",n);
	for (int i = 2;i <= n;i++) {
		printf("%d %d %d\n",i,rand()%(i-1)+1,rand()%10);
	}
	for (int x,y;q--;) {
		x = rand()%n+1;
		y = rand()%n+1;
		if (rand()%3 == 0) printf("QUERY %d %d\n",x,y);
		else printf("CHANGE %d %d\n",x,rand()%10);
	}
	printf("DONE");
	return 0;
}
