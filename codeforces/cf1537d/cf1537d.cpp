//2021.07.19 11:49 by lrj124.
#include <cstdio>
int main() {
	int t,n;
	for (scanf("%d",&t);t--;) {
		scanf("%d",&n);
		if (n&1) { puts("Bob"); continue; }
		bool ans = true;
		for (int i = 1;i <= 15;i++)
			if (1<<(2*i-1) == n) ans = false;
		puts(ans ? "Alice" : "Bob");
	}
	return 0;
}
