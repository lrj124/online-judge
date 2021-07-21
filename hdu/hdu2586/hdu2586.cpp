#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 40000 + 10;
int T,n,m,dep[maxn],dis[maxn],fa[maxn][25];
vector<pair<int,int> > edge[maxn];
inline void dfs(int now,int f) {
	fa[now][0] = f;
	dep[now] = dep[f]+1;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i].first,w = edge[now][i].second;
		if (to ^ f) {
			dis[to] = dis[now]+w;
			dfs(to,now);
		}
	}
}
inline void init() {
	for (int j = 1;(1<<j) <= n;j++)
		for (int i = 1;i <= n;i++) fa[i][j] = fa[fa[i][j-1]][j-1];
}
inline int lca(int u,int v) {
	if (dep[u] < dep[v]) swap(u,v);
	for (int i = 20;i >= 0;i--)
		if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if (u == v) return u;
	for (int i = 20;i >= 0;i--)
		if (fa[u][i] ^ fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	return fa[u][0];
}
int main() {
	freopen("hdu2586.in","r",stdin);
	freopen("hdu2586.out","w",stdout);
	for (scanf("%d",&T);T--;) {
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++) {
			edge[i].clear();
			dis[i] = dep[i] = 0;
			for (int j = 0;j <= 20;j++) fa[i][j] = 0;
		}
		for (int i = 1,u,v,w;i < n;i++) {
			scanf("%d%d%d",&u,&v,&w);
			edge[u].push_back(make_pair(v,w));
			edge[v].push_back(make_pair(u,w));
		}
		dfs(1,0);
		init();
		for (int u,v;m--;) {
			scanf("%d%d",&u,&v);
			printf("%d\n",dis[u]+dis[v]-(dis[lca(u,v)]<<1));
		}
	}
	return 0;
}
