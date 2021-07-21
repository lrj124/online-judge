/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.10.21:11
*Mail          :  1584634848@qq.com
*Problem       :  luogu3280
************************************************/
#include <algorithm>
#include <cstring>
#include <cstdio>
#define int ll
using ll = long long;
using namespace std;
const ll inf = 100000000000000ll;
const int maxn = 100000 + 10;
int egcnt,n,m,q,cnt,per[maxn],dep[maxn],father[maxn],top[maxn],num[maxn],val[maxn],Map[maxn],siz[maxn],son[maxn],fir[maxn];
struct Edge { int to,nex; ll w; } eg[maxn];
ll minv[maxn<<2],w[maxn];
struct Road {
	int u,v; ll w;
	inline bool operator < (Road cmp) {
		return w > cmp.w;
	}
} edge[maxn*3];
inline void addedge(int u,int v,ll w) {
	eg[++egcnt] = {v,fir[u],w}; fir[u] = egcnt;
	eg[++egcnt] = {u,fir[v],w}; fir[v] = egcnt;
}
inline void dfs1(int now,int fa) {
	siz[now] = 1;
	father[now] = fa;
	dep[now] = dep[fa]+1;
	for (int i = fir[now];~i;i = eg[i].nex)
		if (eg[i].to ^ fa) {
			dfs1(eg[i].to,now);
			val[eg[i].to] = eg[i].w;
			siz[now] += siz[eg[i].to];
			if (siz[son[now]] < siz[eg[i].to]) son[now] = eg[i].to;
		}
}
inline void dfs2(int now,int ntop) {
	num[now] = ++cnt;
	Map[cnt] = now;
	top[now] = ntop;
	if (son[now]) dfs2(son[now],ntop);
	for (int i = fir[now];~i;i = eg[i].nex)
		if (eg[i].to ^ father[now] && eg[i].to ^ son[now]) dfs2(eg[i].to,eg[i].to);
}
inline void pushup(int root) { minv[root] = min(minv[root<<1],minv[root<<1|1]); }
inline void build(int l,int r,int root) {
	if (l == r) {
		minv[root] = val[Map[l]];
		return;
	}
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline ll query(int l,int r,int ql,int qr,int root) {
	if (l > qr || r < ql) return inf;
	if (ql <= l && r <= qr)  return minv[root];
	int mid = l+r>>1;
	return min(query(l,mid,ql,qr,root<<1),query(mid+1,r,ql,qr,root<<1|1));
}
inline ll query_edge(int u,int v) {
	ll ans = inf;
	for (;top[u] ^ top[v];u = father[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		ans = min(ans,query(1,n,num[top[u]],num[u],1));
	}
	if (dep[u] > dep[v]) swap(u,v);
	return min(ans,query(1,n,num[u]+1,num[v],1));
}
inline int find(int x) { return father[x] = father[x] == x ? x : find(father[x]); }
inline void kruskal() {
	for (int i = 1;i <= n;i++) father[i] = i;
	if (!q) q = 1;
	int cnt = 0;
	sort(edge+1,edge+m+q);
	for (int i = 1,x,y;i <= m+q-1;i++) {
		x = find(edge[i].u);
		y = find(edge[i].v);
		if (x ^ y) {
			father[x] = y;
			addedge(edge[i].u,edge[i].v,edge[i].w);
			cnt++;
		}
		if (cnt == n-1) break;
	}
	memset(father,0,sizeof(father));
}
signed main() {
	freopen("luogu3280.in","r",stdin);
	freopen("luogu3280.out","w",stdout);
	memset(fir,-1,sizeof(fir));
	scanf("%lld%lld%lld",&n,&m,&q);
	for (int i = 1;i <= n;i++) scanf("%lld",&per[i]);
	for (int i = 1;i <= n;i++) scanf("%lld",&w[i]);
	for (int i = 1;i <= m;i++) scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	for (int i = 1,x,y;i <= q;i++) { scanf("%lld",&x); if (i ^ 1) edge[m+i-1] = {x,y,inf}; y = x; }
	kruskal();
	dfs1(1,0);
	dfs2(1,1);
	build(1,n,1);
	ll now = 0;
	for (int i = 1;i < n;i++)
		if (w[per[i]] > 0) now = min(now+w[per[i]],query_edge(per[i],per[i+1]));
		else {
			printf("%lld\n",min(-w[per[i]],now));
			now = min(max(0ll,now+w[per[i]]),query_edge(per[i],per[i+1]));
		}
	if (w[per[n]] < 0) printf("%lld",min(-w[per[n]],now));
	return 0;
}
