/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.20.17:17
*Mail          :  1584634848@qq.com
*Problem       :  luogu1196
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 30000 + 10;
int T,f[maxn],size[maxn],dis[maxn];
inline int find(int x) {
	if (f[x] == x) return x;
	int fa = find(f[x]);
	dis[x] += dis[f[x]];
	return f[x] = fa;
}
int main() {
	freopen("luogu1196.in","r",stdin);
	freopen("luogu1196.out","w",stdout);
	for (int i = 1;i < maxn;size[i] = 1,i++) f[i] = i;
	for (scanf("%d\n",&T);T--;) {
		char op; int x,y;
		scanf("%c%d%d\n",&op,&x,&y);
		if (op == 'M') {
			x = find(x);
			y = find(y);
			f[x] = y;
			dis[x] += size[y];
			size[y] += size[x];
			size[x] = 0;
		} else
			if (find(x) ^ find(y)) printf("-1\n");
			else printf("%d\n",max(dis[x]-dis[y],dis[y]-dis[x])-1);
	}
	return 0;
}
