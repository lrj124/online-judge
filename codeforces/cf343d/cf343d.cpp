/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.20.09:22
*Mail          :  1584634848@qq.com
*Problem       :  cf343d
************************************************/
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 500000 + 10;
int n,q,cnt,dep[maxn],top[maxn],num[maxn],siz[maxn],father[maxn],son[maxn];
vector<int> edges[maxn];
inline void dfs1(int now,int f) {
    siz[now] = 1;
    father[now] = f;
    dep[now] = dep[father[now]]+1;
	for (size_t i = 0;i < edges[now].size();i++)
	    if (edges[now][i] != f) {
			dfs1(edges[now][i],now);
			siz[now] += siz[edges[now][i]];
			if (siz[son[now]] < siz[edges[now][i]] || !son[now]) son[now] = edges[now][i];
		}
}
inline void dfs2(int now,int ntop) {
    top[now] = ntop;
	num[now] = ++cnt;
	if (son[now]) dfs2(son[now],ntop);
	for (size_t i = 0;i < edges[now].size();i++)
	    if (edges[now][i] != father[now] && edges[now][i] != son[now]) dfs2(edges[now][i],edges[now][i]);
}
struct seg { int l,r,mark,sum; } tree[maxn*4];
inline void pushup(int root) { tree[root].sum = tree[root<<1].sum+tree[root<<1|1].sum; }
inline void pushdown(int root) {
    if (tree[root].mark) {
	    tree[root<<1].mark = tree[root].mark;
		tree[root<<1|1].mark = tree[root].mark;
		tree[root<<1].sum = (tree[root].mark-1)*(tree[root<<1].r-tree[root<<1].l+1);
		tree[root<<1|1].sum = (tree[root].mark-1)*(tree[root<<1|1].r-tree[root<<1|1].l+1);
		tree[root].mark = 0;
	}
}
inline void BuildTree(int l,int r,int root) {
	tree[root].l = l;
	tree[root].r = r;
    if (l == r) return;
	int mid = l+r>>1;
	BuildTree(l,mid,root<<1);
	BuildTree(mid+1,r,root<<1|1);
	pushup(root);
}
inline void Update(int l,int r,int ql,int qr,int root,int x) {
    if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
	    tree[root].mark = x+1;
		tree[root].sum = x*(r-l+1);
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	Update(l,mid,ql,qr,root<<1,x);
	Update(mid+1,r,ql,qr,root<<1|1,x);
	pushup(root);
}
inline int Query(int l,int r,int ql,int qr,int root) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) return tree[root].sum;
	pushdown(root);
	int mid = l+r>>1;
	return Query(l,mid,ql,qr,root<<1)+Query(mid+1,r,ql,qr,root<<1|1);
}
inline int Query2(int l,int r,int ql,int qr,int root) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) return (r-l+1)-tree[root].sum;
	pushdown(root);
	int mid = l+r>>1;
	return Query2(l,mid,ql,qr,root<<1)+Query2(mid+1,r,ql,qr,root<<1|1);
}
inline void UpdateEdge(int u,int v,long long x) {
    int topu = top[u];
	int topv = top[v];
	while (topu != topv) {
	    if (dep[topu] < dep[topv]) {
		    swap(topu,topv);
			swap(u,v);
		}
		Update(1,cnt,num[topu],num[u],1,x);
		u = father[topu];
		topu = top[u];
	}
	if (dep[u] > dep[v]) swap(u,v);
	Update(1,cnt,num[u],num[v],1,x);
}
inline int QueryEdge(int u,int v) {
	int topu = top[u];
	int topv = top[v];
	int sum = 0;
	while (topu != topv) {
	    if (dep[topu] < dep[topv]) {
		    swap(topu,topv);
			swap(u,v);
		}
		sum += Query2(1,cnt,num[topu],num[u],1);
		u = father[topu];
		topu = top[u];
	}
	if (dep[u] > dep[v]) swap(u,v);
	return sum+Query2(1,cnt,num[u],num[v],1);
}
int main() {
	freopen("cf343d.in","r",stdin);
	freopen("cf343d.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for (scanf("%d",&q);q--;) {
		int op,x;
		scanf("%d%d",&op,&x);
		if (op == 1) Update(1,cnt,num[x],num[x]+siz[x]-1,1,1);
		if (op == 2) UpdateEdge(1,x,0);
		if (op == 3) printf("%d\n",Query(1,cnt,num[x],num[x],1));
	}
	return 0;
}
