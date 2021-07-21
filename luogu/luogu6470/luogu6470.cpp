/************************************************
*Author        :  lrj124
*Created Time  :  2020.10.16.17:08
*Mail          :  1584634848@qq.com
*Problem       :  luogu6470
************************************************/
#include <cstdio>
const int maxn = 1e4 + 10;
int n,cnt,a[3][maxn];
inline bool cmp(int a,int b) { return a%3 < b%3; }
int main() {
//	freopen("luogu6470.in","r",stdin);
//	freopen("luogu6470.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1,x;i <= n;i++) {
		scanf("%d",&x);
		cnt += !(x%3);
		a[x%3][++a[x%3][0]] = x;
	}
	if (2*cnt > n+1) return printf("No")*0;
	for (;a[1][0];) {
		if (a[0][0] > 1) printf("%d ",a[0][a[0][0]--]);
		printf("%d ",a[1][a[1][0]--]);
	}
	if (a[0][0] == 1) printf("%d ",a[0][a[0][0]--]);
	for (;a[2][0];) {
		printf("%d ",a[2][a[2][0]--]);
		if (a[0][0] > 0) printf("%d",a[0][a[0][0]--]);
	}
	return 0;
}
