#include <cstring>
#include <cstdio>
const int maxn = 1e5 + 10;
int n,d[maxn];
int main() {
	for (;scanf("%d",&n), n;puts("")) {
		memset(d,0,sizeof d);
		for (int l,r,x = n;x--;d[r+1]--,d[l]++) scanf("%d%d",&l,&r);
		for (int i = 1;i <= n;i++) printf("%d ",d[i] += d[i-1]);
	}
	return 0;
}
