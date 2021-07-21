/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.29.15:31
*Mail          :  1584634848@qq.com
*Problem       :  luogu3398
************************************************/
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100000 + 10;
vector<int> edge[maxn];
int n,q,dep[maxn],father[maxn][20];
inline void dfs(int now,int fa) {
	dep[now] = dep[fa]+1;
	father[now][0] = fa;
	for (size_t i = 0;i < edge[now].size();i++)
		if (edge[now][i] ^ fa) dfs(edge[now][i],now);
}
inline void init() {
	for (int j = 1;j <= 18;j++)
		for (int i = 1;i <= n;i++) father[i][j] = father[father[i][j-1]][j-1];
}
inline int lca(int u,int v) {
	if (dep[u] < dep[v]) swap(u,v);
	for (int i = 18;~i;i--)
		if (dep[father[u][i]] >= dep[v]) u = father[u][i];
	if (u == v) return u;
	for (int i = 18;~i;i--)
		if (father[u][i] ^ father[v][i]) {
			u = father[u][i];
			v = father[v][i];
		}
	return father[u][0];
}
inline int dis(int u,int v) { return dep[u]+dep[v]-dep[lca(u,v)]*2; }
int main() {
	freopen("luogu3398.in","r",stdin);
	freopen("luogu3398.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	init();
	for (int u,v,a,b,x,y;q--;) {
		scanf("%d%d%d%d",&u,&v,&a,&b);
		x = lca(u,v);
		y = lca(a,b);
		puts(dis(a,x)+dis(x,b) == dis(a,b) || dis(u,y)+dis(y,v) == dis(u,v) ? "Y" : "N");
	}
	return 0;
}
