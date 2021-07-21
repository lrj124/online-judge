/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.15.19:28
*Mail          :  1584634848@qq.com
*Problem       :  cf1174d
************************************************/
#include <cstdio>
const int maxn = 1<<18;
int n,x,ans[maxn];
bool vis[maxn];
int main() {
	freopen("cf1174d.in","r",stdin);
	freopen("cf1174d.out","w",stdout);
	scanf("%d%d",&n,&x);
	vis[0] = vis[x] = true;
	for (int i = 1;i < 1<<n;i++)
		if (!vis[i]) {
			vis[i^x] = true;
			ans[++ans[0]] = i;
		}
	printf("%d\n",ans[0]);
	for (int i = 1;i <= ans[0];i++) printf("%d ",ans[i]^(i ^ 1 ? ans[i-1] : 0));
	return 0;
}
