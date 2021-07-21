#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
#define ri register
using namespace std;
const int maxn = 2e5 + 10;
int n,m,mn[maxn<<2],laz[maxn<<2];
long long sum[maxn<<2];
inline int read() {
	ri int x,p = 1;
	char ch;
	for (;(ch = getchar()) < '0' || ch > '9';) if (ch == '-') p = -x;
	x = ch-'0';
	for (;(ch = getchar()) >= '0' && ch <= '9';) x = x*10+ch-'0';
	return x*p;
}
inline void pushup(int root) {
	mn[root] = min(mn[root<<1],mn[root<<1|1]);
	sum[root] = sum[root<<1]+sum[root<<1|1];
}
inline void pushdown(int root,int l,int r) {
	ri int mid = l+r>>1;
	if (laz[root]) {
		laz[root<<1] = laz[root];
		laz[root<<1|1] = laz[root];
		sum[root<<1] = 1ll*(mid-l+1)*laz[root];
		sum[root<<1|1] = 1ll*(r-mid)*laz[root]; 
		mn[root<<1] = laz[root];
		mn[root<<1|1] = laz[root];
		laz[root] = 0;
	}
}
inline void build(int l,int r,int root) {
	if (l == r) return void(mn[root] = sum[root] = mn[root] = read());
	ri int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline int lower(int l,int r,int num,int root,int x) {
	if (l == r) return mn[root] <= x ? l : n+1;
	pushdown(root,l,r);
	ri int mid = l+r>>1;
	if (mn[root<<1] <= x && num <= mid) return lower(l,mid,num,root<<1,x);
	return lower(mid+1,r,num,root<<1|1,x);
}
inline void update(int l,int r,int ul,int ur,int root,int x) {
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		laz[root] = mn[root] = x;
		sum[root] = 1ll*x*(r-l+1);
		return;
	}
	pushdown(root,l,r);
	ri int mid = l+r>>1;
	update(l,mid,ul,ur,root<<1,x);
	update(mid+1,r,ul,ur,root<<1|1,x);
	pushup(root);
}
inline long long query(int l,int r,int ql,int qr,int root) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return sum[root];
	pushdown(root,l,r);
	ri int mid = l+r>>1;
	return query(l,mid,ql,qr,root<<1)+query(mid+1,r,ql,qr,root<<1|1);
}
int main() {
	freopen("in.in","r",stdin);
	freopen("bf.ans","w",stdout);
	n = read(),m = read();
	build(1,n,1);
	for (ri int i = 1,o,x,y;i <= m;i++) {
		o = read(),x = read(),y = read();
		if (o == 1) {
			ri int num = lower(1,n,1,1,y);
			if (num <= x) update(1,n,num,x,1,y);
		} else {
			ri int ans = 0;
			for (;x <= n;) {
				x = lower(1,n,x,1,y);
				if (x == n+1) break;
				ri int l = x,r = n,mid,res = 0;
				for (;l <= r;query(1,n,x,mid = l+r>>1,1) <= y ? res = mid,l = mid+1 : r = mid-1);
				y -= query(1,n,x,res,1);
				ans += res-x+1;
				x = res+1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
