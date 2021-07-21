#include <cstdio>
int n,k;
int main() {
	scanf("%d%d",&n,&k);
	printf("%d",k+1);
	for (int i = 1;i <= n*2;i++) if (i ^ k+1) printf(" %d",i);
	return 0;
}
