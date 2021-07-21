/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.21.20:53
*Mail          :  1584634848@qq.com
*Problem       :  cf832d
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
int n,q,dep[maxn],father[maxn][20],fir[maxn],cnt;
struct Edge { int to,nex; } eg[maxn<<1];
inline void addedge(int u,int v) {
	eg[++cnt] = {v,fir[u]}; fir[u] = cnt;
	eg[++cnt] = {u,fir[v]}; fir[v] = cnt;
}
inline void dfs(int now,int fa) {
	dep[now] = dep[fa]+1;
	father[now][0] = fa;
	for (int i = fir[now];i;i = eg[i].nex)
		if (eg[i].to ^ fa) dfs(eg[i].to,now);
}
inline void init() {
	for (int j = 1;j <= 17;j++)
		for (int i = 1;i <= n;i++) father[i][j] = father[father[i][j-1]][j-1];
}
inline int lca(int u,int v) {
	if (dep[u] < dep[v]) swap(u,v);
	for (int i = 17;~i;i--)
		if (dep[father[u][i]] >= dep[v]) u = father[u][i];
	if (u == v) return u;
	for (int i = 17;~i;i--)
		if (father[u][i] ^ father[v][i]) {
			u = father[u][i];
			v = father[v][i];
		}
	return father[u][0];
}
inline int calc(int a,int b,int c) {
	int dis1 = dep[a]+dep[b]-(dep[lca(a,b)]<<1);
	int dis2 = dep[a]+dep[c]-(dep[lca(a,c)]<<1);
	int dis3 = dep[b]+dep[c]-(dep[lca(b,c)]<<1);
	return dis1+dis2-dis3>>1;
}
int main() {
	freopen("cf832d.in","r",stdin);
	freopen("cf832d.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 2,x;i <= n;i++) {
		scanf("%d",&x);
		addedge(i,x);
	}
	dfs(1,0);
	init();
	for (int a,b,c;q--;printf("%d\n",max(calc(a,b,c),max(calc(c,a,b),calc(b,a,c)))+1)) scanf("%d%d%d",&a,&b,&c);
	return 0;
}
