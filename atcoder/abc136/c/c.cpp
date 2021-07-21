/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.04.20:11
*Mail          :  1584634848@qq.com
*Problem       :  c/c
************************************************/
#include <bits/stdc++.h>
using namespace std;
int n,x,last = -999;
int main() {
	//freopen("c/c.in","r",stdin);
	//freopen("c/c.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) {
		scanf("%d",&x);
		if (x > last)  x--;
		if (x < last) {
			printf("No");
			return 0;
		}
		last = x;
	}
	printf("Yes");
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}
