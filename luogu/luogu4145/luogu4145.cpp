/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.28.14:24
*Mail          :  1584634848@qq.com
*Problem       :  luogu4145
************************************************/
#include <algorithm>
#include <cstdio>
#include <cmath>
using ll = long long;
const int maxn = 100000 + 10;
ll sum[maxn<<2],maxv[maxn<<2];
inline void pushup(int root) {
	sum[root] = sum[root<<1]+sum[root<<1|1];
	maxv[root] = std :: max(maxv[root<<1],maxv[root<<1|1]);
}
inline void build(int l,int r,int root) {
	if (l == r) {
		scanf("%lld",&sum[root]);
		maxv[root] = sum[root];
		return;
	}
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline void update(int l,int r,int ul,int ur,int root) {
	if (l > ur || r < ul || maxv[root] < 2) return;
	if (l == r) {
		maxv[root] = sum[root] = sqrt(sum[root]);
		return;
	}
	int mid = l+r>>1;
	update(l,mid,ul,ur,root<<1);
	update(mid+1,r,ul,ur,root<<1|1);
	pushup(root);
}
inline ll query(int l,int r,int ql,int qr,int root) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return sum[root];
	int mid = l+r>>1;
	return query(l,mid,ql,qr,root<<1)+query(mid+1,r,ql,qr,root<<1|1);
}
int main() {
	for (int n,q,x,y,z;scanf("%d",&n) ^ EOF;puts("")) {
		build(1,n,1);
		for (scanf("%d",&q);q--;) {
			scanf("%d%d%d",&x,&y,&z);
			if (y > z) std :: swap(y,z);
			if (x) printf("%lld\n",query(1,n,y,z,1));
			else update(1,n,y,z,1);
		}
	}
	return 0;
}
