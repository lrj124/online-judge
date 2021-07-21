/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.26.08:17
*Mail          :  1584634848@qq.com
*Problem       :  luogu1169
************************************************/
#include <algorithm>
#include <cstdio>
using std :: max;
using std :: min;
const int maxn = 2000 + 10;
int n,m,a[maxn][maxn],left[maxn][maxn],right[maxn][maxn],up[maxn][maxn],ans_sq,ans;
int main() {
	freopen("luogu1169.in","r",stdin);
	freopen("luogu1169.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) {
			scanf("%d",&a[i][j]);
			up[i][j] = 1;
			left[i][j] = right[i][j] = j;
		}
	for (int i = 1;i <= n;i++)
		for (int j = 2;j <= m;j++)
			if (a[i][j] ^ a[i][j-1]) left[i][j] = left[i][j-1];
	for (int i = 1;i <= n;i++)
		for (int j = m-1;j;j--)
			if (a[i][j] ^ a[i][j+1]) right[i][j] = right[i][j+1];
	for (int i = 1;i <= n;i++)
		for (int j = 1,tmp;j <= m;j++) {
			if (i > 1 && a[i][j]^a[i-1][j]) {
				up[i][j] = up[i-1][j]+1;
				left[i][j] = max(left[i][j],left[i-1][j]);
				right[i][j] = min(right[i][j],right[i-1][j]);
			}
			tmp = right[i][j]-left[i][j]+1;
			ans = max(ans,tmp*up[i][j]);
			ans_sq = max(ans_sq,min(up[i][j],tmp)*min(up[i][j],tmp));
		}
	printf("%d\n%d",ans_sq,ans);
	return 0;
}
