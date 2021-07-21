/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.04.20:07
*Mail          :  1584634848@qq.com
*Problem       :  b
************************************************/
#include <bits/stdc++.h>
using namespace std;
int n,ans;
inline int cnt(int x) {
	if (x < 10) return 1;
	return cnt(x/10)+1;
}
int main() {
	//freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) ans += cnt(i)&1;
	printf("%d",ans);
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}
