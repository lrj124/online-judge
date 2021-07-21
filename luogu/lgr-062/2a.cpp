/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.27.14:14
*Mail          :  1584634848@qq.com
*Problem       :  2a
************************************************/
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string,string> ans;
map<string,char> p;
int n,q;
int main() {
	//freopen("2a.in","r",stdin);
	//freopen("2a.out","w",stdout);
	for (cin >> n >> q;n--;) {
		string str;
		cin >> str >> ans[str];
	}
	for (string str;q--;) {
		cin >> str;
		for (int i = 0;i < 4;i++) {
			string a;
			cin >> a;
			p[a] = 'A'+i;
		}
		printf("%c\n",p[ans[str]]);
	}
	return 0;
}
