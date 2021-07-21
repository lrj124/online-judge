//2021.07.17 15:37 by lrj124.
#include <cstdarg>
#include <cstring>
#include <cstdio>
const int maxn = 2.5e5 + 10;
const int mod = 998244353;
struct matrix {
	int n,m,a[5][5];
	inline void clear() { n = m = 0; memset(a,0,sizeof a); }
	inline bool operator != (matrix x) const {
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				if (a[i][j] ^ x.a[i][j]) return true;
		return false;
	}
	inline matrix operator + (matrix x) const {
		matrix res; res.clear();
		res.n = n; res.m = m;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++) res.a[i][j] = (a[i][j]+x.a[i][j])%mod;
		return res;
	}
	inline matrix operator * (matrix x) const {
		matrix res; res.clear();
		res.n = n; res.m = x.m;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= x.m;j++)
				for (int k = 1;k <= m;k++) (res.a[i][j] += 1ll*a[i][k]*x.a[k][j]%mod) %= mod;
		return res;
	}
} e,sum[maxn<<2],laz[maxn<<2];
inline matrix set(int r,int c,...) {
	matrix res; res.n = r; res.m = c;
	va_list args; va_start(args,r*c);
	for (int i = 1;i <= r;i++)
		for (int j = 1;j <= c;j++) res.a[i][j] = va_arg(args,int);
	va_end(args);
	return res;
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
	if (l == r) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		return sum[root] = set(1,4,a,b,c,1),void();
	}
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline void update(int l,int r,int ul,int ur,int root,matrix x) {
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		sum[root] = sum[root]*x;
		laz[root] = laz[root]*x;
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	update(l,mid,ul,ur,root<<1,x);
	update(mid+1,r,ul,ur,root<<1|1,x);
	pushup(root);
}
inline matrix query(int l,int r,int ql,int qr,int root) {
	if (l > ql || r < ql) return set(1,4,0,0,0,0);
	if (ql <= l && r <= qr) return sum[root];
	pushdown(root);
	int mid = l+r>>1;
	return query(l,mid,ql,qr,root<<1)+query(mid+1,r,ql,qr,root<<1|1);
}
int main() {
	e = set(4,4,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	int n,m; scanf("%d",&n); build(1,n,1);
	for (scanf("%d",&m);m--;) {
		int o,l,r,v;
		scanf("%d%d%d",&o,&l,&r);
		if (4 <= o && o <= 6) scanf("%d",&v);
		if (o == 1) update(1,n,l,r,1,set(4,4,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1));
		else if (o == 2) update(1,n,l,r,1,set(4,4,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1));
		else if (o == 3) update(1,n,l,r,1,set(4,4,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1));
		else if (o == 4) update(1,n,l,r,1,set(4,4,1,0,0,0,0,1,0,0,0,0,1,0,v,0,0,1));
		else if (o == 5) update(1,n,l,r,1,set(4,4,1,0,0,0,0,v,0,0,0,0,1,0,0,0,0,1));
		else if (o == 6) update(1,n,l,r,1,set(4,4,1,0,0,0,0,1,0,0,0,0,0,0,0,0,v,1));
		else if (o == 7) {
			matrix ans = query(1,n,l,r,1);
			printf("%d %d %d\n",ans.a[1][1],ans.a[1][2],ans.a[1][3]);
		}
	}
	return 0;
}
