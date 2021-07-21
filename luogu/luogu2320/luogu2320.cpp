/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.23.11:31
*Mail          :  1584634848@qq.com
*Problem       :  luogu2320
************************************************/
#include <bits/stdc++.h>
using namespace std;
int n,a[50];
int main() {
	freopen("luogu2320.in","r",stdin);
	freopen("luogu2320.out","w",stdout);
	for (scanf("%d",&n);n;n >>= 1) a[++a[0]] = n+1>>1;
	for (printf("%d\n",a[0]);a[0];printf("%d ",a[a[0]--]));
	return 0;
}
