/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.03.14:47
*Mail          :  1584634848@qq.com
*Problem       :  luogu4281
************************************************/
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 500000 + 10;
int n,m,dep[maxn],siz[maxn],top[maxn],father[maxn],son[maxn];
vector<int> edge[maxn];
inline void dfs(int now,int fa) {
	siz[now] = 1;
	father[now] = fa;
	dep[now] = dep[fa]+1;
	for (size_t i = 0;i < edge[now].size();i++)
		if (edge[now][i] ^ fa) {
			dfs(edge[now][i],now);
			siz[now] += siz[edge[now][i]];
			if (siz[son[now]] < siz[edge[now][i]]) son[now] = edge[now][i];
		}
}
inline void dfs2(int now,int ntop) {
	top[now] = ntop;
	if (son[now]) dfs2(son[now],ntop);
	for (size_t i = 0;i < edge[now].size();i++)
		if (edge[now][i] ^ father[now] && edge[now][i] ^ son[now]) dfs2(edge[now][i],edge[now][i]);
}
inline int lca(int u,int v) {
	for (;top[u] ^ top[v];u = father[top[u]])
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
	if (dep[u] > dep[v]) swap(u,v);
	return u;
}
inline int dist(int u,int v) { return dep[u]+dep[v]-(dep[lca(u,v)]<<1); }
inline int solve(int a,int b,int c) {
	int g1 = lca(a,b),g2 = lca(b,c),g3 = lca(a,c);
	int v1 = dist(a,g1)+dist(b,g1)+dist(c,g1);
	int v2 = dist(a,g2)+dist(b,g2)+dist(c,g2);
	int v3 = dist(a,g3)+dist(b,g3)+dist(c,g3);
	if (v1 < v2 && v1 < v3) return printf("%d %d\n",g1,v1);
	if (v2 < v1 && v2 < v3) return printf("%d %d\n",g2,v2);
	return printf("%d %d\n",g3,v3);
}
int main() {
	freopen("luogu4281.in","r",stdin);
	freopen("luogu4281.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,1);
	for (int a,b,c;m--;) {
		scanf("%d%d%d",&a,&b,&c);
		solve(a,b,c);
	}
	return 0;
}
