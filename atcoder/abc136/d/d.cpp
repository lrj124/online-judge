/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.04.20:19
*Mail          :  1584634848@qq.com
*Problem       :  d
************************************************/
#include <bits/stdc++.h>
using namespace std;
int ans[100000],sum,posl;
string str;
bool w = true;
int main() {
	//freopen("d.in","r",stdin);
	//freopen("d.out","w",stdout);
	cin >> str;
	str += "R";
	for (size_t i = 1;i <= str.size();i++)
		if (w)
			if (str[i-1] == 'L') ans[i-1] += (sum+1)/2,ans[i] += sum/2,w ^= 1,sum = 1,posl = i;
			else sum++;
		else
			if (str[i-1] == 'R') ans[posl] += (sum+1)/2,ans[posl-1] += sum/2,w ^= 1,sum = 1;
			else sum++;
	for (size_t i = 1;i < str.size();i++) printf("%d ",ans[i]);
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}
