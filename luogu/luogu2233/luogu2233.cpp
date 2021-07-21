//2021.07.15 21:01 by lrj124.
#include <cstdio>
const int maxn = 1e7 + 10;
int n,f[2][8];
int main() {
	scanf("%d",&n);
	f[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < 8;j++) f[i&1][j] = (bool(j^5)*f[i&1^1][(j+7)%8]+bool(j^3)*f[i&1^1][(j+1)%8])%1000;
	printf("%d",f[n&1][4]);
	return 0;
}
