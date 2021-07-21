/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.30.12:25
*Mail          :  1584634848@qq.com
*Problem       :  luogu1654
************************************************/
#include <cstdio>
double x1[2],x2[2],x3[2];
int n,k;
int main() {
	freopen("luogu1654.in","r",stdin);
	freopen("luogu1654.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++,k ^= 1) {
		double x;
		scanf("%lf",&x);
		x1[k^1] = (x1[k]+1)*x;
		x2[k^1] = (x2[k]+2*x1[k]+1)*x;
		x3[k^1] = x3[k]+(3*x2[k]+3*x1[k]+1)*x;
	}
	printf("%.1lf",x3[k]);
	return 0;
}
