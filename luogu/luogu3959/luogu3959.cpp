//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 12 + 1;
const int inf = 1e8;
int n,m,ans(inf),f[1<<maxn],dis[maxn],edg[maxn][maxn];
inline void dfs(int s) {
	for (register int i = 1;i <= n;i++) if (s>>(i-1)&1)
		for (register int to = 1;to <= n;to++)
			if (edg[i][to] ^ inf && !(s>>(to-1)&1) && f[s|(1<<(to-1))] > f[s]+dis[to]*edg[i][to]) {
				dis[to] = dis[i]+1;
				f[s|(1<<(to-1))] = f[s]+dis[to]*edg[i][to];
				dfs(s|(1<<(to-1)));
			}
}
int main() {
	freopen("luogu3959.in","r",stdin);
	freopen("luogu3959.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) edg[i][j] = inf;
	for (int i = 1,u,v,w;i <= m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		edg[u][v] = edg[v][u] = min(edg[u][v],w);
	}
	for (int st = 1;st <= n;st++) {
		fill(f,f+(1<<n),inf);
		f[1<<(st-1)] = dis[st] = 0;
		dfs(1<<(st-1));
		ans = min(ans,f[(1<<n)-1]);
	}
	printf("%d",ans);
	return 0;
}
