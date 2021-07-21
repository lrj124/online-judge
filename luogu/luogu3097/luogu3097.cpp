/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.06.21:55
*Mail          :  1584634848@qq.com
*Problem       :  luogu3097
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 40000 + 10;
int n,d,tree[maxn<<2][2][2];
long long ans;
inline void pushup(int root) {
	tree[root][0][1] = max(max(
		tree[root<<1][0][1]+tree[root<<1|1][0][1],
		tree[root<<1][0][0]+tree[root<<1|1][0][1]),
		tree[root<<1][0][0]+tree[root<<1|1][1][1]);
	tree[root][1][0] = max(max(
		tree[root<<1][1][0]+tree[root<<1|1][1][0],
		tree[root<<1][1][1]+tree[root<<1|1][0][0]),
		tree[root<<1][1][0]+tree[root<<1|1][0][0]);
	tree[root][0][0] = max(max(
		tree[root<<1][0][1]+tree[root<<1|1][0][0],
		tree[root<<1][0][0]+tree[root<<1|1][0][0]),
		tree[root<<1][0][0]+tree[root<<1|1][1][0]);
	tree[root][1][1] = max(max(
		tree[root<<1][1][1]+tree[root<<1|1][0][1],
		tree[root<<1][1][0]+tree[root<<1|1][1][1]),
		tree[root<<1][1][0]+tree[root<<1|1][0][1]);
}
inline void build(int l,int r,int root) {
	if (l == r) {
		scanf("%d",&tree[root][1][1]);
		return;
	}
	int mid = l+r>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}
inline void update(int l,int r,int num,int x,int root) {
	if (l > num || r < num) return;
	if (l == r) {
		tree[root][1][1] = x;
		return;
	}
	int mid = l+r>>1;
	update(l,mid,num,x,root<<1);
	update(mid+1,r,num,x,root<<1|1);
	pushup(root);
}
int main() {
	freopen("luogu3097.in","r",stdin);
	freopen("luogu3097.out","w",stdout);
	scanf("%d%d",&n,&d);
	build(1,n,1);
	for (int i = 1,x,y;i <= d;i++) {
		scanf("%d%d",&x,&y);
		update(1,n,x,y,1);
		ans += max(max(tree[1][0][1],tree[1][1][0]),max(tree[1][1][1],tree[1][0][0]));
	}
	printf("%lld",ans);
	return 0;
}
