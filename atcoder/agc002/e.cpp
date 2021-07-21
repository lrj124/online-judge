/************************************************
*Author        :  lrj124
*Created Time  :  2020.08.14.11:48
*Mail          :  1584634848@qq.com
*Problem       :  at1999
************************************************/
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int n,a[maxn];
int main() {
	freopen("at1999.in","r",stdin);
	freopen("at1999.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	for (int i = 1;i <= n;i++)
		if (i >= a[i+1]) {
			int cnt = 0;
			for (int j = i+1;j <= n;j++) if (a[j] == i) cnt++; else break;
			return puts((a[i]-i)&1 || cnt&1 ? "First" : "Second"),0;
		}
	return 0;
}
