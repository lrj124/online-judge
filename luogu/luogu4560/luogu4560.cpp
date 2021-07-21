/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.03.21:38
*Mail          :  1584634848@qq.com
*Problem       :  luogu4560
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2000000 + 10;
int n,q,maxv[maxn<<2],minv[maxn<<2];
inline void pushup_max(int root,int x) {
	minv[root] = max(minv[root],x);
	maxv[root] = max(maxv[root],x);
}
inline void pushup_min(int root,int x) {
	minv[root] = min(minv[root],x);
	maxv[root] = min(maxv[root],x);
}
inline void pushdown(int root) {
	pushup_max(root<<1,maxv[root]);
	pushup_max(root<<1|1,maxv[root]);
	pushup_min(root<<1,minv[root]);
	pushup_min(root<<1|1,minv[root]);
	maxv[root] = 0; minv[root] = 999999;
}
inline void take_max(int l,int r,int ul,int ur,int root,int x) {
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		pushup_max(root,x);
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	take_max(l,mid,ul,ur,root<<1,x);
	take_max(mid+1,r,ul,ur,root<<1|1,x);
}
inline void take_min(int l,int r,int ul,int ur,int root,int x) {
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		pushup_min(root,x);
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	take_min(l,mid,ul,ur,root<<1,x);
	take_min(mid+1,r,ul,ur,root<<1|1,x);
}
inline void print(int l,int r,int root) {
	if (l == r) {
		printf("%d\n",maxv[root]);
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	print(l,mid,root<<1);
	print(mid+1,r,root<<1|1);
}
int main() {
	freopen("luogu4560.in","r",stdin);
	freopen("luogu4560.out","w",stdout);
	for (scanf("%d%d",&n,&q);q--;) {
		int op,l,r,w;
		scanf("%d%d%d%d",&op,&l,&r,&w);
		if (op == 1) take_max(1,n,l+1,r+1,1,w);
		else take_min(1,n,l+1,r+1,1,w);
	}
	print(1,n,1);
	return 0;
}
