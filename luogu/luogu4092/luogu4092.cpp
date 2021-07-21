/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.28.15:23
*Mail          :  1584634848@qq.com
*Problem       :  luogu4092
************************************************/
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
int n,q,cnt,tree[maxn<<2],dep[maxn],top[maxn],son[maxn],father[maxn],num[maxn],siz[maxn],map[maxn];
vector<int> edge[maxn];
inline void dfs(int now,int fa) {
	dep[now] = dep[fa]+1;
	father[now] = fa;
	siz[now] = 1;
	for (size_t i = 0;i < edge[now].size();i++)
		if (edge[now][i] ^ fa) {
			dfs(edge[now][i],now);
			siz[now] += edge[now][i];
			if (siz[son[now]] < siz[edge[now][i]]) son[now] =  edge[now][i];
		}
}
inline void dfs2(int now,int ntop) {
	top[now] = ntop;
	num[now] = ++cnt;
	map[cnt] = now;
	if (son[now]) dfs2(son[now],ntop);
	for (size_t i = 0;i < edge[now].size();i++)
		if (edge[now][i] ^ father[now] && edge[now][i] ^ son[now]) dfs2(edge[now][i],edge[now][i]);
}
inline int Max(int a,int b) { return dep[a] > dep[b] ? a : b; }
inline void pushup(int root) { tree[root] = Max(tree[root<<1],tree[root<<1|1]); }
inline void update(int l,int r,int num,int root) {
	if (l > num || r < num) return;
	if (l == r) {
		tree[root] = map[l];
		return;
	}
	int mid = l+r>>1;
	update(l,mid,num,root<<1);
	update(mid+1,r,num,root<<1|1);
	pushup(root);
}
inline int query(int l,int r,int ql,int qr,int root) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return tree[root];
	int mid = l+r>>1;
	return Max(query(l,mid,ql,qr,root<<1),query(mid+1,r,ql,qr,root<<1|1));
}
inline int query_edge(int u,int v) {
	for (;top[u] ^ top[v];u = father[top[u]]) {
		if (dep[top[u]] < dep[top[v]]) swap(u,v);
		int ans = query(1,n,num[top[u]],num[u],1);
		if (ans) return ans;
	}
	if (dep[u] > dep[v]) swap(u,v);
	return query(1,n,dep[u],dep[v],1);
}
int main() {
	freopen("luogu4092.in","r",stdin);
	freopen("luogu4092.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,1);
	update(1,n,1,1);
	for (char op[2];q--;) {
		int x;
		scanf("%s%d",op,&x);
		if (op[0] == 'C') update(1,n,num[x],1);
		else printf("%d\n",query_edge(1,x));
	}
	return 0;
}
