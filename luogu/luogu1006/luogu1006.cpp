#include <bits/stdc++.h>
using namespace std;
int n,m,f[51][51][51][51],a[51][51];
inline int MAX(int a,int b,int c,int d) { return max(a,max(b,max(c,d))); }
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) scanf("%d",&a[i][j]);
	for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            for (int x = 1;x <= n;x++)
                for (int y = 1;y <= m;y++)
                    f[i][j][x][y] = MAX(f[i-1][j][x-1][y],f[i][j-1][x-1][y],f[i-1][j][x][y-1],f[i][j-1][x][y-1])+a[i][j]+a[x][y]*(i != x && j != y);
    printf("%d",f[n][m][n][m]);
    return 0;
}
