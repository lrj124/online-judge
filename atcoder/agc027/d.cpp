#include <cstring>
#include <cstdio>
#define int long long
const int maxn = 500 + 10;
int n,num[100001],a[maxn][maxn],b[maxn][maxn];
bool notpri[100001];
inline int gcd(int x,int y) { return y ? gcd(y,x%y) : x; }
inline int lcm(int x,int y) {
	if (!x || !y) return x+y;
	return x/gcd(x,y)*y;
}
signed main() {
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	scanf("%lld",&n);
	if (n == 2) return printf("4 7\n23 10")*0;
	notpri[1] = true;
	for (int i = 2;i <= 10000;i++)
		if (!notpri[i]) {
			num[++num[0]] = i;
			for (int j = 2;i*j <= 10000;j++) notpri[i*j] = true;
		}
	int tot1 = 1,tot2 = n&1 ? 2*n : 2*n-1,cnt = 0;
	for (int j = n&1 ? n : n-1;j > 1;j -= 2) {
		cnt++;
		int x = n,y = j;
		for (;x >= 1 && y <= n;x--,y++) a[x][y] = cnt&1 ? tot1 : tot2;
		if (cnt&1) tot1++;
		else tot2--;
	}
	for (int i = n;i >= 1;i -= 2) {
		cnt++;
		int x = i,y = 1;
		for (;x >= 1 && y <= n;x--,y++) a[x][y] = cnt&1 ? tot1 : tot2;
		if (cnt&1) tot1++;
		else tot2--;
	}
	for (int j = n;j > 1;j -= 2) {
		cnt++;
		int x = 1,y = j;
		for (;x <= n && y <= n;x++,y++) b[x][y] = cnt&1 ? tot1 : tot2;
		if (cnt&1) tot1++;
		else tot2--;
	}
	for (int i = n&1 ? 1 : 2;i <= n;i += 2) {
		cnt++;
		int x = i,y = 1;
		for (;x <= n && y <= n;x++,y++) b[x][y] = cnt&1 ? tot1 : tot2;
		if (cnt&1) tot1++;
		else tot2--;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (a[i][j] && b[i][j]) a[i][j] = num[a[i][j]]*num[b[i][j]];
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (!a[i][j]) a[i][j] = lcm(a[i+1][j],lcm(a[i-1][j],lcm(a[i][j-1],a[i][j+1])))+1;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) printf("%lld%c",a[i][j],j ^ n ? ' ' : '\n');
	return 0;
}
