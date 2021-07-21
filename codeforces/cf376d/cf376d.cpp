#include <cstdio>
int n,k;
int main() {
	scanf("%d%d",&n,&k);
	printf("%d\n",k*((n-1)*6+5));
	for (int i = 1;n--;i += 6) printf("%d %d %d %d\n",k*i,k*(i+1),k*(i+2),k*(i+4));
	return 0;
}
