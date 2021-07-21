//2021.07.04 10:47 by lrj124.
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1000 + 10;
int n,m,ans,lef[maxn][maxn],rig[maxn][maxn],up[maxn][maxn];
char a[maxn][maxn];
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) {
			lef[i][j] = rig[i][j] = j;
			up[i][j] = 1;
			for (;scanf("%c",&a[i][j]), a[i][j] ^ 'R' && a[i][j] ^ 'F';);
		}
	for (int i = 1;i <= n;i++)
		for (int j = 2;j <= m;j++) if (a[i][j-1] == 'F' && a[i][j] == 'F') lef[i][j] = lef[i][j-1];
	for (int i = 1;i <= n;i++)
		for (int j = m-1;j >= 1;j--) if (a[i][j+1] == 'F' && a[i][j] == 'F') rig[i][j] = rig[i][j+1];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) {
			if (a[i][j] == 'F' && a[i-1][j] == 'F') {
				up[i][j] = up[i-1][j]+1;
				lef[i][j] = max(lef[i][j],lef[i-1][j]);
				rig[i][j] = min(rig[i][j],rig[i-1][j]);
			}
			if (a[i][j] == 'F') ans = max(ans,(rig[i][j]-lef[i][j]+1)*up[i][j]*3);
		}
	printf("%d",ans);
	return 0;
}
