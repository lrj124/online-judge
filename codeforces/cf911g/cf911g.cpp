/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.04.14:07
*Mail          :  1584634848@qq.com
*Problem       :  cf911g
************************************************/
#include <cstdio>
const int maxn = 200000 + 10;
int n,q,a[maxn],tag[maxn<<2][101];
inline void pushdown(int root) {
	for (int i = 1;i <= 100;i++) {
		tag[root<<1][i] = tag[root][tag[root<<1][i]];
		tag[root<<1|1][i] = tag[root][tag[root<<1|1][i]];
	}
	for (int i = 1;i <= 100;i++) tag[root][i] = i;
}
inline void update(int l,int r,int ul,int ur,int num,int root,int x) {
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		for (int i = 1;i <= 100;i++)
			if (tag[root][i] == num) tag[root][i] = x;
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	update(l,mid,ul,ur,num,root<<1,x);
	update(mid+1,r,ul,ur,num,root<<1|1,x);
}
inline void print(int l,int r,int root) {
	if (l == r) {
		printf("%d ",tag[root][a[l]]);
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	print(l,mid,root<<1);
	print(mid+1,r,root<<1|1);
}
int main() {
	freopen("cf911g.in","r",stdin);
	freopen("cf911g.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n<<2;i++) for (int j = 1;j <= 100;j++) tag[i][j] = j;
	for (scanf("%d",&q);q--;) {
		int l,r,x,y;
		scanf("%d%d%d%d",&l,&r,&x,&y);
		update(1,n,l,r,x,1,y);
	}
	print(1,n,1);
	return 0;
}
