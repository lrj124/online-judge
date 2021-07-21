/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.21.14:59
*Mail          :  1584634848@qq.com
*Problem       :  luogu1198
************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200000 << 2;
const ll inf = 1 << 62;
ll maxv[maxn+10],t,d;
int m,tot;
inline void pushup(int root) { maxv[root] = max(maxv[root<<1],maxv[root<<1|1]); }
inline void update(int l,int r,int num,int root,ll x) {
	if (l > num || r < num) return;
	if (l == r) {
		maxv[root] = x;
		return;
	}
	int mid = l+r>>1;
	update(l,mid,num,root<<1,x);
	update(mid+1,r,num,root<<1|1,x);
	pushup(root);
}
inline ll query(int l,int r,int ql,int qr,int root) {
	if (r < ql || l > qr) return -inf;
	if (ql <= l && r <= qr) return maxv[root];
	int mid = l+r>>1;
	return max(query(l,mid,ql,qr,root<<1),query(mid+1,r,ql,qr,root<<1|1));
}
int main() {
	freopen("luogu1198.in","r",stdin);
	freopen("luogu1198.out","w",stdout);
	scanf("%d%lld\n",&m,&d);
	for (int i = 1;i <= m;i++) {
		char op; ll x;
		scanf("%c%lld\n",&op,&x);
		if (op == 'A') update(1,m,++tot,1,(x+t)%d);
		else printf("%lld\n",t = query(1,m,tot-x+1,tot,1));
	}
	return 0;
}
