#include <bits/stdc++.h>
bool vis[100][100];
int n,m,k;
int main() {
	freopen("luogu6378.in","w",stdout);
	srand(time(NULL));
	n = 4,m = 5,k = 2;
	printf("%d %d %d\n",n,m,k);
	for (int i = 2;i <= n;i++) {
		int u = i,v = rand()%(i-1)+1;
		vis[u][v] = true;
		vis[v][u] = true;
		printf("%d %d\n",u,v);
	}
	for (int i = 1;i <= m-n+1;i++) {
		int u = rand()%n+1,v = rand()%n+1;
		for (;vis[u][v] || u == v;u = rand()%n+1,v = rand()%n+1);
		vis[u][v] = vis[v][u] = true;
		printf("%d %d\n",u,v);
	}
	printf("3 1 2 3\n");
	printf("1 4\n");
	return 0;
}
