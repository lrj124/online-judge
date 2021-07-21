/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.03.20:16
*Mail          :  1584634848@qq.com
*Problem       :  luogu1886
************************************************/
#include <cstdio>
const int maxn = 1e6 + 10;
struct que { int val,num; } q[maxn];
int n,k,a[maxn],l,r;
int main() {
	freopen("luogu1886.in","r",stdin);
	freopen("luogu1886.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	l = 1; r = 0;
	for (int i = 1;i <= n;i++) {
		for (;q[r].val >= a[i] && r >= l;r--);
		q[++r] = { a[i],i };
		for (;q[l].num <= i-k;l++);
		if (i >= k) printf("%d ",q[l].val);
	}
	puts("");
	l = 1; r = 0;
	for (int i = 1;i <= n;i++) {
		for (;q[r].val <= a[i] && r >= l;r--);
		q[++r] = { a[i],i };
		for (;q[l].num <= i-k;l++);
		if (i >= k) printf("%d ",q[l].val);
	}
	return 0;
}
