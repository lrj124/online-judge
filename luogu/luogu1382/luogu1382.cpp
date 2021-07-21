//I am hunting for the golden stag.
#include <algorithm>
#include <utility>
#include <cstdio>
#define int long long
using namespace std;
const int maxn = 2e5 + 10;
int n,tot,cnt,a[maxn],sum[maxn<<3],len[maxn<<3];
pair<int,int> ans[maxn];
struct line {
	int x,y,k;
	inline bool operator < (line cmp) const {
		if (x == cmp.x)
			return k > cmp.k;
		return x < cmp.x;
	}
} p[maxn];
inline int ash(int x) { return lower_bound(a+1,a+a[0]+1,x)-a; }
inline void pushup(int root,int l,int r) {
	if (sum[root]) len[root] = a[r+1]-a[l];
	else len[root] = len[root<<1]+len[root<<1|1];
}
inline void update(int l,int r,int ul,int ur,int root,int x) {
	if (l > ur || r < ul) return;
	if (l <= ul && r <= ur) {
		sum[root] += x;
		return pushup(root,l,r);
	}
	int mid = l+r>>1;
	update(l,mid,ul,ur,root<<1,x);
	update(mid+1,r,ul,ur,root<<1|1,x);
	pushup(root,l,r);
}
signed main() {
	freopen("luogu1382.in","r",stdin);
	freopen("luogu1382.out","w",stdout);
	scanf("%lld",&n);
	a[++a[0]] = 0;
	for (int i = 1,x1,x2,y;i <= n;i++) {
		scanf("%lld%lld%lld",&y,&x1,&x2);
		a[++a[0]] = y;
		p[++tot] = (line){ x1,y,1 };
		p[++tot] = (line){ x2,y,-1 };
	}
	sort(a+1,a+a[0]+1);
	sort(p+1,p+tot+1);
	a[0] = unique(a+1,a+a[0]+1)-(a+1);
	for (int i = 1;i <= tot;i++) {
		ans[++cnt] = make_pair(p[i].x,len[1]);
		update(1,tot,ash(0),ash(p[i].y)-1,1,p[i].k);
		ans[++cnt] = make_pair(p[i].x,len[1]);
	}
	int res = 2;
	for (int i = 2;i < cnt;i++)
		if ((ans[i].first ^ ans[i-1].first || ans[i].first ^ ans[i+1].first) &&
			(ans[i].second ^ ans[i-1].second || ans[i].second ^ ans[i+1].second)) res++;
	printf("%lld\n%lld %lld\n",res,ans[1].first,ans[1].second);
	for (int i = 2;i < cnt;i++)
		if ((ans[i].first ^ ans[i-1].first || ans[i].first ^ ans[i+1].first) &&
			(ans[i].second ^ ans[i-1].second || ans[i].second ^ ans[i+1].second))
			printf("%lld %lld\n",ans[i].first,ans[i].second);
	printf("%lld %lld",ans[cnt].first,ans[cnt].second);
	return 0;
}
