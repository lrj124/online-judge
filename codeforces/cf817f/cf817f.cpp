//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
int n,a[maxn],opt[maxn],lef[maxn],rig[maxn],sum[maxn<<2],laz[maxn<<2],rev[maxn<<2];
inline int num(int x) { return lower_bound(a+1,a+a[0]+1,x)-a; }
inline void pushup(int root) { sum[root] = sum[root<<1]+sum[root<<1|1]; }
inline void pushdown(int root,int l,int r) {
	int mid = l+r>>1;
	if (laz[root] ^ -1) {
		rev[root] = 0;
		laz[root<<1] = laz[root];
		laz[root<<1|1] = laz[root];
		sum[root<<1] = laz[root]*(mid-l+1);
		sum[root<<1|1] = laz[root]*(r-mid);
		laz[root] = -1;
	}
	if (rev[root]) {
		if (laz[root<<1] ^ -1) laz[root<<1] ^= 1;
		else rev[root<<1] ^= 1;
		if (laz[root<<1|1] ^ -1) laz[root<<1|1] ^= 1;
		else rev[root<<1|1] ^= 1;
		sum[root<<1] = mid-l+1-sum[root<<1];
		sum[root<<1|1] = r-mid-sum[root<<1|1];
		rev[root] ^= 1;
	}
}
inline void update_set(int l,int r,int ul,int ur,int root,int x) {
	pushdown(root,l,r);
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		laz[root] = x;
		sum[root] = x*(r-l+1);
		return;
	}
	int mid = l+r>>1;
	update_set(l,mid,ul,ur,root<<1,x);
	update_set(mid+1,r,ul,ur,root<<1|1,x);
	pushup(root);
}
inline void update_rev(int l,int r,int ul,int ur,int root) {
	pushdown(root,l,r);
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		rev[root] ^= 1;
		sum[root] = r-l+1-sum[root];
		return;
	}
	int mid = l+r>>1;
	update_rev(l,mid,ul,ur,root<<1);
	update_rev(mid+1,r,ul,ur,root<<1|1);
	pushup(root);
}
inline int query(int l,int r,int root) {
	pushdown(root,l,r);
	if (l == r) return l;
	int mid = l+r>>1;
	if (sum[root<<1] < mid-l+1) return query(l,mid,root<<1);
	return query(mid+1,r,root<<1|1);
}
signed main() {
	freopen("cf817f.in","r",stdin);
	freopen("cf817f.out","w",stdout);
	scanf("%lld",&n); a[++a[0]] = 1;
	for (int i = 1;i <= n;i++) {
		scanf("%lld%lld%lld",&opt[i],&lef[i],&rig[i]);
		a[++a[0]] = lef[i];
		a[++a[0]] = rig[i];
		a[++a[0]] = rig[i]+1;
	}
	fill(laz,laz+n*12,-1);
	sort(a+1,a+a[0]+1);
	a[0] = unique(a+1,a+a[0]+1)-(a+1);
	for (int i = 1;i <= n;i++) {
		if (opt[i] == 1) update_set(1,a[0],num(lef[i]),num(rig[i]),1,1);
		if (opt[i] == 2) update_set(1,a[0],num(lef[i]),num(rig[i]),1,0);
		if (opt[i] == 3) update_rev(1,a[0],num(lef[i]),num(rig[i]),1);
		printf("%lld\n",a[query(1,a[0],1)]);
	}
	return 0;
}
