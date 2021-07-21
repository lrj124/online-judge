/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.26.17:22
*Mail          :  1584634848@qq.com
*Problem       :  luogu1438
************************************************/
#include <cstdio>
const int maxn = 100000 + 10;
struct seg { int sum,mark,l,r; } tree[maxn<<2];
int n,m,op,l,r,s,e,d,last;
inline void build(int l,int r,int root) {
	if (l == r) {
		int x; scanf("%d",&x);
		tree[root] = {x-last,0,l,r};
		last = x;
		return;
	}
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	tree[root] = {tree[root<<1].sum+tree[root<<1|1].sum,0,l,r};
}
inline void pushdown(int root) {
	if (tree[root].mark) {
		tree[root<<1].mark += tree[root].mark;
		tree[root<<1|1].mark += tree[root].mark;
		tree[root<<1].sum += tree[root].mark*(tree[root<<1].r-tree[root<<1].l+1);
		tree[root<<1|1].sum += tree[root].mark*(tree[root<<1|1].r-tree[root<<1|1].l+1);
		tree[root].mark = 0;
	}
}
inline void update(int l,int r,int ul,int ur,int root,int x) {
	if (r < ul || l > ur) return;
	if (ul <= l && r <= ur) {
		tree[root].sum += x*(r-l+1);
		tree[root].mark += x;
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	update(l,mid,ul,ur,root<<1,x);
	update(mid+1,r,ul,ur,root<<1|1,x);
	tree[root].sum = tree[root<<1].sum+tree[root<<1|1].sum;
}
inline int query(int l,int r,int ql,int qr,int root) {
	if (r < ql || l > qr) return 0;
	if (ql <= l && r <= qr) return tree[root].sum;
	pushdown(root);
	int mid = l+r>>1;
	return query(l,mid,ql,qr,root<<1)+query(mid+1,r,ql,qr,root<<1|1);
}
int main() {
	freopen("luogu1438.in","r",stdin);
	freopen("luogu1438.out","w",stdout);
	for (scanf("%d%d",&n,&m),build(1,n,1);m--;) {
		scanf("%d%d",&op,&l);
		if (op == 2) printf("%d\n",query(1,n,1,l,1));
		else {
			scanf("%d%d%d",&r,&s,&d);
			e = s+(r-l)*d;
			update(1,n,l,l,1,s);
			update(1,n,l+1,r,1,d);
			update(1,n,r+1,r+1,1,-e);
		}
	}
	return 0;
}
