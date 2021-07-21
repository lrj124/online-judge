/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.20.11:47
*Mail          :  1584634848@qq.com
*Problem       :  cf914d
************************************************/
#include <cstdio>
const int maxn = 500000 + 10;
int n,q,tree[maxn<<2],cnt;
inline int gcd(int a,int b) { return b ? gcd(b,a%b) : a; }
inline void pushup(int root) { tree[root] = gcd(tree[root<<1],tree[root<<1|1]); }
inline void build(int l,int r,int root) {
	if (l == r) {
		scanf("%d",&tree[root]);
		return;
	}
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline void update(int l,int r,int num,int root,int x) {
	if (l == r) {
		tree[root] = x;
		return;
	}
	int mid = l+r>>1;
	if (mid >= num) update(l,mid,num,root<<1,x);
	else update(mid+1,r,num,root<<1|1,x);
	pushup(root);
}
inline void query(int l,int r,int ql,int qr,int root,int x) {
	if (cnt > 1 || r < ql || l > qr || !(tree[root]%x)) return;
	if (l == r) {
		cnt++;
		return;
	}
	int mid = l+r>>1;
	query(l,mid,ql,qr,root<<1,x);
	query(mid+1,r,ql,qr,root<<1|1,x);
}
int main() {
	freopen("cf914d.in","r",stdin);
	freopen("cf914d.out","w",stdout);
	scanf("%d",&n);
	build(1,n,1);
	for (scanf("%d",&q);q--;) {
		int op,l,r,x;
		scanf("%d%d%d",&op,&l,&r);
		if (op == 1) {
			scanf("%d",&x); cnt = 0;
			query(1,n,l,r,1,x);
			puts(cnt > 1 ? "NO" : "YES");
		} else update(1,n,l,1,r);
	}
	return 0;
}
