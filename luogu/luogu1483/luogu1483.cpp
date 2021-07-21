/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.30.19:38
*Mail          :  1584634848@qq.com
*Problem       :  luogu1483
************************************************/
#include <cstdio>
using ll = long long;
const int maxn = 1000000 + 10;
int n,m,a[maxn],add[maxn];
ll ans;
int main() {
	freopen("luogu1483.in","r",stdin);
	freopen("luogu1483.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int op,x,y;m--;ans = 0) {
		scanf("%d%d",&op,&x);
		if (op == 1) {
			scanf("%d",&y);
			add[x] += y;
		} else {
			for (int i = 1;i*i <= x;i++)
				if (!(x%i)) ans += (i*i ^ x ? add[i]+add[x/i] : add[i]);
			printf("%lld\n",a[x]+ans);
		}
	}
	return 0;
}
