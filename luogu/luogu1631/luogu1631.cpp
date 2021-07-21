/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.22.11:53
*Mail          :  1584634848@qq.com
*Problem       :  luogu1631
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 * 3000 +  10;
int a[maxn],b[maxn],n,ans[maxn];
int main() {
	freopen("luogu1631.in","r",stdin);
	freopen("luogu1631.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++) scanf("%d",&b[i]);
	for (int i = 1;i <= min(n,2000);i++)
		for (int j = 1;j <= min(n,2000);j++) ans[++ans[0]] = a[i]+b[j];
	sort(ans+1,ans+ans[0]+1);
	for (int i = 1;i <= n;i++) printf("%d ",ans[i]);
	return 0;
}
