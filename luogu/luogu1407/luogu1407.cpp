/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.02.19:53
*Mail          :  1584634848@qq.com
*Problem       :  luogu1407
************************************************/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <stack>
#include <map>
using namespace std;
const int maxn = 10000 + 10;
int n,m,cnt,ind,dfn[maxn],low[maxn],scc[maxn],scccnt;
string u[maxn],v[maxn];
vector<int> edge[maxn];
map<string,int> num;
bool vis[maxn];
stack<int> s;
inline void tarjan(int now) {
	vis[now] = true; s.push(now);
	dfn[now] = low[now] = ++ind;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (!dfn[to]) {
			tarjan(to);
			low[now] = min(low[now],low[to]);
		} else if (vis[to]) low[now] = min(low[now],dfn[to]);
	}
	if (dfn[now] == low[now]) {
		scc[now] = ++scccnt;
		for (;s.top() ^ now;vis[s.top()] = false,s.pop()) scc[s.top()] = scccnt;
		vis[s.top()] = false; s.pop();
	}
}
int main() {
	freopen("luogu1407.in","r",stdin);
	freopen("luogu1407.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) {
		cin >> u[i] >> v[i];
		num[u[i]] = ++cnt;
		num[v[i]] = ++cnt;
		edge[num[u[i]]].push_back(num[v[i]]);
	}
	scanf("%d",&m);
	for (int i = 1;i <= m;i++) {
		string a,b;
		cin >> a >> b;
		edge[num[b]].push_back(num[a]);
	}
	for (int i = 1;i <= 2*n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= n;i++)
		if (scc[num[u[i]]] ^ scc[num[v[i]]]) puts("Safe");
		else puts("Unsafe");
	return 0;
}
