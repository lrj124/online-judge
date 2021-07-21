//I am hunting for the golden stag.
#include <cstdio>
const int maxn = 1e5 + 10;
const int N = 20 + 1;
long long sum[maxn<<2][N];
int n,m,laz[maxn<<2][N];
inline void pushup(int root) { for (int i = 0;i < N;i++) sum[root][i] = sum[root<<1][i]+sum[root<<1|1][i]; }
inline void pushdown(int ls,int rs,int root) {
	for (int i = 0;i < N;i++) if (laz[root][i]) {
		laz[root<<1][i] ^= 1;
		sum[root<<1][i] = ls-sum[root<<1][i];
		laz[root<<1|1][i] ^= 1;
		sum[root<<1|1][i] = rs-sum[root<<1|1][i];
		laz[root][i] ^= 1;
	}
}
inline void build(int l,int r,int root) {
	if (l == r) {
		int x; scanf("%d",&x);
		for (int i = 0;i < N;i++) sum[root][i] = x>>i&1;
		return;
	}
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline void update(int l,int r,int ul,int ur,int root,int x) {
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		for (int i = 0;i < N;i++) if (x>>i&1) {
			laz[root][i] ^= 1;
			sum[root][i] = r-l+1-sum[root][i];
		}
		return;
	}
	int mid = l+r>>1;
	pushdown(mid-l+1,r-mid,root);
	update(l,mid,ul,ur,root<<1,x);
	update(mid+1,r,ul,ur,root<<1|1,x);
	pushup(root);
}
inline long long query(int l,int r,int ql,int qr,int root) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) {
		long long res = 0;
		for (int i = 0;i < N;i++) res += sum[root][i]*(1<<i);
		return res;
	}
	int mid = l+r>>1;
	pushdown(mid-l+1,r-mid,root);
	return query(l,mid,ql,qr,root<<1)+query(mid+1,r,ql,qr,root<<1|1);
}
int main() {
	freopen("cf242e.in","r",stdin);
	freopen("cf242e.out","w",stdout);
	scanf("%d",&n); build(1,n,1);
	for (scanf("%d",&m);m--;) {
		int op,l,r,x;
		scanf("%d%d%d",&op,&l,&r);
		if (op == 1) printf("%lld\n",query(1,n,l,r,1));
		if (op == 2) { scanf("%d",&x); update(1,n,l,r,1,x); }
	}
	return 0;
}
