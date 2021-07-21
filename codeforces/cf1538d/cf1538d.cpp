//2021.07.19 11:02 by lrj124.
#include <cstdio>
int t,a,b,k;
inline int gcd(int a,int b) { return b ? gcd(b,a%b) : a; }
int main() {
	for (scanf("%d",&t);t--;) {
		scanf("%d%d%d",&a,&b,&k);
		if (a == b && k == 1) { puts("NO"); continue; }
		int g = gcd(a,b),x = a,y = b,cnt1 = 0,cnt2 = 0;
		for (int i = 2;i*i <= x;i++)
			for (;!(x%i);x /= i) cnt1++;
		if (x ^ 1) cnt1++;
		for (int i = 2;i*i <= y;i++)
			for (;!(y%i) && y ^ i;y /= i) cnt2++;
		if (y ^ 1) cnt2++;
		puts((a != g)+(b != g) <= k && k <= cnt1+cnt2 ? "YES" : "NO");
	}
	return 0;
}
