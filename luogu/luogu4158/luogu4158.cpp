/************************************************
*Author        :  lrj124
*Created Time  :  2020.10.02.17:14
*Mail          :  1584634848@qq.com
*Problem       :  luogu4158
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2500 + 10;
int n,m,K,a[51][51],f[51][51][maxn][2],g[maxn];
int main() {
	freopen("luogu4158.in","r",stdin);
	freopen("luogu4158.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) scanf("%1d",&a[i][j]);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			for (int k = 1;k <= K;k++) {
				
			}
	for (int i = 1;i <= n;i++)
		for (int k = 1;k <= K;k++)
			for (int j = K;j >= k;j--) g[j] = max(g[j],g[j-k]+max(f[i][m][k][0],f[i][m][k][1]));
	printf("%d",g[K]);
	return 0;
}
