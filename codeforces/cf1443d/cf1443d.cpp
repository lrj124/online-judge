//I am hunting for the golden stag.
#include <cstdio>
const int maxn = 3e4 + 10;
int t,n,pre,suf,a[maxn];
int main() {
	for (scanf("%d",&t);t--;) {
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
		pre = 1; suf = n;
		for (int i = 2;i <= n;i++) if (a[i] <= a[i-1]) pre = i; else break;
		for (int i = n-1;i;i--) if (a[i] <= a[i+1]) suf = i; else break;
//		printf("suf=%d pre=%d\n",suf,pre);
		bool flag = false;
		for (int i = 1;i < n;i++) if (i <= pre && i+1 >= suf) flag = true;
		for (int i = 2;i < n;i++)
			if (a[i-1]+a[i+1] >= a[i] && i-1 <= pre && i+1 >= suf) flag = true;
		puts(flag|(pre == n)|(suf == 1) ? "Yes" : "No");
	}
	return 0;
}
