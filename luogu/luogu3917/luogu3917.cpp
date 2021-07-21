/************************************************
*Author        :  lrj124
*Created Time  :  2020.10.16.16:57
*Mail          :  1584634848@qq.com
*Problem       :  luogu3917
************************************************/
#include <cstdio>
const int maxn = 1e5 + 10;
int n,f[maxn];
long long ans;
int main() {
	freopen("luogu3917.in","r",stdin);
	freopen("luogu3917.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1,x;i <= n;i++) {
		scanf("%d",&x);
		for (int j = 0;j < 31;j++) {
			if (x&(1<<j)) f[j] = i-f[j];
			ans += 1ll*f[j]*(1<<j);
		}
	}
	printf("%lld",ans);
	return 0;
}
