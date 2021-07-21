/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.02.18:14
*Mail          :  1584634848@qq.com
*Problem       :  2a
************************************************/
#include <cstdio>
int n,m,k,ans,a[1001];
int main() {
	//freopen("2a.in","r",stdin);
	//freopen("2a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1,x;i <= k;i++) {
		scanf("%d",&x);
		a[x] = 1;
	}
	for (int now = 0,val = m;now < n;now += val,ans++) if (a[now]) val++;
	printf("%d",ans);
	return 0;
}
