//I am hunting for the golden stag.
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int n,m,cnt,nod[maxn],dep[maxn],top[maxn],dfn[maxn],fa[maxn],siz[maxn],son[maxn];
vector<int> edge[maxn],col[maxn];
inline void dfs1(int now,int f) {
	dep[now] = dep[f]+1;
	fa[now] = f;
	siz[now] = 1;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ f) {
			dfs1(to,now);
			siz[now] += siz[to];
			if (siz[to] > siz[son[now]]) son[now] = to;
		}
	}
}
inline void dfs2(int now,int ntop) {
	dfn[now] = ++cnt;
	top[now] = ntop;
	col[nod[now]].push_back(cnt);
	if (son[now]) dfs2(son[now],ntop);
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ fa[now] && to ^ son[now]) dfs2(to,to);
	}
}
inline int query(int u,int v,int w) {
	for (;top[u] ^ top[v];u = fa[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		size_t num = lower_bound(col[w].begin(),col[w].end(),dfn[top[u]])-col[w].begin();
 		if (num < col[w].size() && col[w][num] <= dfn[u]) return 1;
	}
	if (dep[u] > dep[v]) swap(u,v);
	size_t num = lower_bound(col[w].begin(),col[w].end(),dfn[u])-col[w].begin();
	if (num < col[w].size() && col[w][num] <= dfn[v]) return 1;
	return 0;
}
int main() {
	freopen("luogu5838.in","r",stdin);
	freopen("luogu5838.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&nod[i]);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for (int i = 1;i <= n;i++) sort(col[i].begin(),col[i].end());
	for (int u,v,w;m--;) {
		scanf("%d%d%d",&u,&v,&w);
		printf("%d",query(u,v,w));
	}
	return 0;
}
