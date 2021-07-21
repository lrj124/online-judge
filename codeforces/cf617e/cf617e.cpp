#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5000000 + 10;
int n,m,k,block,cnt[maxn],val[maxn];
long long tot,ans[maxn];
struct Query {
	int l,r,num;
	inline bool operator < (Query cmp) const {
		if (l/block != cmp.l/block) return l/block < cmp.l/block;
		return r/block < cmp.r/block;
	}
}q[maxn];
inline void add(int x) { tot += cnt[x^k]; cnt[x]++; }
inline void del(int x) { cnt[x]--; tot -= cnt[x^k]; }
signed main() {
	scanf("%lld%lld%lld",&n,&m,&k);
	block = sqrt(n);
	for (int i = 1;i <= n;i++) scanf("%lld",&val[i]),val[i] ^= val[i-1];
	for (int i = 1;i <= m;i++) {
		scanf("%lld%lld",&q[i].l,&q[i].r);
		q[i].l--;
		q[i].num = i;
	}
	sort(q+1,q+m+1);
	int l = 1,r = 0;
	for (int i = 1;i <= m;i++) {
		while (l > q[i].l) add(val[--l]);
		while (l < q[i].l) del(val[l++]);
		while (r < q[i].r) add(val[++r]);
		while (r > q[i].r) del(val[r--]);
		ans[q[i].num] = tot;
	}
	for (int i = 1;i <= m;i++) printf("%lld\n",ans[i]);
	return 0;
}
