/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.27.11:55
*Mail          :  1584634848@qq.com
*Problem       :  luogu1641
************************************************/
#include <cstdio>
const int p = 20100403;
int n,m,fac[p + 10];
inline int pow(int x,int y) {
	int ans = 1;
	for (;y;y >>= 1,x = 1ll*x*x%p) if (y&1) ans = 1ll*ans*x%p;
	return ans;
}
inline int C(int n,int m) {
	if (m > n) return 0;
	return 1ll*fac[n]*pow(fac[m],p-2)%p*pow(fac[n-m],p-2)%p;
}
inline int Lucas(int n,int m) {
	if (!m) return 1;
	return 1ll*Lucas(n/p,m/p)*C(n%p,m%p)%p;
}
int main() {
	freopen("luogu1641.in","r",stdin);
	freopen("luogu1641.out","w",stdout);
	scanf("%d%d",&n,&m);
	fac[0] = 1;
	for (int i = 1;i <= p;i++) fac[i] = 1ll*fac[i-1]*i%p;
	printf("%d",(Lucas(n+m,m)-Lucas(n+m,m-1)+p)%p);
	return 0;
}
