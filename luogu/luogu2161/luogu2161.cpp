/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.02.21:11
*Mail          :  1584634848@qq.com
*Problem       :  luogu2161
************************************************/
#include <cstdio>
#define lowbit(x) (x & -x)
const int maxn = 200000 + 10;
int n,a,b,tree[maxn],t[maxn],ans;
inline void add(int x,int v) { for (;x <= maxn;x += lowbit(x)) tree[x] += v; }
inline int que(int x) { int ans(0); for (;x;x -= lowbit(x)) ans += tree[x]; return ans; }
int main() {
	freopen("luogu2161.in","r",stdin);
	freopen("luogu2161.out","w",stdout);
	for (scanf("%d",&n);n--;) {
		char str[10]; scanf("%s",str);
		if (str[0] == 'B') printf("%d\n",ans);
		else {
			int a,b,del(0);
			scanf("%d%d",&a,&b);
			for (int ed,l,r;ed = que(b);) {
				for (l = 0,r = b;l < r;que(l+r>>1) < ed ?  l = (l+r>>1)+1 : r = l+r>>1);
				if (t[l] >= a) {
					add(l,-1);
					del++;
				} else break;
			}
			ans -= del-1;
			add(a,1); t[a] = b;
			printf("%d\n",del);
		}
	}
	return 0;
}
