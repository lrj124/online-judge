/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.27.17:29
*Mail          :  1584634848@qq.com
*Problem       :  luogu2264
************************************************/
#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 100 + 10;
map<string,bool> vis,vis_2;
int n,cnt,ans;
string word[maxn],str;
int main() {
	freopen("luogu2264.in","r",stdin);
	freopen("luogu2264.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> str;
		for (size_t j = 0;j < str.size();j++) str[j] += (str[j] <= 'Z' ? 32 : 0);
		vis[str] = true;
	}
	str = "";
	getchar(); char ch = getchar();
	for (cnt = 1;ch ^ EOF;ch = getchar()) {
		if (ch == ',') {
			for (size_t j = 0;j < str.size();j++) str[j] += (str[j] <= 'Z' ? 32 : 0);
			if (!vis_2[str] && vis[str]) {
				ans++;
				vis_2[str] = true;
			}
			str = "";
			continue;
		}
		if (ch == '.') {
			for (size_t j = 0;j < str.size();j++) str[j] += (str[j] <= 'Z' ? 32 : 0);
			if (!vis_2[str] && vis[str]) {
				ans++;
				vis_2[str] = true;
			}
			str = "";
			vis_2.clear();
		} else if (ch == ' ') {
			for (size_t j = 0;j < str.size();j++) str[j] += (str[j] <= 'Z' ? 32 : 0);
			if (!vis_2[str] && vis[str]) {
				ans++;
				vis_2[str] = true;
			}
			str = "";
		} else str += ch;
	}
	printf("%d",ans);
	return 0;
}
