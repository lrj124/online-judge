#include <cstdio>
const int maxn = 1e6 + 10;
const int mod = 9901;
#define int long long
int a,b,ans(1),ind[maxn],fac[maxn];
inline int power(int x,int y) {
	int ans = 1;
	for (;y;y >>= 1,x = x*x%mod) if (y & 1) ans = ans*x%mod;
	return ans;
}
signed main() {
	freopen("luogu1593.in","r",stdin);
	freopen("luogu1593.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	if (!a) return printf("0")*0;
	for (int i = 2;i*i <= a;i++)
		if (!(a%i)) {
			fac[++fac[0]] = i;
			for (;!(a%i);a /= i) ind[fac[0]]++;
		}
	if (a ^ 1) {
		fac[++fac[0]] = a;
		ind[fac[0]] = 1;
	}
	for (int i = 1;i <= fac[0];i++)
	    if (fac[i]%mod == 1) ans = ans*(b+1)%mod;
	    else ans = ans*(power(fac[i],b*ind[i]+1)-1+mod)%mod*power(fac[i]-1,mod-2)%mod;
	printf("%lld",(ans%mod+mod)%mod);
	return 0;
}
