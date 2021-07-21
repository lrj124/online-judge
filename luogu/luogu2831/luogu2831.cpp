//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
using namespace std;
const double eps = 1e-6;
const int maxn = 20;
int T,t,n,f[1<<maxn],nex[maxn][maxn];
long double x[maxn],y[maxn];
inline long double dabs(long double x) { return x > 0 ? x : -x; }
int main() {
// 	freopen("luogu2831.in","r",stdin);
// 	freopen("luogu2831.out","w",stdout);
	for (scanf("%d",&T),t = T;t--;) {
		scanf("%d%*d",&n);
		fill(f+1,f+(1<<maxn),999999);
		for (int i = 1;i <= n;i++) scanf("%Lf%Lf",&x[i],&y[i]);
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++) {
				long double a = (x[j]*y[i]-x[i]*y[j])/(x[i]*x[i]*x[j]-x[j]*x[j]*x[i]);
				if (a > 0 || (i ^ j && (x[i]*y[i]/x[j]-y[j]) < eps)) { nex[i][j] = -1; continue; }
				long double b = (y[i]*x[j]*x[j]-y[j]*x[i]*x[i])/(x[i]*x[j]*x[j]-x[j]*x[i]*x[i]);
				nex[i][j] = (1<<(i-1))|(1<<(j-1));
				for (int k = 1;k <= n;k++)
					if (k ^ i && k ^ j && dabs(a*x[k]*x[k]+b*x[k]-y[k]) <= eps) nex[i][j] |= 1<<(k-1);
			}
		for (int sta = 0;sta < (1<<n);sta++)
			for (int i = 1;i <= n;i++) if (!(sta>>(i-1)&1))
				for (int j = 1;j <= n;j++) if (!(sta>>(j-1)&1) && nex[i][j] ^ -1) f[sta|nex[i][j]] = min(f[sta|nex[i][j]],f[sta]+1);
		printf("%d\n",f[(1<<n)-1]);
	}
	return 0;
}
