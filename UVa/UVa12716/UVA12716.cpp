/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.08.21:50
*Mail          :  1584634848@qq.com
*Problem       :  UVA12716
************************************************/
//if gcd(a,b) = a xor b, then gcd(a,b) = a xor b = a-b
#include <bits/stdc++.h>
using namespace std;
const int maxn = 30000000 + 10;
int T,n,ans[maxn];
inline void init() {
	for (int i = 1;i <= maxn;i++,ans[i] += ans[i-1])
		for (int j = i*2;j <= maxn;j += i)
			if ((i^j) == j-i) ans[j]++;
}
int main() {
    freopen("UVA12716.in","r",stdin);
    freopen("UVA12716.out","w",stdout);
    init(); scanf("%d",&T);
	for (int i = 1;i <= T;i++) {
		scanf("%d",&n);
		printf("Case %d: %d\n",i,ans[n]);
	}
    return 0;
}
