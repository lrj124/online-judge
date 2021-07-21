//I am hunting for the golden stag.
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
int n,nod,rot,cnt,tot,ls[maxn<<2],rs[maxn<<2],dfn[maxn<<2],low[maxn<<2],scc[maxn<<2],siz[maxn<<2],lef[maxn<<2],rig[maxn<<2],ll[maxn<<2],rr[maxn<<2];
vector<int> edge[maxn<<2],e[maxn<<2];
stack<int> s; bool vis[maxn<<2];
struct boom {
	long long num,x,r;
	inline bool operator < (boom cmp) const {
		return x < cmp.x;
	}
} p[maxn<<2];
inline void build(int l,int r,int& root) {
	if (l == r) return void(root = l);
	root = ++nod; ll[root] = l,rr[root] = r;
	int mid = l+r>>1;
	build(l,mid,ls[root]);
	build(mid+1,r,rs[root]);
	edge[root].push_back(ls[root]);
	edge[root].push_back(rs[root]);
}
inline void update(int l,int r,int u,int vl,int vr,int root) {
	if (l > vr || r < vl) return;
	if (vl <= l && r <= vr) return void(edge[u].push_back(root));
	int mid = l+r>>1;
	update(l,mid,u,vl,vr,ls[root]);
	update(mid+1,r,u,vl,vr,rs[root]);
}
inline void tarjan(int now) {
	low[now] = dfn[now] = ++cnt;
	s.push(now); vis[now] = true;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (!dfn[to]) {
			tarjan(to);
			low[now] = min(low[now],low[to]);
		} else if (vis[to]) low[now] = min(low[now],dfn[to]);
	}
	if (low[now] == dfn[now]) {
		for (tot++;s.top() ^ now;vis[s.top()] = false,s.pop()) {
			scc[s.top()] = tot;
			lef[tot] = min(lef[tot],ll[s.top()]);
			rig[tot] = max(rig[tot],rr[s.top()]);
		}
		lef[tot] = min(lef[tot],ll[s.top()]);
		rig[tot] = max(rig[tot],rr[s.top()]);
		scc[s.top()] = tot;
		vis[s.top()] = false,s.pop();
	}
}
inline void dfs(int now) {
	vis[now] = true;
	for (size_t i = 0;i < e[now].size();i++) {
		int to = e[now][i];
		if (!vis[to]) dfs(to);
		lef[now] = min(lef[now],lef[to]);
		rig[now] = max(rig[now],rig[to]);
	}
}
signed main() {
	freopen("luogu5025.in","r",stdin);
	freopen("luogu5025.out","w",stdout);
	scanf("%d",&n); fill(lef+1,lef+n+n+1,n+1);
	for (int i = 1;i <= n;i++) { p[i].num = i; scanf("%lld%lld",&p[i].x,&p[i].r); }
	sort(p+1,p+n+1); nod = n; build(1,n,rot);
	for (int i = 1,u,v;i <= n;i++) {
		u = lower_bound(p+1,p+n+1,(boom){0,p[i].x-p[i].r,0})-p;
		v = upper_bound(p+1,p+n+1,(boom){0,p[i].x+p[i].r,0})-p-1;
		update(1,n,i,u,v,rot);
		ll[i] = u,rr[i] = v;
	}
	for (int i = 1;i <= n;i++) if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= n;i++)
		for (size_t j = 0;j < edge[i].size();j++) {
			int to = edge[i][j];
			if (scc[i] ^ scc[to] && to <= n) e[scc[i]].push_back(scc[to]);
		}
	fill(vis+1,vis+n+n+1,false);
	for (int i = 1;i <= tot;i++) if (!vis[i]) dfs(i);
	long long sum = 0;
	for (int i = 1;i <= n;i++) (sum += 1ll*p[i].num*(rig[scc[i]]-lef[scc[i]]+1)%mod) %= mod;
	printf("%lld",sum);
	return 0;
}
