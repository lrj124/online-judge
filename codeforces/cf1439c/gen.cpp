//I am hunting for the golden stag.
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("in.in","w",stdout);
	srand(time(NULL));
	int n = 100,m = 100,a[101];
	printf("%d %d\n",n,m);
	for (int i = 1;i <= n;i++) a[i] = rand()%40;
	sort(a+1,a+n+1,greater<int>());
	for (int i = 1;i <= n;i++) printf("%d ",a[i]);
	puts("");
	for (int i = 1;i <= m;i++) {
		int o = rand()%4 ? 2 : 1;
		printf("%d %d %d\n",o,rand()%n+1,rand()%500);
	}
	return 0;
}
