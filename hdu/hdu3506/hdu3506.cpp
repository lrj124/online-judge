/************************************************
*Author        :  lrj124
*Created Time  :  2020.09.01.21:27
*Mail          :  1584634848@qq.com
*Problem       :  hdu3506
************************************************/
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 2000 + 10;
int n,a[maxn],pre[maxn],s[maxn][maxn];
long long f[maxn][maxn];
int main() {
	freopen("hdu3506.in","r",stdin);
	freopen("hdu3506.out","w",stdout);
	for (;~scanf("%d",&n);pre[0] = 0) {
		for (int i = 1;i <= n;i++) scanf("%d",&a[i]),a[i+n] = a[i];
		memset(f,10,sizeof f);
		memset(s,0,sizeof s);
		for (int i = 1;i <= n<<1;i++) pre[i] = pre[i-1]+a[i],s[i][i] = i,f[i][i] = 0;
		for (int len = 1;len <= n;len++)
			for (int i = 1,j = i+len-1;j <= n<<1;i++,j++)
				for (int k = s[i][j-1];k <= s[i+1][j];k++) {
					if (f[i][j] > f[i][k]+f[k+1][j]+pre[j]-pre[i-1]) {
						s[i][j] = k;
						f[i][j] = f[i][k]+f[k+1][j]+pre[j]-pre[i-1];
					}
				}
		long long ans = 0x7f7f7f;
		for (int i = 1;i <= n;i++) ans = min(ans,f[i][i+n-1]);
		printf("%lld\n",ans);
	}
	return 0;
}
