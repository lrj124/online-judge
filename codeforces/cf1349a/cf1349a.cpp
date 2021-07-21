//I am hunting for the golden stag.
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 99999999;
int n,a[maxn],mn[maxn],secmn[maxn],ind[maxn];
bool vis[maxn];
inline long long power(long long x,int y) {
	long long ans = 1;
	for (;y;y >>= 1,x *= x) if (y & 1) ans *= x;
	return ans;
}
int main() {
	freopen("cf1349a.in","r",stdin);
	freopen("cf1349a.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i < maxn;i++) mn[i] = secmn[i] = inf;
	for (int i = 1,x;i <= n;i++) {
		scanf("%d",&x);
		for (int j = 2;j*j <= x;j++) {
			int cnt = 0;
			for (;!(x%j);x /= j) cnt++;
			ind[j]++;
			if (mn[j] > cnt) {
				secmn[j] = mn[j];
				mn[j] = cnt;
			} else secmn[j] = min(secmn[j],cnt);
		}
		if (x > 1) {
			ind[x]++;
			if (mn[x] > 1) {
				secmn[x] = mn[x];
				mn[x] = 1;
			} else secmn[x] = min(secmn[x],1);
		}
	}
	long long ans = 1;
	for (int i = 1;i < maxn;i++) {
		if (ind[i] == n) ans *= power(i,secmn[i]);
		if (ind[i] == n-1) ans *= power(i,mn[i]);
	}
	printf("%lld",ans);
	return 0;
}
