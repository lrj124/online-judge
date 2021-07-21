/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.30.08:45
*Mail          :  1584634848@qq.com
*Problem       :  luogu1365
************************************************/
#include <cstdio>
const int maxn = 1000000 + 10;
double g[maxn],f[maxn];
char str[maxn];
int n,pos;
int main() {
//	freopen("luogu1365.in","r",stdin);
//	freopen("luogu1365.out","w",stdout);
	scanf("%d%s",&n,&str[1]);
	for (int i = 1;i <= n;i++) {
		if (str[i] == 'o') { g[i] = g[i-1]+1; f[i] = f[i-1]+2*g[i-1]+1; }
		if (str[i] == 'x') { g[i] = 0; f[i] = f[i-1]; }
		if (str[i] == '?') { g[i] = (g[i-1]+1)/2; f[i] = f[i-1]+g[i-1]+0.5; }
	}
	printf("%.4f",f[n]);
	return 0;
}
