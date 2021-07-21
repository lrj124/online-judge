/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.24.16:27
*Mail          :  1584634848@qq.com
*Problem       :  cf446a
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
int n,a[maxn],pre[maxn],ans;
int main() {
	//freopen("cf446a.in","r",stdin);
	//freopen("cf446a.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
		pre[i] = a[i] > a[i-1] ? pre[i-1]+1 : 1;
	}
	for (int i = 1;i <= n;i++) {
		ans = max(ans,min(n,pre[i]+1));
		if (a[i-pre[i]+1] > a[i-pre[i]-1]+1 || a[i-pre[i]+2] > a[i-pre[i]]+1) ans = max(ans,pre[i]+pre[i-pre[i]]);
	}
	printf("%d",ans);
	return 0;
}
