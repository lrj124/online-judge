//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 8e6 + 10;
const int inf = 1e9;
int n,k,tot,ls[maxn],rs[maxn];
long long ans,sum[maxn];
struct robot {
	int x,r,q;
	inline bool operator < (robot cmp) const {
		return r > cmp.r;
	}
} p[100010];
map<int,int> rt;
inline void update(int l,int r,int num,int& root) {
	if (!root) root = ++tot;
	if (l > num || r < num) return;
	if (l == r) return void(sum[root]++);
	int mid = l+r>>1;
	update(l,mid,num,ls[root]);
	update(mid+1,r,num,rs[root]);
	sum[root] = sum[ls[root]]+sum[rs[root]];
}
inline int query(int l,int r,int ql,int qr,int root) {
	if (!root || l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) return sum[root];
	int mid = l+r>>1;
	return query(l,mid,ql,qr,ls[root])+query(mid+1,r,ql,qr,rs[root]);
}
int main() {
	freopen("cf1045g.in","r",stdin);
	freopen("cf1045g.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++) scanf("%d%d%d",&p[i].x,&p[i].r,&p[i].q);
	sort(p+1,p+n+1);
	for (int i = 1;i <= n;i++) {
		for (int j = p[i].q-k;j <= p[i].q+k;j++) ans += query(-inf,inf,p[i].x-p[i].r,p[i].x+p[i].r,rt[j]);
		update(-inf,inf,p[i].x,rt[p[i].q]);
	}
	printf("%lld",ans);
	return 0;
}
