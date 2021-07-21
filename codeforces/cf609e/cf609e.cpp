/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.20.08:29
*Mail          :  1584634848@qq.com
*Problem       :  cf609e
************************************************/
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#define int long long
using namespace std;
const int maxn = 200000 + 10;
int n,m,cnt,mst,ans[maxn],Map[maxn],num[maxn],dep[maxn],val[maxn],father[maxn],top[maxn],son[maxn],siz[maxn];
vector<pair<int,int> > edge[maxn];
struct road {
	int u,v,w,num;
	inline bool operator < (road cmp) const {
		return w < cmp.w;
	}
} eg[maxn];
inline int find(int x) { return father[x] = father[x] == x ? x : find(father[x]); }
inline void Kruskal() {
	for (int i = 1;i <= n;i++) father[i] = i;
	sort(eg+1,eg+m+1);
	for (int i = 1,x,y;i <= m;i++) {
		x = find(eg[i].u);
		y = find(eg[i].v);
		if (x ^ y) {
			father[x] = y;
			mst += eg[i].w;
			edge[eg[i].u].push_back(make_pair(eg[i].v,eg[i].w));
			edge[eg[i].v].push_back(make_pair(eg[i].u,eg[i].w));
			if (++cnt == n-1)  break;
		}
	}
	cnt = 0;
	memset(father,0,sizeof(father));
}
inline void dfs(int now,int fa) {
	siz[now] = 1;
	father[now] = fa;
	dep[now] = dep[fa]+1;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i].first,w = edge[now][i].second;
		if (to ^ fa) {
			dfs(to,now);
			siz[now] += siz[to];
			val[to] = w;
			if (siz[to] > siz[son[now]]) son[now] = to;
		}
	}
}
inline void dfs2(int now,int ntop) {
	top[now] = ntop;
	num[now] = ++cnt;
	Map[cnt] = now;
	if (son[now]) dfs2(son[now],ntop);
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i].first;
		if (to ^ father[now] && to ^ son[now]) dfs2(to,to);
	}
}
int maxv[maxn<<2];
inline void pushup(int root) { maxv[root] = max(maxv[root<<1],maxv[root<<1|1]); }
inline void build(int l,int r,int root) {
	if (l == r) {
		maxv[root] = val[Map[l]];
		return;
	}
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline int query(int l,int r,int ql,int qr,int root) {
	if (r <  ql || l > qr) return -99999999999999;
	if (ql <= l && r <= qr) return maxv[root];
	int mid = l+r>>1;
	return max(query(l,mid,ql,qr,root<<1),query(mid+1,r,ql,qr,root<<1|1));
}
inline int query_road(int u,int v) {
	int ans = -99999999999999;
	for (;top[u] ^ top[v];u = father[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		ans = max(ans,query(1,n,num[top[u]],num[u],1));
	}
	if (dep[u] > dep[v]) swap(u,v);
	return max(ans,query(1,n,num[u]+1,num[v],1));
}
signed main() {
	freopen("cf609e.in","r",stdin);
	freopen("cf609e.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i = 1;i <= m;i++) {
		scanf("%lld%lld%lld",&eg[i].u,&eg[i].v,&eg[i].w);
		eg[i].num = i;
	}
	Kruskal();
	dfs(1,0);
	dfs2(1,1);
	build(1,n,1);
	for (int i = 1;i <= m;i++) ans[eg[i].num] = mst+eg[i].w-query_road(eg[i].u,eg[i].v);
	for (int i = 1;i <= m;i++) printf("%lld\n",ans[i]);
	return 0;
}
