/************************************************
*Author        :  lrj124
*Created Time  :  2020.10.20.16:32
*Mail          :  1584634848@qq.com
*Problem       :  luogu2938
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 7e5 + 10;
int s,d,m,ans,p[51][11],f[maxn];
int main() {
	freopen("luogu2938.in","r",stdin);
	freopen("luogu2938.out","w",stdout);
	scanf("%d%d%d",&s,&d,&m);
	for (int i = 1;i <= s;i++)
		for (int j = 1;j <= d;j++) scanf("%d",&p[i][j]);
	for (int i = 2;i <= d;i++) {
		int Max = 0; fill(f,f+ans+m+1,0);
		for (int j = 1;j <= s;j++)
			for (int k = p[j][i-1];k <= m+ans;k++) {
				f[k] = max(f[k],f[k-p[j][i-1]]+p[j][i]-p[j][i-1]);
				Max = max(Max,f[k]);
			}
		ans += Max;
	}
	printf("%d",m+ans);
	return 0;
}
