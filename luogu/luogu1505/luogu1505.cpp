/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.07.14:49
*Mail          :  1584634848@qq.com
*Problem       :  luogu1505
************************************************/
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 20000 + 10;
int n,q,cnt,egcnt,a[maxn],b[maxn],c[maxn],dep[maxn],top[maxn],fa[maxn],size[maxn],son[maxn],num[maxn],fir[maxn];
struct Edge { int to,nex; } eg[maxn<<2];
inline void addedge(int u,int v) {
	eg[++egcnt] = {v,fir[u]}; fir[u] = egcnt;
	eg[++egcnt] = {u,fir[v]}; fir[v] = egcnt;
}
inline void dfs1(int now,int f) {
	dep[now] = dep[f]+1;
	size[now] = 1;
	fa[now] = f;
	for (int i = fir[now];~i;i = eg[i].nex)
		if (eg[i].to  ^ f) {
			dfs1(eg[i].to,now);
			size[now] += size[eg[i].to];
			if (size[eg[i].to] > size[son[now]]) son[now] = eg[i].to;
		}
}
inline void dfs2(int now,int nt) {
	top[now] = nt;
	num[now] = cnt++;
	if (son[now]) dfs2(son[now],nt);
	for (int i = fir[now];~i;i = eg[i].nex)
		if (eg[i].to ^ fa[now] && eg[i].to ^ son[now]) dfs2(eg[i].to,eg[i].to);
}
struct seg { int mark,sum,max,min; } tree[maxn<<2];
inline void pushup(int root) {
	tree[root].sum = tree[root<<1].sum+tree[root<<1|1].sum;
	tree[root].max = max(tree[root<<1].max,tree[root<<1|1].max);
	tree[root].min = min(tree[root<<1].min,tree[root<<1|1].min);
}
inline void pushdown(int root) {
	if (tree[root].mark) {
		tree[root].mark ^= 1;
		tree[root<<1].mark ^= 1;
		tree[root<<1|1].mark ^= 1;
		tree[root<<1].sum *= -1;
		tree[root<<1|1].sum *= -1;

		int tmp = tree[root<<1].max;
		tree[root<<1].max = -tree[root<<1].min;
		tree[root<<1].min = -tmp;

		tmp = tree[root<<1|1].max;
		tree[root<<1|1].max = -tree[root<<1|1].min;
		tree[root<<1|1].min = -tmp;
	}
}
inline void update_edge(int l,int r,int num,int root,int x) {
	if (l > num || r < num) return;
	if (l == r) {
		tree[root].sum = tree[root].max = tree[root].min = x;
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	update_edge(l,mid,num,root<<1,x);
	update_edge(mid+1,r,num,root<<1|1,x);
	pushup(root);
}
inline void update(int l,int r,int ul,int ur,int root) {
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		tree[root].sum *= -1;
		int tmp = tree[root].max;
		tree[root].max = -tree[root].min;
		tree[root].min = -tmp;
		tree[root].mark ^= 1;
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	update(l,mid,ul,ur,root<<1);
	update(mid+1,r,ul,ur,root<<1|1);
	pushup(root);
}
inline int query_sum(int l,int r,int ql,int qr,int root) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return tree[root].sum;
	pushdown(root);
	int mid = l+r>>1;
	return query_sum(l,mid,ql,qr,root<<1)+query_sum(mid+1,r,ql,qr,root<<1|1);
}
inline int query_max(int l,int r,int ql,int qr,int root) {
	if (l > qr || r < ql) return -9999;
	if (ql <= l && r <= qr) return tree[root].max;
	pushdown(root);
	int mid = l+r>>1;
	return max(query_max(l,mid,ql,qr,root<<1),query_max(mid+1,r,ql,qr,root<<1|1));
}
inline int query_min(int l,int r,int ql,int qr,int root) {
	if (l > qr || r < ql) return 9999;
	if (ql <= l && r <= qr) return tree[root].min;
	pushdown(root);
	int mid = l+r>>1;
	return min(query_min(l,mid,ql,qr,root<<1),query_min(mid+1,r,ql,qr,root<<1|1));
}
inline void update_road(int u,int v) {
	for (;top[u] ^ top[v];u = fa[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		update(1,n,num[top[u]],num[u],1);
	}
	if (dep[u] > dep[v]) swap(u,v);
	update(1,n,num[u]+1,num[v],1);
}
inline int query_SUM(int u,int v) {
	int ans = 0;
	for (;top[u] ^ top[v];u = fa[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		ans += query_sum(1,n,num[top[u]],num[u],1);
	}
	if (dep[u] > dep[v]) swap(u,v);
	return ans+query_sum(1,n,num[u]+1,num[v],1);
}
inline int query_MAX(int u,int v) {
	int ans = -9999;
	for (;top[u] ^ top[v];u = fa[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		ans = max(ans,query_max(1,n,num[top[u]],num[u],1));
	}
	if (dep[u] > dep[v]) swap(u,v);
	return max(ans,query_max(1,n,num[u]+1,num[v],1));
}
inline int query_MIN(int u,int v) {
	int ans = 9999;
	for (;top[u] ^ top[v];u = fa[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		ans = min(ans,query_min(1,n,num[top[u]],num[u],1));
	}
	if (dep[u] > dep[v]) swap(u,v);
	return min(ans,query_min(1,n,num[u]+1,num[v],1));
}
int main() {
	freopen("luogu1505.in","r",stdin);
	freopen("luogu1505.out","w",stdout);
	memset(fir,-1,sizeof(fir));
	scanf("%d",&n);
	for (int i = 1;i < n;i++) {
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		addedge(a[i],b[i]);
	}
	dfs1(0,0);
	dfs2(0,0);
	for (int i = 1;i < n;i++) {
		if (fa[b[i]] == a[i]) swap(a[i],b[i]);
		update_edge(1,n,num[a[i]],1,c[i]);
	}
	for (scanf("%d",&q);q--;) {
		char str[10];
		int u,v;
		scanf("%s%d%d",str,&u,&v);
		if (str[0] == 'C') update_edge(1,n,num[a[u]],1,v);
		if (str[0] == 'N') update_road(u,v);
		if (str[0] == 'S') printf("%d\n",query_SUM(u,v));
		if (str[1] == 'A') printf("%d\n",query_MAX(u,v));
		if (str[1] == 'I') printf("%d\n",query_MIN(u,v));
	}
	return 0;
}
