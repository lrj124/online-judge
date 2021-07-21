/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.22.11:43
*Mail          :  1584634848@qq.com
*Problem       :  luogu2278
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
int n,m,a[maxn],b[maxn],c[maxn];
struct func {
	int id,x,y;
	inline bool operator < (func cmp) const {
		return y > cmp.y;
	}
};
priority_queue<func> Q;
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) {
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		Q.push((func){i,1,a[i]+b[i]+c[i]});
	}
	for (func now;m--;Q.pop(),Q.push(now)) {
		now = Q.top(); now.x++;
		printf("%d ",now.y);
		now.y = now.x*now.x*a[now.id]+now.x*b[now.id]+c[now.id];
	}
	return 0;
}
