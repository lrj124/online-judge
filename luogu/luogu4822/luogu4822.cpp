#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxn = 10000 + 10;
const ll inf = (ll)1e15;
struct edge { int to,nex; ll w; } eg[maxn<<5];
int n,m,k,fir[maxn],egcnt;
bool vis[maxn];
ll dis[maxn];
inline void addedge(int u,int v,ll w) { eg[++egcnt] = { v,fir[u],w }; fir[u] = egcnt; }
priority_queue<pii,vector<pii>,greater<pii> > q;
inline void dijkstra(int s) {
	for (int i = 1;i <= n*(k+1);i++) dis[i] = inf;
	q.push(make_pair(0,s));
	dis[s] = 0;
	for (int now;q.size();) {
		now = q.top().second; q.pop();
		if (vis[now]) continue;
		vis[now] = true;
		for (int i = fir[now];~i;i = eg[i].nex)
			if (dis[eg[i].to] > dis[now]+eg[i].w) {
				dis[eg[i].to] = dis[now]+eg[i].w;
				q.push(make_pair(dis[eg[i].to],eg[i].to));
			}
	}
}
int main() {
	memset(fir,-1,sizeof(fir));
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1,u,v;i <= m;i++) {
        ll w; scanf("%d%d%lld",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
		for (int j = 1;j <= k;addedge(j*n+u,j*n+v,w),addedge(j*n+v,j*n+u,w),addedge((j-1)*n+u,j*n+v,w>>1),addedge((j-1)*n+v,j*n+u,w>>1),j++);
	}
	dijkstra(1);
	ll ans = dis[n];
	for (int i = 1;i <= k+1;i++) ans = min(ans,dis[i*n]);
	printf("%lld",ans);
	return 0;
}
