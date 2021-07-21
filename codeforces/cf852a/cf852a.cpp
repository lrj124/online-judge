/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.27.21:19
*Mail          :  1584634848@qq.com
*Problem       :  cf852a
************************************************/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <ctime>
using namespace std;
string str,tmp,ans[3];
int n;
int main() {
	freopen("cf852a.in","r",stdin);
	freopen("cf852a.out","w",stdout);
	srand(time(NULL));
	cin >> n >> str;
	do {
		tmp = str;
		for (int i(0),num(0),x(0);i < 3;i++,tmp = to_string(x),x = 0) {
			ans[i] = "";
			for (size_t j(0);j < tmp.size();j++) {
				num = num*10+tmp[j]-'0';
				ans[i] += tmp[j];
				if (rand()%100 || j == tmp.size()-1) {
					x += num; num = 0;
					if (j ^ tmp.size()-1) ans[i] += '+';
				}
			}
		}
	} while (tmp.size() ^ 1);
	for (int i = 0;i < 3;i++) cout << ans[i] << endl;
	return 0;
}
