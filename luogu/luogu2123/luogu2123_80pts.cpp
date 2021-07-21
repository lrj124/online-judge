/************************************************
*Author        :  lrj124
*Created Time  :  2019.03.22.20:18
*Mail          :  1584634848@qq.com
*Problem       :  luogu2123
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000 + 10;
struct Node {
	int a,b;
	inline bool operator < (Node cmp) const {
		return min(a,cmp.b) < min(b,cmp.a);
	}
}p[maxn];
long long ans,pre;
int n,T;
int main() {
// 	freopen("luogu2123.in","r",stdin);
// 	freopen("luogu2123.out","w",stdout);
	for (scanf("%d",&T);T--;) {
	    ans = pre = 0;
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) scanf("%d%d",&p[i].a,&p[i].b);
		sort(p+1,p+n+1);
		for (int i = 1;i <= n;i++) {
			pre += p[i].a;
			ans = max(ans,pre)+p[i].b;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
