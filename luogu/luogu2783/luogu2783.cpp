//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;
const int maxn = 1e5 + 10;
int n,m,q,tot,cnt(1),fir[maxn],low[maxn],dfn[maxn],col[maxn],siz[maxn],dep[maxn],fa[maxn][25],dis[maxn];
struct { int to,nex; } eg[maxn<<1];
map<pair<int,int>,bool > mp;
vector<int> edge[maxn];
bool cut[maxn];
inline void addedge(int u,int v) {
	if (u > v) swap(u,v);
	if (!mp[make_pair(u,v)]) {
		eg[++cnt] = { v,fir[u] }; fir[u] = cnt;
		eg[++cnt] = { u,fir[v] }; fir[v] = cnt;
		mp[make_pair(u,v)] = true;
	}
}
inline void tarjan(int now,int fa) {
	dfn[now] = low[now] = ++tot;
	for (int i = fir[now];i;i = eg[i].nex)
		if (!dfn[eg[i].to]) {
			tarjan(eg[i].to,now);
			low[now] = min(low[now],low[eg[i].to]);
			if (low[eg[i].to] > dfn[now]) cut[i] = cut[i^1] = true;
		} else if (eg[i].to ^ fa) low[now] = min(low[now],dfn[eg[i].to]);
}
inline void color(int now,int tmp) {
	col[now] = tmp;
	for (int i = fir[now];i;i = eg[i].nex)
		if (!col[eg[i].to] && !cut[i]) color(eg[i].to,tmp);
}
inline void dfs(int now,int f) {
	dep[now] = dep[f]+1;
	fa[now][0] = f;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ f) dfs(to,now);
	}
}
inline void init() {
	for (int j = 1;j <= 20;j++)
		for (int i = 1;i <= n;i++) fa[i][j] = fa[fa[i][j-1]][j-1];
}
inline int lca(int u,int v) {
	if (dep[u] < dep[v]) swap(u,v);
	for (int i = 20;~i;i--)
		if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if (u == v) return u;
	for (int i = 20;~i;i--)
		if (fa[u][i] ^ fa[v][i]) { u = fa[u][i]; v = fa[v][i]; }
	return fa[u][0];
}
inline int dista(int u,int v) {
	int f = lca(u,v);
	return dep[u]+dep[v]-2*dep[f]+1;
}
inline string to_01(int x) {
	bool flag = false;
	string ans = "";
	for (int i = 31;~i;i--) {
		if (!(x&(1<<i)) && flag) ans += "0";
		if (x&(1<<i)) { flag = 1; ans += "1"; }
	}
	return ans;
}
int main() {
	freopen("luogu2783.in","r",stdin);
	freopen("luogu2783.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1,u,v;i <= m;i++) { scanf("%d%d",&u,&v); addedge(u,v); }
	for (int i = 1;i <= n;i++) if (!dfn[i]) tarjan(i,0);
	for (int i = 1,tmp = 0;i <= n;i++) if (!col[i]) color(i,++tmp);
	for (int i = 1;i <= n;i++)
		for (int j = fir[i];j;j = eg[j].nex)
			if (col[i] ^ col[eg[j].to]) edge[col[i]].push_back(col[eg[j].to]);
	dfs(1,0);
	init();
	for (scanf("%d",&q);q--;) {
		int u,v; scanf("%d%d",&u,&v);
		printf("%s\n",to_01(dista(col[u],col[v])).c_str());
	}
	return 0;
}
