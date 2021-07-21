//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 5000 + 10;
int n,m,ans,tot,cnt(1),fir[maxn],low[maxn],dfn[maxn],col[maxn],deg[maxn];
struct { int to,nex; } eg[maxn<<1];
vector<int> edge[maxn];
bool cut[maxn];
inline void addedge(int u,int v) {
	eg[++cnt] = { v,fir[u] }; fir[u] = cnt;
	eg[++cnt] = { u,fir[v] }; fir[v] = cnt;
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
inline void dfs(int now,int tmp) {
	col[now] = tmp;
	for (int i = fir[now];i;i = eg[i].nex)
		if (!col[eg[i].to] && !cut[i]) dfs(eg[i].to,tmp);
}
int main() {
	freopen("luogu2860.in","r",stdin);
	freopen("luogu2860.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1,u,v;i <= m;i++) { scanf("%d%d",&u,&v); addedge(u,v); }
	for (int i = 1;i <= n;i++) if (!dfn[i]) tarjan(i,0);
	for (int i = 1,tmp = 0;i <= n;i++) if (!col[i]) dfs(i,++tmp);
	for (int i = 1;i <= n;i++)
		for (int j = fir[i];j;j = eg[j].nex)
			if (col[i] ^ col[eg[j].to]) {
				edge[col[i]].push_back(col[eg[j].to]);
				edge[col[eg[j].to]].push_back(col[i]);
			}
	for (int i = 1;i <= tot;i++) {
		sort(edge[i].begin(),edge[i].end());
		int cnt = unique(edge[i].begin(),edge[i].end())-edge[i].begin();
		for (int j = 0;j < cnt;j++) deg[edge[i][j]]++;
	}
	for (int i = 1;i <= tot;i++) if (deg[i] == 1) ans++;
	printf("%d",ans+1>>1);
	return 0;
}
