/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.25.15:42
*Mail          :  1584634848@qq.com
*Problem       :  luogu4513
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 500000 + 10;
struct seg { int l,r,sum,max; } tree[maxn<<2];
int n,q;
inline void pushup(int root) {
	tree[root].sum = tree[root<<1].sum+tree[root<<1|1].sum;
	tree[root].l = max(tree[root<<1].l,tree[root<<1|1].l+tree[root<<1].sum);
	tree[root].r = max(tree[root<<1|1].r,tree[root<<1].r+tree[root<<1|1].sum);
	tree[root].max = max(tree[root<<1].r+tree[root<<1|1].l,max(tree[root<<1].max,tree[root<<1|1].max));
}
inline void build(int l,int r,int root) {
	if (l == r) {
		int x; scanf("%d",&x);
		tree[root] = { x,x,x,x };
		return;
	}
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline void update(int l,int r,int num,int root,int x) {
	if (l > num || r < num) return;
	if (l == r) {
		tree[root] = { x,x,x,x };
		return;
	}
	int mid = l+r>>1;
	update(l,mid,num,root<<1,x);
	update(mid+1,r,num,root<<1|1,x);
	pushup(root);
}
inline seg query(int l,int r,int ql,int qr,int root) {
	if (ql <= l && r <= qr) return tree[root];
	int mid = l+r>>1;
	if (mid >= qr) return query(l,mid,ql,qr,root<<1);
	if (ql > mid) return query(mid+1,r,ql,qr,root<<1|1);
	seg lson = query(l,mid,ql,qr,root<<1),rson = query(mid+1,r,ql,qr,root<<1|1),ans;
	ans = { max(lson.l,rson.l+lson.sum),max(rson.r,lson.r+rson.sum),rson.sum+lson.sum,max(lson.r+rson.l,max(lson.max,rson.max)) };
	return ans;
}
int main() {
	freopen("luogu4513.in","r",stdin);
	freopen("luogu4513.out","w",stdout);
	scanf("%d%d",&n,&q);
	build(1,n,1);
	for (int x,y,z;q--;) {
		scanf("%d%d%d",&x,&y,&z);
		if (x == 2) update(1,n,y,1,z);
		else {
			if (y > z) swap(y,z);
			printf("%d\n",query(1,n,y,z,1).max);
		}
	}
	return 0;
}
