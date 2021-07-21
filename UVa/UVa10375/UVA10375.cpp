/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.07.19:08
*Mail          :  1584634848@qq.com
*Problem       :  UVA10375
************************************************/

//C(n,m) = prod_{i=1}^m (n-i+1)/(m-i+1)
#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main() {
    freopen("UVA10375.in","r",stdin);
    freopen("UVA10375.out","w",stdout);
    while (cin >> a >> b >> c >> d) {
		long double ans = 1.;
		for (int i = 1;i <= max(b,d);i++) {
			// u must div and mul at the same time,otherwise there's something wrong with the precision.
			long double tmp = 1.;
			if (i <= b) tmp *= 1.*(a-i+1)/(b-i+1);
			if (i <= d) tmp /= 1.*(c-i+1)/(d-i+1);
			ans *= tmp;
		}
		printf("%.5Lf\n",ans);
	}
    return 0;
}
