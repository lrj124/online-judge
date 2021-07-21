/************************************************
*Author        :  lrj124
*Created Time  :  2020.08.17.08:35
*Mail          :  1584634848@qq.com
*Problem       :  luogu6098
************************************************/
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
int n,q,cnt,val[maxn],dep[maxn],father[maxn],top[maxn],son[maxn],dfn[maxn],siz[maxn],map[maxn];
vector<int> edge[maxn];
inline void dfs1(int now,int fa) {
	father[now] = fa;
	siz[now] = 1;
	dep[now] = dep[fa]+1;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ fa) {
			dfs1(to,now);
			siz[now] += siz[to];
			if (siz[son[now]] < siz[to]) son[now] = to;
		}
	}
}
inline void dfs2(int now,int ntop) {
	dfn[now] = ++cnt;
	map[cnt] = now;
	top[now] = ntop;
	if (son[now]) dfs2(son[now],ntop);
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ father[now] && to ^ son[now]) dfs2(to,to);
	}
}
int tree[maxn<<2];
inline void pushup(int root) { tree[root] = tree[root<<1]^tree[root<<1|1]; }
inline void build(int l,int r,int root) {
	if (l == r) {
		tree[root] = val[map[l]];
		return;
	}
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline void update(int l,int r,int num,int root,int x) {
	if (l > num || r < num) return;
	if (l == r) {
		tree[root] = x;
		return;
	}
	int mid = l+r>>1;
	update(l,mid,num,root<<1,x);
	update(mid+1,r,num,root<<1|1,x);
	pushup(root);
}
inline int query(int l,int r,int ql,int qr,int root) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return tree[root];
	int mid = l+r>>1;
	return query(l,mid,ql,qr,root<<1)^query(mid+1,r,ql,qr,root<<1|1);
}
inline int query_edge(int u,int v) {
	int ans = 0;
	for (;top[u] ^ top[v];u = father[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		ans ^= query(1,n,dfn[top[u]],dfn[u],1);
	}
	if (dep[u] > dep[v]) swap(u,v);
	return ans^query(1,n,dfn[u],dfn[v],1);
}
int main() {
	freopen("luogu6098.in","r",stdin);
	freopen("luogu6098.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++) scanf("%d",&val[i]);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,n,1);
	for (int op,x,y;q--;) {
		scanf("%d%d%d",&op,&x,&y);
		if (op == 1) update(1,n,dfn[x],1,y);
		else printf("%d\n",query_edge(x,y));
	}
	return 0;
}
