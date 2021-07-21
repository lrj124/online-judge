/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.09.21:03
*Mail          :  1584634848@qq.com
*Problem       :  uva1635
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n,m,m_index[maxn],factor[maxn],cnt,c_index[maxn],ans[maxn];
inline void init() {
	for (int i = 2;i*i <= m;i++)
		if (!(m%i)) {
			factor[++cnt] = i;
			for (;!(m%i);m /= i,m_index[cnt]++);
		}
	if (m > 1) {
		factor[++cnt] = m;
		m_index[cnt]++;
	}
}
inline bool check(int N,int k) {
	N = N-k+1;
	for (int i = 1;i <= cnt;i++) {
		for	(;!(N%factor[i]);N /= factor[i],c_index[i]++);
		for (;!(k%factor[i]);k /= factor[i],c_index[i]--);
	}
	for (int i = 1;i <= cnt;i++)
		if (m_index[i] > c_index[i]) return false;
	return true;
}
int main() {
	freopen("uva1635.in","r",stdin);
	freopen("uva1635.out","w",stdout);
	while (cin >> n >> m) {
		memset(m_index,0,sizeof(m_index));
		memset(c_index,0,sizeof(c_index));
		ans[0] = cnt = 0;
		init();
		for (int i = 1;i <= n-2;i++)
			if (check(n-1,i)) ans[++ans[0]] = i+1;
		printf("%d\n",ans[0]);
		for (int i = 1;i <= ans[0];i++) printf("%s%d",i ^ 1 ? " " : "",ans[i]);
		printf("\n");
	}
	return 0;
}
