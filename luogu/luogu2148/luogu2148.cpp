/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.24.17:02
*Mail          :  1584634848@qq.com
*Problem       :  luogu2148
************************************************/
#include <bits/stdc++.h>
using namespace std;
int T,n,ans,cnt,a,b;
int main() {
	freopen("luogu2148.in","r",stdin);
	freopen("luogu2148.out","w",stdout);
	for (scanf("%d",&T);T--;ans = 0) {
		for (scanf("%d",&n),n >>= 1;n--;cnt = 0) {
			scanf("%d%d",&a,&b);
			for (int tmp = a-1|b-1;tmp&1;tmp >>= 1,cnt++);
			ans ^= cnt;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
