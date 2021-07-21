/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.27.14:31
*Mail          :  1584634848@qq.com
*Problem       :  1a
************************************************/
#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 5e5 + 10;
priority_queue<int,vector<int>,greater<int> > q;
priority_queue<int> p;
int n,m,deg1[maxn],deg2[maxn],ans1,ans2;
vector<int> edge[maxn];
bool vis[maxn];
int main() {
	//freopen("1a.in","r",stdin);
	//freopen("1a.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1,u,v;i <= m;i++) {
		scanf("%d%d",&u,&v);
		deg1[v]++,deg2[v]++;
		edge[u].push_back(v);
	}
	for (int i = 1;i <= n;i++)
		if (!deg1[i]) q.push(i);
	for (int now,last = 0;q.size();) {
		now = q.top(); q.pop();
		if (now > last) ans1++;
		last = max(last,now);
		for (size_t i = 0;i < edge[now].size();i++)
			if (deg1[edge[now][i]]) {
				deg1[edge[now][i]]--;
				if (!deg1[edge[now][i]] && !vis[edge[now][i]]) {
					q.push(edge[now][i]);
					vis[edge[now][i]] = true;
				}
			}
	}
	memset(vis,false,sizeof(vis));
	for (int i = 1;i <= n;i++)
		if (!deg2[i]) {
			q.push(i);
			p.push(i);
		}
	for (int now,last = 0,lastnode;p.size();) {
		now = p.top(); p.pop();
		//for ()
	}
	printf("%d\n%d",ans1,ans2);
	return 0;
}
