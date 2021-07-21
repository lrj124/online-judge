/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.31.18:36
*Mail          :  1584634848@qq.com
*Problem       :  luogu1369
************************************************/
#include <algorithm>
#include <cstdio>
int ans,n,a[101][101];
int main() {
	freopen("luogu1369.in","r",stdin);
	freopen("luogu1369.out","w",stdout);
	scanf("%d",&n);
    for (int i = 1,x,y;i <= n;i++,a[x][y]++) scanf("%d%d",&x,&y);
	for (int i = 1;i <= 100;i++)
		for (int j = 1;j <= 100;j++) a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	for (int i = 1;i <= 100;i++)
		for (int j = 1;j <= 100;j++)
			for (int x = i+1;x <= 100;x++)
				for (int y = j+1;y <= 100;y++) ans = std::max(ans,a[x][y]-a[x][j-1]-a[i-1][y]+a[i-1][j-1]-a[x-1][y-1]+a[x-1][j]+a[i][y-1]-a[i][j]);
	printf("%d",ans);
	return 0;
}
