/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.17.20:01
*Mail          :  1584634848@qq.com
*Problem       :  a
************************************************/
#include <bits/stdc++.h>
using namespace std;
string str,now,last;
int ans = 1;
int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin >> str;
	last = str[0];
	for (size_t i = 1;i < str.size();i++) {
		now += str[i];
		if (now == last) continue;
		last = now; now = "";
		ans++;
	}
	printf("%d",ans);
	return 0;
}
