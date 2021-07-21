//2021.07.11 11:37 by lrj124.
#include <algorithm>
#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 3000 + 10;
const int base1 = 131,mod1 = 998244353;
const int base2 = 133,mod2 = 19260817;
typedef pair<int,int> pii;
pii has1[maxn],has2[maxn];
vector<int> edge[maxn][2];
int t,n,fa[maxn];
inline int getedge(string str,int k) {
	memset(fa,0,sizeof fa);
	int now = 1,tot = 1;
	for (size_t i = 0;i < str.size();i++)
		if (str[i] == '0') {
			fa[++tot] = now;
			edge[tot][k].push_back(now);
			edge[now][k].push_back(tot);
			now = tot;
		} else now = fa[now];
	return tot;
}
inline pii dfs(int now,int fa,int k) {
	vector<pii> son;
	pii has(1,1);
	for (size_t i = 0;i < edge[now][k].size();i++) {
		int to = edge[now][k][i];
		if (to ^ fa) son.push_back(dfs(to,now,k));
	}
	sort(son.begin(),son.end());
	for (size_t i = 0;i < son.size();i++) {
		has.first = (1ll*has.first*base1%mod1+son[i].first)%mod1;
		has.second = (1ll*has.second*base2%mod2+son[i].second)%mod2;
	}
	return has;
}
int main() {
	for (scanf("%d%*c",&t);t--;) {
		for (int i = 1;i < maxn;i++) { edge[i][0].clear(); edge[i][1].clear(); }
		string a,b;
		cin >> a >> b;
		if ((n = getedge(a,0)) ^ getedge(b,1)) { puts("different"); continue; }
		puts(dfs(1,0,0) == dfs(1,0,1) ? "same" : "different");
	}
	return 0;
}
