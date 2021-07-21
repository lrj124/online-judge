#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int n,k,a[maxn],sum[maxn],lmax[maxn];
signed main() {
	freopen("poj2018.in","r",stdin);
	freopen("poj2018.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i = 1;i <= n;i++) { scanf("%lld",&a[i]); a[i] *= 1000; }
	int l = 0,r = 1000000000,mid,ans;
	for (;l <= r;) {
		mid = l+r>>1;
		for (int i = 1;i <= n;i++) {
			sum[i] = sum[i-1]+a[i]-mid;
			lmax[i] = max(0ll,max(lmax[i-1]+a[i]-mid,a[i]-mid));
		}
		bool flag = false;
		for (int i = k;i <= n;i++)
			if (lmax[i-k]+sum[i]-sum[i-k] >= 0) { flag = true; break; }
		if (flag) { ans = mid; l = mid+1; } else r = mid-1;
	}
	printf("%lld",ans);
	return 0;
}
