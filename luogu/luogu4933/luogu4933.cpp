//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2e4 + 10;
const int mod = 998244353;
int n,a[maxn],f[maxn<<1],g[maxn<<1],mx,mn(maxn),ans;
int main() {
	freopen("luogu4933.in","r",stdin);
	freopen("luogu4933.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
		mn = min(mn,a[i]);
		mx = max(mx,a[i]);
	}
	for (int d = mn-mx;d <= mx-mn;d++) {
		for (int i = 0;i < maxn+maxn;i++) g[i] = 0;
		for (int i = 1;i <= n;i++) {
			(f[i] = g[a[i]-d+maxn]+1) %= mod;
			(g[a[i]+maxn] += f[i]) %= mod;
			(ans += f[i]) %= mod;
		}
	}
	printf("%d\n",(ans-(2*mx-2*mn)*n%mod+mod)%mod);
	return 0;
}
