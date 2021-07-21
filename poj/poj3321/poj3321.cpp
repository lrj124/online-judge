#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn = 100000 + 10;
int n,m,dfn[maxn],edgecnt,size[maxn],cnt,first[maxn],tree[maxn];
struct edge { int to,next; } eg[maxn<<2];
inline void addedge(int u,int v) {
	eg[++edgecnt] = (edge){v,first[u]};
	first[u] = edgecnt;
}
inline void dfs(int now,int f) {
	dfn[now] = ++cnt;
	size[now] = 1;
	for (int i = first[now];~i;i = eg[i].next)
		if (eg[i].to ^ f) {
			dfs(eg[i].to,now);
			size[now] += size[eg[i].to];
		}
}
inline void modif(int x,int v) { for (;x <= n;x += lowbit(x)) tree[x] += v; }
inline int query(int x) { int ans = 0; for (;x;x -= lowbit(x)) ans += tree[x]; return ans; }
inline int read() {
	int x,p = 1;
	char ch;
	while ((ch = getchar()) < '0' || ch > '9') if (ch == '-') p = -1;
	x = ch-'0';
	while ((ch = getchar()) >= '0' && ch <= '9') x = x*10+ch-'0';
	return x*p;
}
int main() {
	memset(first,-1,sizeof(first));
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) modif(i,1);
	for (int i = 1,u,v;i < n;i++) {
		u = read(),v = read();
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,0);
	for (scanf("%d",&m);m--;) {
		char ch; int x; while ((ch = getchar()) ^ 'C' && ch ^ 'Q'); x = read();
		if (ch == 'C') query(dfn[x])-query(dfn[x]-1) ? modif(dfn[x],-1) : modif(dfn[x],1);
		else printf("%d\n",query(dfn[x]+size[x]-1)-query(dfn[x]-1));
	}
	return 0;
}
