/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.18.20:19
*Mail          :  1584634848@qq.com
*Problem       :  d
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
vector<int> edge[maxn];
int n,q,val[maxn];
inline void dfs(int now,int fa) {
	val[now] += val[fa];
	for (size_t i = 0;i < edge[now].size();i++)
		if (edge[now][i] ^ fa) dfs(edge[now][i],now);
}
int main() {
	scanf("%d%d",&n,&q);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int x,y;q--;) {
		scanf("%d%d",&x,&y);
		val[x] += y;
	}
	dfs(1,0);
	printf("%d",val[1]);
	for (int i = 2;i <= n;i++) printf(" %d",val[i]);
	return 0;
}
