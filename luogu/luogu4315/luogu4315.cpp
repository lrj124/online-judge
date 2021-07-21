/************************************************
*Author		:  lrj124
*Created Time  :  2019.09.10.21:17
*Mail		  :  1584634848@qq.com
*Problem	   :  luogu4315
************************************************/
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
const int inf = 2147483647;
int n,egcnt,cnt,u[maxn],v[maxn],w[maxn],num[maxn],fa[maxn],dep[maxn],top[maxn],size[maxn],son[maxn],fir[maxn],maxv[maxn<<2],tag[maxn<<2],mark[maxn<<2];
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
inline void pushdown(int root) {
	if (tag[root] >= 0) {
		mark[root<<1] = mark[root<<1|1] = 0;
		tag[root<<1] = tag[root<<1|1] = maxv[root<<1] = maxv[root<<1|1] = tag[root];
		tag[root] = -1;
	}
	if (mark[root]) {
		mark[root<<1] += mark[root];
		maxv[root<<1] += mark[root];
		mark[root<<1|1] += mark[root];
		maxv[root<<1|1] += mark[root];
		mark[root] = 0;
	}
}
inline void update_set(int l,int r,int ul,int ur,int root,int x) {
	if (l > ur || r < ul) return;
	if (l == r) {
		maxv[root] = tag[root] = x;
		mark[root] = 0;
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	update_set(l,mid,ul,ur,root<<1,x);
	update_set(mid+1,r,ul,ur,root<<1|1,x);
	pushup(root);
}
inline void update_add(int l,int r,int ul,int ur,int root,int x) {
	if (l > ur || r < ul) return;
	if (l == r) {
		maxv[root] += x;
		mark[root] += x;
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	update_add(l,mid,ul,ur,root<<1,x);
	update_add(mid+1,r,ul,ur,root<<1|1,x);
	pushup(root);
}
inline int query(int l,int r,int ql,int qr,int root) {
	if (r < ql || l > qr) return -inf;
	if (ql <= l && r <= qr) return maxv[root];
	int mid = l+r>>1;
	return max(query(l,mid,ql,qr,root<<1),query(mid+1,r,ql,qr,root<<1|1));
}
inline void update_edge(int u,int v,int w) {
	for (;top[u] ^ top[v];u = fa[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		update_add(1,n,num[top[u]],num[u],1,w);
	}
	if (dep[u] > dep[v]) swap(u,v);
	update_add(1,n,num[u]+1,num[v],1,w);
}
inline void set_edge(int u,int v,int w) {
	for (;top[u] ^ top[v];u = fa[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		update_set(1,n,num[top[u]],num[u],1,w);
	}
	if (dep[u] > dep[v]) swap(u,v);
	update_set(1,n,num[u]+1,num[v],1,w);
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
	freopen("luogu4315.in","r",stdin);
	freopen("luogu4315.out","w",stdout);
	memset(tag,-1,sizeof(tag));
	scanf("%d",&n);
	for (int i = 1;i < n;i++) {
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		addedge(u[i],v[i]);
	}
	dfs(1,0);
	dfs2(1,1);
	for (int i = 1;i < n;i++) {
		if (fa[v[i]] == u[i]) swap(u[i],v[i]);
		update_set(1,n,num[u[i]],num[u[i]],1,w[i]);
	}
	char ch[10];
	for (int x,y;scanf("%s%d%d",ch,&x,&y), ch[0] ^ 'S';) {
		if (ch[0] == 'M') printf("%d\n",query_edge(x,y));
		else if (ch[1] == 'o') {
			int w; scanf("%d",&w);
			set_edge(x,y,w);
		} else if (ch[1] == 'd') {
			int w; scanf("%d",&w);
			update_edge(x,y,w);
		} else {
			if (fa[v[x]] == u[x]) swap(u[x],v[x]);
			update_set(1,n,num[u[x]],num[u[x]],1,y);
		}
	}
	return 0;
}
