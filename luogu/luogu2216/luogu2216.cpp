/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.26.14:52
*Mail          :  1584634848@qq.com
*Problem       :  luogu2216
************************************************/
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
const int inf = 1000000000;
const int maxn = 1000 + 10;
int n,m,k,a[maxn][maxn],ans = inf;
struct Seg {
	int maxv[maxn<<2],minv[maxn<<2];
	inline void pushup(int root) {
		maxv[root] = max(maxv[root<<1],maxv[root<<1|1]);
		minv[root] = min(minv[root<<1],minv[root<<1|1]);
	}
	inline void build(int l,int r,int root) {
		if (l == r) {
			scanf("%d",&maxv[root]);
			minv[root] = maxv[root];
			return;
		}
		int mid = l+r>>1;
		build(l,mid,root<<1);
		build(mid+1,r,root<<1|1);
		pushup(root);
	}
	inline int query_max(int l,int r,int ql,int qr,int root) {
		if (l > qr || r < ql) return -inf;
		if (ql <= l && r <= qr) return maxv[root];
		int mid = l+r>>1;
		return max(query_max(l,mid,ql,qr,root<<1),query_max(mid+1,r,ql,qr,root<<1|1));
	}
	inline int query_min(int l,int r,int ql,int qr,int root) {
		if (l > qr || r < ql) return inf;
		if (ql <= l && r <= qr) return minv[root];
		int mid = l+r>>1;
		return min(query_min(l,mid,ql,qr,root<<1),query_min(mid+1,r,ql,qr,root<<1|1));
	}
} tree[maxn];
bool vis[maxn][maxn];
int main() {
//	freopen("luogu2216.in","r",stdin);
//	freopen("luogu2216.out","w",stdout);
	srand((unsigned)time(NULL));
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++) tree[i].build(1,m,1);
	for (int Min,Max,i,j;i = rand()%(n-k+1)+1,j = rand()%(m-k+1)+1;) {
		if (1.*clock()/CLOCKS_PER_SEC > 0.99) {
			printf("%d",ans);
			return 0;
		}
		if (vis[i][j]) continue;
		vis[i][j] = true;
		Min = inf; Max = -inf;
		for (int t = i;t <= i+k-1;t++) {
			Max = max(Max,tree[t].query_max(1,m,j,j+k-1,1));
			Min = min(Min,tree[t].query_min(1,m,j,j+k-1,1));
		}
		ans = min(ans,Max-Min);
	}
	return 0;
}
