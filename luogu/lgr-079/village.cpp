//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2e6 + 10;
int T,n,a[maxn];
long long m;
inline int read(){
	int x = 0,f = 1;
	char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = (x<<1)+(x<<3)+c-'0'; c = getchar(); }
	return x*f; 
}
int main() {
	freopen("village.in","r",stdin);
	freopen("village.out","w",stdout);
	for (T = read();T--;) {
		n = read(); scanf("%lld",&m);
		int Max = 0,x,y;
		for (register int i = 1;i <= n;i++) {
			a[i] = read();
			if (Max < a[i]) { Max = a[i]; x = i; }
		}
		Max = 0;
		if (n == 1) { printf("1\n"); continue; }
		for (register int i = 1,u,v;i < n;i++) {
			u = read(),v = read();
			if (v == x) u ^= v ^= u ^= v;
			if (u == x && Max < a[v]) {
				Max = a[v];
				y = v;
			}
		}
		if (a[x]-a[y] > m) printf("%d\n",x);
		else if (a[x]-a[y] == m) printf("%d\n",x > y ? y : x);
		else printf("%d\n",m-(a[x]-a[y])&1 ? (x > y ? x : y) : (x > y ? y : x));
	}
	return 0;
}
