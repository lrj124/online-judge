#include <bits/stdc++.h>
typedef long long ll; 
inline ll solve(int n) {
	int sq = sqrt(n),cnt = 0;
	ll ans = 0;
	for (int i = 2;i <= sq && n > 1;i++)
		if (!(n%i)) {
			ll tmp = 1; cnt++;
			for(;!(n%i) && n > 1;tmp *= i,n /= i);
			ans += tmp;
		}
	if (cnt == 0 || n > 1) {
		cnt++;
		ans += n;
	}
	if (cnt == 1) ans++;
	return ans;
}
int main() {
	for (int cas = 1,n;scanf("%d",&n), n;cas++) printf("Case %d: %lld\n", cas, solve(n));
	return 0;
}
