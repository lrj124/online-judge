/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.18.20:33
*Mail          :  1584634848@qq.com
*Problem       :  e
************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int lately[40][200000];
string s,t;
signed main() {
	memset(lately,-1,sizeof(lately));
	cin >> s >> t;
	for (char i = 'a';i <= 'z';i++) {
		size_t pos = 0;
		for (size_t j = 0;j < s.size();j++)
			if (s[j] == i)
				for (;pos <= j;pos++) lately[1*i-'a'][pos] = j;
	}
	bool flag = true;
	size_t pos = 0;
	int cnt = 1;
	for (size_t i = 0;i < t.size();i++) {
		if (lately[1*t[i]-'a'][0] == -1) {
			flag = false;
			break;
		}
		if (lately[1*t[i]-'a'][pos] == -1 || pos >= s.size()) {
			pos = 0;
			cnt++;
		}
		pos = lately[1*t[i]-'a'][pos]+1;
	}
	if (flag == false) printf("-1");
	else printf("%lld\n",1ll*cnt*s.size()-(1ll*s.size()-pos));
	return 0;
}
