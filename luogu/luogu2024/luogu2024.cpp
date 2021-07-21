/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.16.14:32
*Mail          :  1584634848@qq.com
*Problem       :  luogu2024
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 10;
int n,k,f[maxn*3],ans;
//f[x]   is oneself
//f[x+n] is food
//f[x+n+n] is foe
inline int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }
inline void Union(int x,int y) { x = find(x); y = find(y); f[x] = y; }
int main() {
	freopen("luogu2024.in","r",stdin);
	freopen("luogu2024.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n*3;i++) f[i] = i;
	for (int op,x,y;k--;) {
		scanf("%d%d%d",&op,&x,&y);
		if (x > n || y > n) { ans++; continue; }
		if (op == 1) {
			if (find(x+n) == find(y) || find(x+n+n) == find(y)) { ans++; continue; }
			Union(x,y); Union(x+n,y+n); Union(x+n+n,y+n+n);
		} else {
			if (find(x) == find(y) || find(x+n+n) == find(y)) { ans++; continue; }
			Union(x+n,y); Union(x,y+n+n); Union(x+n+n,y+n);
		}
	}
	printf("%d",ans);
	return 0;
}
