#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("luogu4416.in","w",stdout);
	srand(time(NULL));
	int n = 20,q = 30;
	printf("%d %d\n",n,q);
	for (int i = 2;i <= n;i++) printf("%d %d\n",i,n%(i-1)+1);
	puts("");
	for (int i = 1;i <= q;i++) printf("%d %d\n",rand()%2,rand()%n+1);
	return 0;
}
