/************************************************
*Author        :  lrj124
*Created Time  :  2020.08.17.10:55
*Mail          :  1584634848@qq.com
*Problem       :  luogu2585
************************************************/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 5e5 + 10;
int n,cnt(1),fmax[maxn][3],fmin[maxn][3],ch[maxn][2];
string str;
inline void dfs() {
	if (str[++n] == '0') return;
	if (str[n] == '1') {
		int now = cnt;
		ch[now][0] = ++cnt; dfs();
	}
	if (str[n] == '2') {
		int now = cnt;
		ch[now][0] = ++cnt; dfs();
		ch[now][1] = ++cnt; dfs();
	}
}
inline void dp(int now) {
	int lson = ch[now][0],rson = ch[now][1];
	if (lson) dp(lson);
	if (rson) dp(rson);
	
	if (!lson && !rson) {
		fmax[now][0] = 1; fmax[now][1] = fmax[now][2] = 0;
		fmin[now][0] = 1; fmin[now][1] = fmin[now][2] = 0;
	} else {
		fmax[now][0] = max(fmax[lson][1]+fmax[rson][2],fmax[lson][2]+fmax[rson][1])+1;
		fmax[now][1] = max(fmax[lson][0]+fmax[rson][2],fmax[lson][2]+fmax[rson][0]);
		fmax[now][2] = max(fmax[lson][1]+fmax[rson][0],fmax[lson][0]+fmax[rson][1]);

		fmin[now][0] = min(fmin[lson][1]+fmin[rson][2],fmin[lson][2]+fmin[rson][1])+1;
		fmin[now][1] = min(fmin[lson][0]+fmin[rson][2],fmin[lson][2]+fmin[rson][0]);
		fmin[now][2] = min(fmin[lson][1]+fmin[rson][0],fmin[lson][0]+fmin[rson][1]);
	}
}
int main() {
	freopen("luogu2585.in","r",stdin);
	freopen("luogu2585.out","w",stdout);
	cin >> str;
	str = " "+str;
	dfs(); dp(1);
	printf("%d %d",max(fmax[1][0],max(fmax[1][1],fmax[1][2])),min(fmin[1][0],min(fmin[1][1],fmin[1][2])));
	return 0;
}
