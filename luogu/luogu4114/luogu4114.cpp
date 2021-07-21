/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.03.21:32
*Mail          :  1584634848@qq.com
*Problem       :  luogu4114
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
const int inf = 99999999;
int n,egcnt,cnt,u[maxn],v[maxn],w[maxn],num[maxn],fa[maxn],dep[maxn],top[maxn],size[maxn],son[maxn],fir[maxn],maxv[maxn<<2];
struct Edge { int to,nex; } eg[maxn<<2];
inline void addedge(int u,int v) {
	eg[++egcnt] = {v,fir[u]}; fir[u] = egcnt;
	eg[++egcnt] = {u,fir[v]}; fir[v] = egcnt;
}
inline void dfs(int now,int f) {
	fa[now] = f;
	size[now] = 1;
	dep[now] = dep[f]+1;
	for (int i = fir[now];i;i = eg[i].nex)
		if (eg[i].to ^ f) {
			dfs(eg[i].to,now);
			size[now] += size[eg[i].to];
			if (size[eg[i].to] > size[son[now]]) son[now] = eg[i].to;
		}
}
inline void dfs2(int now,int ntop) {
	top[now] = ntop;
	num[now] = ++cnt;
	if (son[now]) dfs2(son[now],ntop);
	for (int i = fir[now];i;i = eg[i].nex)
		if (eg[i].to ^ fa[now] && eg[i].to ^ son[now]) dfs2(eg[i].to,eg[i].to);
}
inline void pushup(int root) { maxv[root] = max(maxv[root<<1],maxv[root<<1|1]); }
inline void update(int l,int r,int num,int root,int x) {
	if (l > num || r < num) return;
	if (l == r) {
		maxv[root] = x;
		return;
	}
	int mid = l+r>>1;
	update(l,mid,num,root<<1,x);
	update(mid+1,r,num,root<<1|1,x);
	pushup(root);
}
inline int query(int l,int r,int ql,int qr,int root) {
	if (r < ql || l > qr) return 0;
	if (ql <= l && r <= qr) return maxv[root];
	int mid = l+r>>1;
	return max(query(l,mid,ql,qr,root<<1),query(mid+1,r,ql,qr,root<<1|1));
}
inline int query_edge(int u,int v) {
	int ans = -inf;
	for (;top[u] ^ top[v];u = fa[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		ans = max(ans,query(1,n,num[top[u]],num[u],1));
	}
	if (dep[u] > dep[v]) swap(u,v);
	return max(ans,query(1,n,num[u]+1,num[v],1));
}
int main() {
	freopen("luogu4114.in","r",stdin);
	freopen("luogu4114.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i < n;i++) {
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		addedge(u[i],v[i]);
	}
	dfs(1,0);
	dfs2(1,1);
	for (int i = 1;i < n;i++) {
		if (fa[v[i]] == u[i]) swap(u[i],v[i]);
		update(1,n,num[u[i]],1,w[i]);
	}
	char ch[10];
	for (int x,y;scanf("%s%d%d",ch,&x,&y), ch[0] ^ 'D';)
		if (ch[0] == 'Q') printf("%d\n",query_edge(x,y));
		else {
			if (fa[v[x]] == u[x])  swap(u[x],v[x]);
			update(1,n,num[u[x]],1,y);
		}
	return 0;
}
