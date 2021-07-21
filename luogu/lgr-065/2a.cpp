/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.13.14:25
*Mail          :  1584634848@qq.com
*Problem       :  2a
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
int a,b,ans,tmp;
int main() {
 	freopen("2a.in","r",stdin);
 	freopen("2a.out","w",stdout);
	for (char ch;(ch = getchar()) ^ EOF;) {
		if (ch == '1') a++;
		if (ch == '0') b++;
		if (b < a) a = b = 0;
		if (ch == '0') tmp = 1;
		ans = max(ans,b-a);
	}
	printf("%d",tmp ? ans : -1);
	return 0;
}
