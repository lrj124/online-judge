/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.22.17:26
*Mail          :  1584634848@qq.com
*Problem       :  luogu2278
************************************************/
#include <bits/stdc++.h>
using namespace std;
struct task {
	int id,s,t,p;
	inline bool operator < (task cmp) const {
		if (p == cmp.p) return s > cmp.s;
		return p < cmp.p;
	}
};
priority_queue<task> q;
int id,s,t,p,nowtime;
int main() {
	freopen("luogu2278.in","r",stdin);
	freopen("luogu2278.out","w",stdout);
	for (;scanf("%d%d%d%d",&id,&s,&t,&p) ^ EOF;q.push((task){id,s,t,p})) {
		for (task now;nowtime < s && q.size();) {
			now = q.top(); q.pop();
			nowtime = max(nowtime,now.s);
			int tmp = min(now.t,s-nowtime);
			nowtime += tmp;
			now.t -= tmp;
			if (now.t) q.push(now);
			else printf("%d %d\n",now.id,nowtime);
		}
	}
	for (;q.size();printf("%d %d\n",q.top().id,nowtime += q.top().t),q.pop());
	return 0;
}
