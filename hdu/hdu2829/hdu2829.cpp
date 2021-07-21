/************************************************
*Author        :  lrj124
*Created Time  :  2020.09.01.19:31
*Mail          :  1584634848@qq.com
*Problem       :  hdu2829
************************************************/
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000 + 10;
int n,m,pre[maxn],a[maxn],s[maxn][maxn];
long long f[maxn][maxn],w[maxn][maxn];
int main() {
	freopen("hdu2829.in","r",stdin);
	freopen("hdu2829.out","w",stdout);
	for (;scanf("%d%d",&n,&m),n && m;pre[0] = 0) {
		memset(w,0,sizeof w);
		memset(s,0,sizeof s);
		for (int i = 1;i <= n;i++) scanf("%d",&a[i]),pre[i] = pre[i-1]+a[i];
		for (int l = 1;l <= n;l++)
			for (int i = 1,j = i+l-1;j <= n;i++,j++) w[i][j] = w[i][j-1]+1ll*a[j]*(pre[j-1]-pre[i-1]);
		memset(f,0x3f,sizeof f);
		for (int i = 1;i <= n;i++) f[0][i] = w[1][i];
		for (int i = 1;i <= m;i++) {
			s[i][n+1] = n;
			for (int j = n;j > i;j--)
				for (int k = s[i-1][j];k <= s[i][j+1];k++)
					if (f[i][j] > f[i-1][k]+w[k+1][j]) {
						s[i][j] = k;
						f[i][j] = f[i-1][k]+w[k+1][j];
					}
		}
		printf("%lld\n",f[m][n]);
	}
	return 0;
}
