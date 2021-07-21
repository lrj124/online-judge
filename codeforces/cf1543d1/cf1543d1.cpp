//2021.07.18 21:37 by lrj124.
#include <cstdio>
int t,n,k,ans;
int main() {
	for (scanf("%d",&t);t--;) {
		scanf("%d%d",&n,&k);
		printf("0\n"); fflush(stdout);
		if (scanf("%d",&ans), !ans)
			for (int i = 1;i < n;i++) {
				printf("%d\n",i^(i-1)); fflush(stdout);
				if (scanf("%d",&ans), ans) break;
			}
	}
	return 0;
}
