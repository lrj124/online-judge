//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2e6 + 10;
int n,tot,a[maxn],sum[maxn<<2],len[maxn<<2];
long long ans;
inline int ash(int x) { return lower_bound(a+1,a+a[0]+1,x)-a; }
struct line {
	int x1,x2,y,k;
	inline bool operator < (line cmp) const {
		return y < cmp.y;
	}
} l[maxn];
inline void pushup(int root,int l,int r) {
	if (sum[root]) len[root] = a[r+1]-a[l];
	else len[root] = len[root<<1]+len[root<<1|1];
}
inline void update(int l,int r,int ul,int ur,int root,int x) {
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		sum[root] += x;
		pushup(root,l,r);
		return;
	}
	int mid = l+r>>1;
	update(l,mid,ul,ur,root<<1,x);
	update(mid+1,r,ul,ur,root<<1|1,x);
	pushup(root,l,r);
}
int main() {
	freopen("luogu5490.in","r",stdin);
	freopen("luogu5490.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1,x,y,xx,yy;i <= n;i++) {
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		l[++tot] = { x,xx,y,1 };
		l[++tot] = { x,xx,yy,-1 };
		a[++a[0]] = x;
		a[++a[0]] = xx;
	}
	sort(l+1,l+tot+1);
	sort(a+1,a+a[0]+1);
	a[0] = unique(a+1,a+a[0]+1)-(a+1);
	for (int i = 1;i < tot;i++) {
		update(1,a[0],ash(l[i].x1),ash(l[i].x2)-1,1,l[i].k);
		ans += 1ll*len[1]*(l[i+1].y-l[i].y);
	}
	printf("%lld",ans);
	return 0;
}
