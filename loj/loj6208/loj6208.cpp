//2021.07.17 08:45 by lrj124.
#include <algorithm>
#include <cstdarg>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int n,m,cnt,fa[maxn],son[maxn],top[maxn],dfn[maxn],dep[maxn],siz[maxn];
vector<int> edge[maxn];
inline void init(int now,int f) {
	dep[now] = dep[f]+1;
	fa[now] = f;
	siz[now] = 1;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ f) {
			init(to,now);
			siz[now] += siz[to];
			if (siz[to] > siz[son[now]]) son[now] = to;
		}
	}
}
inline void dfs(int now,int las) {
	dfn[now] = ++cnt;
	top[now] = las;
	if (son[now]) dfs(son[now],las);
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ fa[now] && to ^ son[now]) dfs(to,to);
	}
}
struct matrix {
	int n,m,a[4][4];
	inline void clear() { n = m = 0; memset(a,0,sizeof a); }
	inline bool operator != (matrix x) const {
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				if (a[i][j] ^ x.a[i][j]) return true;
		return false;
	}
	inline matrix operator + (matrix x) const {
		matrix ans; ans.clear();
		ans.n = n; ans.m = m;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++) ans.a[i][j] = a[i][j]+x.a[i][j];
		return ans;
	}
	inline matrix operator * (matrix x) const {
		matrix ans; ans.clear();
		ans.n = n; ans.m = x.m;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= x.m;j++)
				for (int k = 1;k <= m;k++) ans.a[i][j] += a[i][k]*x.a[k][j];
		return ans;
	}
} e,sum[maxn<<2],laz[maxn<<2];
inline matrix set(int r,int c,...) {
	matrix ans; ans.n = r; ans.m = c;
	va_list args; va_start(args,r*c);
	for (int i = 1;i <= ans.n;i++)
		for (int j = 1;j <= ans.m;j++) ans.a[i][j] = va_arg(args,int);
	va_end(args);
	return ans;
}
inline void pushup(int root) { sum[root] = sum[root<<1]+sum[root<<1|1]; }
inline void pushdown(int root) {
	if (laz[root] != e) {
		sum[root<<1] = sum[root<<1]*laz[root];
		laz[root<<1] = laz[root<<1]*laz[root];
		sum[root<<1|1] = sum[root<<1|1]*laz[root];
		laz[root<<1|1] = laz[root<<1|1]*laz[root];
		laz[root] = e;
	}
}
inline void build(int l,int r,int root) {
	laz[root] = e;
	if (l == r) return sum[root] = set(1,3,0,0,1),void();
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline void update(int l,int r,int ql,int qr,int root,matrix x) {
	if (l > qr || r < ql) return;
	if (ql <= l && r <= qr) {
		sum[root] = sum[root]*x;
		laz[root] = laz[root]*x;
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	update(l,mid,ql,qr,root<<1,x);
	update(mid+1,r,ql,qr,root<<1|1,x);
	pushup(root);
}
inline matrix query(int l,int r,int num,int root) {
	if (l == r) return sum[root];
	pushdown(root);
	int mid = l+r>>1;
	if (mid >= num) return query(l,mid,num,root<<1);
	return query(mid+1,r,num,root<<1|1);
}
inline void update_edge(int u,int v,matrix x) {
	for (;top[u] ^ top[v];u = fa[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		update(1,n,dfn[top[u]],dfn[u],1,x);
	}
	if (dep[u] > dep[v]) swap(u,v);
	return update(1,n,dfn[u],dfn[v],1,x);
}
int main() {
	scanf("%d",&n);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	e = set(3,3,1,0,0,0,1,0,0,0,1);
	init(1,0);
	dfs(1,1);
	build(1,n,1);
	for (scanf("%d",&m);m--;) {
		int o,x,d;
		scanf("%d%d",&o,&x);
		if (o == 1) {
			scanf("%d",&d);
			update_edge(1,x,set(3,3,1,0,0,0,1,0,d,0,1));
		} else if (o == 2) {
			scanf("%d",&d);
			update_edge(1,x,set(3,3,1,d,0,0,1,0,0,0,1));
		} else {
			matrix res = query(1,n,dfn[x],1);
			printf("%d\n",query(1,n,dfn[x],1).a[1][2]);
		}
	}
	return 0;
}
